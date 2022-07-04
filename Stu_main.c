// 主函数系统
// 实现的功能



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct fraction
{
    int chinese;
    int math;
    int english;
}Stu_Fraction;



typedef struct Student
{
    char name[20];
    char ID[20];
    char sex[10];
    int age;
    int class;
    int grade;
    Stu_Fraction Frac;
    int S_count;
    struct Student *next;
}StudentNode,*Student;


// 显示菜单
void printMenu(){

    printf("--------------------学生管理系统--------------------\n");
    printf("-----------------------1.录入-----------------------\n");
    printf("-----------------------2.删除-----------------------\n");
    printf("-----------------------3.查找-----------------------\n");
    printf("-----------------------4.修改-----------------------\n");
    printf("-----------------------5.排序-----------------------\n");
    printf("-----------------------6.显示-----------------------\n");
    printf("-----------------------7.人数-----------------------\n");
    printf("-----------------------8.退出-----------------------\n");
    printf("----------------------------------------------------\n");

}





// 录入信息
int add_data(Student S){

    int Stu_count = 0;
    printf("录入信息人数:\n");
    scanf("%d", &Stu_count);
    
    // 创建一个指针始终指向学生链表的最后一个节点
    StudentNode *head = (StudentNode *)malloc(sizeof(StudentNode));
    head = S;
    while(head->next!=NULL)
        head = head->next;

    while(Stu_count>0){
        // 创建一个学生节点
        Student One = (StudentNode *)malloc(sizeof(StudentNode));

        // 输入单个学生信息
        printf("请输入当前学生的姓名:\n");
        scanf("%s",One->name);
        printf("请输入当前学生的学号:\n");
        scanf("%s",One->ID);
        printf("请输入当前学生的性别:\n");
        scanf("%s",One->sex);
        printf("请输入当前学生的年龄:\n");
        scanf("%d",&One->age);
        printf("请输入当前学生的年级:\n");
        scanf("%d",&One->grade);
        printf("请输入当前学生的班级:\n");
        scanf("%d",&One->class);
        printf("请输入当前学生的成绩(语文 数学 英语(以空格隔开)):\n");
        scanf("%d %d %d",&One->Frac.chinese,&One->Frac.math,&One->Frac.english);

        // 将该学生的信息插入到链表中
        head->next = One;
        head = One;
        Stu_count--;
    }
    head->next = NULL;

    if(Stu_count==0){
        S->S_count+=1;
        printf("录入成功!\n");
    }else{
        printf("录入失败!");
    }

}


// 显示信息
void printStu(Student S){
    // 创建一个节点用于遍历链表
    StudentNode *head = (StudentNode *)malloc(sizeof(StudentNode));
    head = S->next;
    printf(" %-5s       %3s      %3s   %3s   %s   %3s   %5s %5s %5s\n","NAME","ID","SEX","AGE","GRADE","CLASS","CHINESE","MATH","ENGLISH");
    while (head!=NULL)
    {
        
        printf("%-5s   %-5s  %3s   %3d    %3d     %3d   %5d    %5d %4d\n",head->name,head->ID,head->sex,head->age,head->grade,head->class,head->Frac.chinese,head->Frac.math,head->Frac.english);
        head = head->next;
    }
    
    
    
}

// 根据ID删除学生信息

bool delete(Student S,char ID[]){
    // 创建一个指针进行查找操作，另一个指针始终指向查找结点的上一个位置
    StudentNode * before = (StudentNode *)malloc(sizeof(StudentNode));
    before = S;
    StudentNode * search = (StudentNode *)malloc(sizeof(StudentNode));
    search = before->next;
    
    while (search!=NULL)
    {
        if(!strcmp(ID,search->ID)){
            // 删除学生信息
            // 如果是最后一个
            if(search->next==NULL){
                before->next = NULL;
                free(search);
            }else{
                // 不是最后一个
                before->next = search->next;
                free(search);
            }
            S->S_count--;
            break;
        }else{
            before = search;
            search = search->next;
        }
    }
    return true;
}

// 根据ID查找信息
bool search(Student S,char ID[]){

    // 创建一个指针进行遍历学生链表
    StudentNode *s = (StudentNode *)malloc(sizeof(StudentNode));
    if(S==NULL){
        return false;
    }
    s = S->next;
    while(s!=NULL){
        if(!strcmp(ID,s->ID)){
            // 符合条件，显示信息
            printf(" %-5s       %3s      %3s   %3s   %s   %3s   %5s %5s %5s\n","NAME","ID","SEX","AGE","GRADE","CLASS","CHINESE","MATH","ENGLISH");
            printf("%-5s   %-5s  %3s   %3d    %3d     %3d   %5d    %5d %4d\n", s->name, s->ID, s->sex, s->age, s->grade, s->class, s->Frac.chinese, s->Frac.math, s->Frac.english);
            break;
        }
        s = s->next;
    }

    return true;
}

// 根据ID修改学生信息


// 根据成绩进行排序

// 显示系统中的学生人数
int count(Student S){
    return S->S_count;
}
//退出
void Exit(){
    exit(0);
}

int main(int argc ,char *argv[]){

    

    


    // 创建一个学生链表
        Student S= (Student)malloc(sizeof(StudentNode));
        S->next = NULL;         //带头结点
        S->S_count = 0;         //当前人数为0

        while (1)
        {
            printMenu();
            printf("请输入操作代码：");
            int choose;
            scanf("%d", &choose);
            switch (choose)
            {
            case 1:
                // 录入学生信息
                add_data(S);
                break;
            case 2:
                // 根据学号删除学生信息
                char DEL_ID[20];
                printf("请输入需要删除学生的学号：");
                scanf("%s", DEL_ID);
                delete (S, DEL_ID);
                break;

            case 3:
                // 根据学号查找学生信息
                char S_ID[20];
                printf("请输入需要查找学生的学号：");
                scanf("%s", &S_ID);
                search(S, S_ID);
                break;

            case 6:
                // 显示学生的信息
                printStu(S);
                break;
            case 7:
                // 显示当前系统中的人数
                int s = count(S);
                printf("当前系统中的人数为:%d\n",s);
                break;

            case 8:
                // 退出系统
                Exit();

            default:
                printMenu();
                break;
            }
        }
    

    // // 创建一个学生链表
    // Student S= (Student)malloc(sizeof(StudentNode));
    // S->next = NULL;         //带头结点

    // add_data(S);
    // printStu(S);
    // delete (S, "1704241014");
    // printStu(S);
    // if(search(S, "1704241014"))
    //     printf("YES!\n");
    // else
    //     printf("No!\n");
    // search(S, "1704241014");


    // return 0;
}