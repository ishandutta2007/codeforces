#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
vector<ll> G[maxn];
ll a[maxn],n,val[maxn],sl[maxn],visit[maxn],f[maxn][5],k,tp[5];

void read()
{
    cin>>n>>k;
    int u,v;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)
        if (!visit[G[u][i]])
        {
            ll v=G[u][i];
            dfs(v);
            sl[u]+=sl[v];
            val[u]+=val[v]+sl[v];
            for (int c=0;c<k;c++) f[u][(c+1)%k]+=f[v][c];
        }
}

void dfs2(int u)
{
    visit[u]=1;
    for (int i=0;i<G[u].size();i++)

        if (!visit[G[u][i]])
        {
            ll v=G[u][i];
            val[v]+=val[u]-val[v]-sl[v]+sl[u]-sl[v];
            sl[v]+=sl[u]-sl[v];
            for (int c=0;c<k;c++) tp[(c+1)%k]=f[u][c]-f[v][(c-1+k)%k];
            for (int c=0;c<k;c++) //if (f[u][c]>f[v][(c-1+k)%k])
                f[v][(c+1)%k]+=tp[(c+1)%k];
            dfs2(v);
        }
}

void process()
{
    for (int i=1;i<=n;i++) sl[i]=1,f[i][0]=1;
    dfs(1);
    for (int i=1;i<=n;i++) visit[i]=0;
    dfs2(1);
    ll ans=0;
    /*for (int i=1;i<=n;i++)
    {
        cout<<endl;
        for (int c=1;c<k;c++) cout<<f[i][c]<<" ";
    }*/
    for (int i=1;i<=n;i++)
    {
        for (int c=1;c<k;c++)
            if (f[i][c]>0)
            val[i]-=f[i][c]*c,ans+=f[i][c];
        ans+=val[i]/k;
    }
    //for (int i=1;i<=n;i++) cout<<val[i]<<" ";
    cout<<ans/2;
    //for (int i=1;i<=n;i++) cout<<val[i]<<" ";
}
int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}