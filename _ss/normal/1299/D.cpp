#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,mb=32,mod=1e9+7;

struct edge {int v,w,id;};
vector<edge> G[N];
int sl=1,val[N],n,m,mark[N],check,nex[410][410],can[N],a[N],e[N],dp[2][410],visit[N][40],on[N],loc[N];
map<int,int> id;
vector<int> single;
vector<pii> cop;

void read()
{
    cin>>n>>m;
    for (int i=1,u,v,w;i<=m;i++)
    {
        cin>>u>>v>>w;
        G[u].pb({v,w,i});
        G[v].pb({u,w,i});
    }
}

void dfs_bit(int u)
{
    val[sl]=u;
    id[u]=sl++;
    for (int i=1;i<mb;i++)
    if (((u>>i)&1)^1)
    {
        int v=(1<<i);
        for (int j=1;j<mb;j++)
            if ((u>>j)&1) v|=(1<<(i^j));
        v|=u;
        if (!id[v]) dfs_bit(v);
    }
}

void change(int &cnt,int i)
{
    if (on[i]) cnt--,on[i]=0;
    else cnt++,on[i]=1;
}

void dfs_layer(int u,int d,int cnt)
{
    for (edge x : G[u])
        if (!mark[x.v])
        {
            change(cnt,x.id);
            int v=x.v,w=x.w^d;
            if (visit[v][w])
            {
                if (visit[v][w]!=cnt) check=0;
            }
            else
            {

                visit[v][w]=cnt;
                if (cnt) dfs_layer(v,w,cnt);
            }
            change(cnt,x.id);
        }
}

void build()
{
    id[0]=0;
    id[1]=-1;
    for (int i=1;i<mb;i++) dfs_bit(1<<i);
    for (int i=0;i<sl;i++)
        for (int j=i+1;j<sl;j++)
            if ((val[i] & val[j])==0)
            {
                int t=val[i] | val[j];
                for (int u=1;u<32;u++)
                    if ((val[i]>>u)&1)
                        for (int v=1;v<32;v++)
                            if ((val[j]>>v)&1) t|=1<<(u^v);
                nex[i][j]=nex[j][i]=id[t];
            }
}

void process()
{
    mark[1]=1;
    for (edge x : G[1]) mark[x.v]=1,loc[x.v]=1;
    for (edge x : G[1])
    {
        int v=x.v;
        mark[v]=0;
        check=1;
        dfs_layer(v,0,0);
        if (check)
        {
            can[v]=1;
            for (int i=1;i<mb;i++)
                if (visit[v][i]) a[v] |= (1<<i);
            e[v]=x.w;
        }
        mark[v]=1;
    }
    for (int u=2;u<=n;u++)
        if (can[u])
        {
            int flag=1;
            for (edge x : G[u])
            {
                int v=x.v;
                if (loc[v]) flag=0;
                if (v>u && can[v])
                {
                    int v1=id[a[u]],v2=id[a[v]];
                    if (!nex[v1][v2] && v1!=0) continue;
                    cop.pb(mp(nex[v1][v2],id[1<<(e[u] ^ e[v] ^ x.w)]));
                }
            }
            if (flag) single.pb(id[a[u]]);
        }
    dp[0][0]=1;
    for (int x : single)
    {
        for (int i=0;i<sl;i++) dp[1][i]=dp[0][i];
        for (int i=0;i<sl;i++)
            if (nex[i][x] || x==0) dp[1][nex[i][x]]=(dp[1][nex[i][x]]+dp[0][i])%mod;
        for (int i=0;i<sl;i++) dp[0][i]=dp[1][i];
    }
    for (pii x : cop)
    {
        for (int i=0;i<sl;i++) dp[1][i]=dp[0][i];
        for (int i=0;i<sl;i++)
        {
            int u=x.fi,v=x.se;
            if (nex[i][u] || u==0) dp[1][nex[i][u]]=(dp[1][nex[i][u]]+dp[0][i]*2%mod)%mod;
            if (v==-1) continue;
            v=nex[u][v];
            if (!v) continue;
            if (nex[i][v]) dp[1][nex[i][v]]=(dp[1][nex[i][v]]+dp[0][i])%mod;
        }
        for (int i=0;i<sl;i++) dp[0][i]=dp[1][i];
    }
    int ans=0;
    for (int i=0;i<sl;i++) ans=(ans+dp[0][i])%mod;
    cout<<ans;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    build();
    process();
    return 0;
}