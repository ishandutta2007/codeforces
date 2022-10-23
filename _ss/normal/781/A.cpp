#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=2e5+10,mod=1e9+7,inf=1e18;
vector<int> G[N];
int n,root,color[N],p[N];

void dfs(int u)
{
    int t=1;
    for (int v : G[u])
        if (v!=p[u])
        {
            while (t==color[u] || t==color[p[u]]) t++;
            color[v]=t++;
            p[v]=u;
            dfs(v);
        }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1,x,y;i<n;i++)
    {
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    root=1;
    for (int i=2;i<=n;i++)
        if (G[i].size()>G[root].size()) root=i;
    int k=G[root].size()+1;
    color[root]=1;
    dfs(root);
    cout<<k<<"\n";
    for (int i=1;i<=n;i++) cout<<color[i]<<" ";
    return 0;
}