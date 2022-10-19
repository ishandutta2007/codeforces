#include"bits/stdc++.h"
using namespace std;
int dis[1005][1005];
int save[1005],l,r;
int vis[1005];
int mp[1005][1005];
vector<int>v[1005];
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        mp[a][b]=mp[b][a]=1;
    }
    for(int bg=1;bg<=n;bg++)
    {
        for(int i=0;i<1005;i++)
        {
            vis[i]=0;
            dis[bg][i]=1e9;
        }
        vis[bg]=1;
        dis[bg][bg]=0;
        l=r=0;
        save[r++]=bg;
        while(l<r)
        {
            for(auto j:v[save[l]])if(vis[j]==0)
            {
                vis[j]=1;
                dis[bg][j]=dis[bg][save[l]]+1;
                save[r++]=j;
            }
            l++;
        }
    }
    //for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("%d%c",dis[i][j]," \n"[j==n]);
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&mp[i][j]==0)
    {
        if(dis[s][t]<=dis[s][i]+1+dis[t][j]&&dis[s][t]<=dis[s][j]+1+dis[t][i])ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}