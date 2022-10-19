#include"stdio.h"
int huiwen(char *p)
{
    char *q=p,*a=p;
    while(*p)p++;p--;
    for(;q<p;p--,q++)if(*p!=*q)return 0;
    for(;*q;a++,q++)if(*q!=*a)return 1;
    return 0;
}
int main()
{
    int n=0,i;
    char a[5005];
    while(1){scanf("%c",a+n);if(a[n]==10)break;n++;}
    //while(scanf("%c",a+n)!=EOF)n++;
    a[n]=0;
    if(n<=3){printf("Impossible\n");return 0;}
    int flag=1;
    for(i=1;i<n;i++)if(a[0]!=a[i])if(n%2==0||i!=n/2)flag=0;
    if(flag){printf("Impossible\n");return 0;}
    if(n%2==0)
    {
        int f=0;
        if(huiwen(a)==1)f=1;
        else
        {
            while(n%4==0)
            {
                n/=2;
                a[n]=0;
                if(huiwen(a)==1)f=1;
            }
        }
        if(f)
        {
            printf("1\n");
            return 0;
        }
    }
    printf("2\n");
    return 0;
}