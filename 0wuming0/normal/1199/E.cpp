#include"bits/stdc++.h"
using namespace std;
int vis[300005];
int ans[300005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(vis[a]==0&&vis[b]==0)
            {
                vis[a]=vis[b]=1;
                ans[nn++]=i;
            }
        }
        if(nn>=n)
        {
            printf("Matching\n");
            for(int i=0;i<n;i++)printf("%d%c",ans[i]," \n"[i==n-1]);
        }
        else
        {
            printf("IndSet\n");
            nn=0;
            for(int i=1;i<=3*n;i++)if(vis[i]==0)ans[nn++]=i;
            for(int i=0;i<n;i++)printf("%d%c",ans[i]," \n"[i==n-1]);
        }
        nn=0;
        for(int i=1;i<=3*n;i++)vis[i]=0;
    }
    return 0;
}