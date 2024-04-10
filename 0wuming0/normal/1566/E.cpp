#include"bits/stdc++.h"
using namespace std;
vector<int>v[200005];
int vis[200005];
int ans[200005];
void dfs(int i)
{
    vis[i]=1;
    for(auto j:v[i])if(vis[j]==0)
    {
        dfs(j);
        if(ans[j]==0)ans[i]=1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            s+=ans[i];
        }
        printf("%d\n",n-2*s+ans[1]);
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            ans[i]=vis[i]=0;
        }
    }
    return 0;
}