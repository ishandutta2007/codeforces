#include"bits/stdc++.h"
using namespace std;
#define ll long long
struct eg
{
    int u;
    int v;
    int w;
}g[200005];
bool cmp(eg x,eg y)
{
    return x.w<y.w;
}
vector<pair<int,int> >v[200005];
map<int,int>mp;
ll dis[405][405];
int vn;
int vis[200005];
ll ans[200005];
int nn;
void dfs(int i)
{
    vis[i]=1;
    for(auto pr:v[i])
    {
        int j=pr.first;
        if(mp.find(j)==mp.end())
        {
            mp[j]=vn;
            for(int k=0;k<=vn;k++)dis[vn][k]=dis[k][vn]=100000000000000000ll;
            dis[vn][vn]=0;
            vn++;
        }
        dis[mp[i]][mp[j]]=dis[mp[j]][mp[i]]=pr.second;
        if(vis[j]==0)
        {
            dfs(j);
        }
    }
}
void solve()
{
    for(int k=0;k<vn;k++)for(int i=0;i<vn;i++)for(int j=0;j<vn;j++)
    {
        dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    for(int i=0;i<vn;i++)for(int j=i+1;j<vn;j++)
    {
        if(dis[i][j]!=100000000000000000ll)ans[nn++]=dis[i][j];
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
        if(g[i].u>g[i].v)swap(g[i].u,g[i].v);
    }
    sort(g,g+m,cmp);
    m=min(k,m);
    for(int i=0;i<min(k,m);i++)
    {
        v[g[i].v].push_back(make_pair(g[i].u,g[i].w));
        v[g[i].u].push_back(make_pair(g[i].v,g[i].w));
    }
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        mp[i]=vn++;
        dfs(i);
        mp.clear();
        solve();
        vn=0;
    }
    sort(ans,ans+nn);
    cout<<ans[k-1]<<endl;
    return 0;
}