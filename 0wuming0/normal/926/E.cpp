#include<iostream>
#include"stdio.h"
#include<algorithm>
#include"stdlib.h"
#include"string.h"
#define ll long long
using namespace std;
struct node
{
    int a;
    struct node* l;
    struct node* r;
};
typedef struct node v;
int main()
{
    int n;
    cin>>n;
    v *data,*now;
    data=(v*)malloc(sizeof(v));
    now=data;
    scanf("%d",&(now->a));
    for(int i=1;i<n;i++)
    {
        now->r=(v*)malloc(sizeof(v));
        scanf("%d",&(now->r->a));
        now=now->r;
        now->r=0;
    }
    data->l=0;
    now=data;
    while(now->r!=0)
    {//cout<<now->r->a<<endl;
        now->r->l=now;
        now=now->r;
    }
    /*
    now=data;
    int sum2=1;
    while(now->r!=0)sum2++,now=now->r;
    cout<<sum2<<endl;
    now=data;
    printf("%d",now->a);
    while(now->r!=0)
    {
        now=now->r;
        printf(" %d",now->a);
    }
    cout<<endl;
    //*/
    now=data;
    while(now->r!=0)
    {
        if(now->r->a==now->a)
        {
            now->a=(now->a)+1;
            v *save;
            save=now->r->r;
            if(save!=0)save->l=now;
            free(now->r);
            now->r=save;
            if(now->l!=0)now=now->l;
        }
        else now=now->r;
    }
    now=data;
    int sum=1;
    while(now->r!=0)sum++,now=now->r;
    cout<<sum<<endl;
    now=data;
    printf("%d ",now->a);
    while(now->r!=0)
    {
        now=now->r;
        printf("%d ",now->a);
    }
    cout<<endl;
    //
    now=data;
    while(now->r!=0)
    {
        now=now->r;
        free(now->l);
    }
    free(now);
    return 0;
}