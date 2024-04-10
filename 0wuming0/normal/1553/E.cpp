#include"bits/stdc++.h"
using namespace std;
int a[600005];
int sum[300005];
int ans[300005];
int vis[300005];
int nn;
int n,m;
void solve(int k)
{
    int *p=a+k;
    int s=0;
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        s++;
        vis[i]=1;
        int now=p[i];
        while(vis[now]==0)
        {
            vis[now]=1;
            now=p[now];
        }
    }
    if(n-s<=m)ans[nn++]=k;
    for(int i=0;i<=n;i++)vis[i]=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum[(i-a[i]+n)%n]++;
            a[i+n]=a[i];
        }
        for(int i=0;i<n;i++)if(sum[i]>=n/4-10)
        {
            solve(i);
        }
        printf("%d",nn);
        for(int i=0;i<nn;i++)printf(" %d",ans[i]);
        printf("\n");
        for(int i=0;i<=n;i++)
        {
            sum[i]=0;
        }
        nn=0;
    }
    return 0;
}