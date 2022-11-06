#include <stdio.h>
#include <algorithm>

int a[100];
int b[100];

int main()
{
    int p=0,q=0,n,i;
    long long m;
    scanf("%d%I64d",&n,&m);
    m--;
    for(i=1;i<=n;i++)
    {
        if(m&(1LL<<(n-i-1)))
            b[q++]=i;
        else
            a[p++]=i;
    }
    for(i=0;i<n;i++)
        if(a[i])
            printf("%d ",a[i]);
    for(i=n-1;i>=0;i--)
        if(b[i])
            printf("%d ",b[i]);

    return 0;
}