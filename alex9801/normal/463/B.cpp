#include <stdio.h>

int main()
{
    int mx=0,a,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        mx=a>mx?a:mx;
    }
    printf("%d",mx);
    return 0;
}