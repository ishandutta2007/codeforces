#include<iostream>
 #include<stdio.h>
 using namespace std;
int n,t,a,b,mn=1<<30,mnn,i;
int main()
{
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        int s=max((t-a+b-1)/b*b+a,a);
        if(mn>s)
        {
            mn=s;
            mnn=i;
        }
    }
    printf("%d",mnn);
}