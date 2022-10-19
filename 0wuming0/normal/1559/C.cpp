#include"bits/stdc++.h"
using namespace std;
int a[10005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        if(a[n]==0)for(int i=1;i<=n+1;i++)printf("%d%c",i," \n"[i==n+1]);
        else if(a[1]==1)
        {
            printf("%d ",n+1);
            for(int i=1;i<=n;i++)printf("%d%c",i," \n"[i==n]);
        }
        else
        {
            for(int k=1;k<n;k++)if(a[k]==0&&a[k+1]==1)
            {
                for(int i=1;i<=k;i++)printf("%d ",i);
                printf("%d ",n+1);
                for(int i=k+1;i<=n;i++)printf("%d%c",i," \n"[i==n]);
                break;
            }
        }
    }
    return 0;
}