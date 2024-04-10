#include <cstdio>

using namespace std;

int main()
{
    int i,j,sum=0,n,q,x;
    //cin>>n;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&x);
            if(i==j)
                sum^=x;
        }

    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d",&x);
        if(x==3)
            printf("%d",sum);
        else
        {
            sum^=1;
            scanf("%d",&x);
        }
    }
    printf("\n");

    return 0;
}