#include"stdio.h"
int a[300005],b[300005],n,i;
int jurge(int t1,int t2,int num)
{
    for(i=num;i<n;i++)
    {
        if(a[i]!=t1&&b[i]!=t1&&a[i]!=t2&&b[i]!=t2)return i;
    }
    return 0;
}
int main()
{
    int flag,num;
    scanf("%*d%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",a+i,b+i);
    }
    num=flag=jurge(a[0],0,1);
    if(!flag){printf("YES\n");return 0;}
    flag=jurge(a[0],a[num],num+1);
    if(!flag){printf("YES\n");return 0;}
    flag=jurge(a[0],b[num],num+1);
    if(!flag){printf("YES\n");return 0;}
    num=flag=jurge(b[0],0,1);
    if(!flag){printf("YES\n");return 0;}
    flag=jurge(b[0],a[num],num+1);
    if(!flag){printf("YES\n");return 0;}
    flag=jurge(b[0],b[num],num+1);
    if(!flag){printf("YES\n");return 0;}
    printf("NO\n");
    return 0;
}