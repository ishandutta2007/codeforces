#include <stdio.h>

int main()
{
    int a,b,n,s,mx=-1,i;
    scanf("%d%d",&n,&s);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a<s||a==s&&b==0)
        {
            if(b==0)
                mx=0>mx?0:mx;
            else
                mx=100-b>mx?100-b:mx;
        }
    }
    printf("%d",mx);
    return 0;
}