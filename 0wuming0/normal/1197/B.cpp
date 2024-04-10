#include"stdio.h"
#define ll long long
int main()
{
    int a[200005],n,i,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n-1;i++)
    {
        if(a[i]==n)flag=1;
        if(flag)
        {
            if(a[i]<a[i+1])
            {
                printf("NO\n");
                return 0;
            }
        }
        else
        {
            if(a[i]>a[i+1])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}