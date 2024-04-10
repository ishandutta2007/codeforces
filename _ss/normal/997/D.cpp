#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=4e3+10,mod=998244353,inf=1e18;
int n,k,p[N];
ll f[N][40],g[N][40],res1[40],tmp[N][40],res[40],ifact[N],fact[N],inverse[N];
vector<int> G[N];

void read()
{
    for (int i=1;i<=n;i++) G[i].clear();
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++) f[i][j]=g[i][j]=0;
    for (int i=0;i<=k;i++) res[i]=0;
    for (int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void dfs(int u)
{
    for (int v : G[u])
        if (v!=p[u])
        {
            p[v]=u;
            dfs(v);
            for (int i=0;i<=k;i++) f[u][i]=(f[u][i]+g[v][i])%mod;
        }
    g[u][0]=1;
    for (int i=1;i<=k;i++)
        for (int j=1;j<=i;j++) g[u][i]=(g[u][i]+f[u][j-1]*g[u][i-j])%mod;
}

void dfs2(int u)
{
    for (int i=0;i<=k;i++) res[i]=(res[i]+g[u][i])%mod;
    for (int v : G[u])
        if (v!=p[u])
        {
            for (int i=0;i<=k;i++) tmp[u][i]=f[u][i];
            for (int i=0;i<=k;i++) f[u][i]=(f[u][i]-g[v][i]+mod)%mod;
            for (int i=1;i<=k;i++)
            {
                g[u][i]=0;
                for (int j=1;j<=i;j++) g[u][i]=(g[u][i]+f[u][j-1]*g[u][i-j])%mod;
            }
            for (int i=0;i<=k;i++) f[v][i]=(f[v][i]+g[u][i])%mod;
            for (int i=1;i<=k;i++)
            {
                g[v][i]=0;
                for (int j=1;j<=i;j++) g[v][i]=(g[v][i]+f[v][j-1]*g[v][i-j])%mod;
            }
            dfs2(v);
            for (int i=0;i<=k;i++) f[u][i]=tmp[u][i];
        }
}

void solve()
{
    dfs(1);
    dfs2(1);
}

void build()
{
    inverse[1]=ifact[0]=ifact[1]=fact[0]=fact[1]=1;
    for (int i=2;i<=k*2;i++)
    {
        inverse[i]=mod-mod/i*inverse[mod%i]%mod;
        ifact[i]=ifact[i-1]*inverse[i]%mod;
        fact[i]=fact[i-1]*i%mod;
    }
}

ll C(int t,int h) {return fact[h]*ifact[t]%mod*ifact[h-t]%mod; }

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n1,n2;
    cin>>n1>>n2>>k;
    if (k&1)
    {
        cout<<0;
        return 0;
    }
    n=n1;
    k/=2;
    read();
    solve();
    for (int i=0;i<=k;i++) res1[i]=res[i];
    n=n2;
    read();
    solve();
    build();
    ll ans=0;
    for (int i=0;i<=k;i++) ans=(ans+res1[i]*res[k-i]%mod*C(2*i,2*k))%mod;
    cout<<ans;
    return 0;
}