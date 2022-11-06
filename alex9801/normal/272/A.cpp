#include <stdio.h>

int main()
{
    int a,s=0,r=0,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        s+=a;
    }
    for(i=1;i<=5;i++)
        if((s+i)%(n+1)!=1)
            r++;
    printf("%d",r);
    return 0;
}