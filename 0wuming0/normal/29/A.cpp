#include"stdio.h"
int main()
{
    int a[100005]={0};
    int i,n,m,j;
    int x,d;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&d);
        a[x+50000]=d;
        if(a[x+50000+d]!=0)
        {
            if(a[x+50000+d]+x+50000+d==x+50000)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}