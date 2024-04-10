#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
int a[maxn],n,visit[maxn],f[maxn],ans=0;
vector<int> G[maxn];

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int u,v;
    for (int i=1;i<=n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u)
{
    visit[u]=1;
    int g,max1=0,max2=0;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]])
        {
            int v=G[u][i];
            dfs(v);
            g=f[v]+(a[u]!=a[v]);
            /*if (g>max1)
            {
                max2=max1;
                max1=g;
            }
            else if (g>max2) max2=g;*/
            max2=max(max2,min(g,max1));
            max1=max(max1,g);
        }
    ans=max(ans,max1+max2);
    f[u]=max1;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    dfs(1);
    cout<<(ans+1)/2;
    return 0;
}