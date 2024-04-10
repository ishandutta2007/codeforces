#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(),vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N=71,M=(1<<17),inf=2e9;
int n,m,a,b;
vi G_in[N],G_out[N];

void add_edge(vi G[],int u,int v)
{
    G[u].eb(v);
    G[v].eb(u);
}

void read()
{
    cin>>n>>m>>a>>b;
    for (int i=1,u,v,c;i<=m;i++)
    {
        cin>>u>>v>>c;
        if (c==a) add_edge(G_in,u,v);
        else add_edge(G_out,u,v);
    }
}

int belong[N],id[N],cnt=0,sl=0,sz[N],d[N][M];

void dfs(int u,int r)
{
    belong[u]=r;
    sz[r]++;
    for (int v : G_in[u])
        if (!belong[v]) dfs(v,r);
}


void process()
{
    for (int i=1;i<=n;i++)
        if (!belong[i])
        {
            dfs(i,++cnt);
            if (sz[cnt]>=4) id[cnt]=++sl;
        }
    for (int i=1;i<=n;i++)
        for (int j=0;j<(1<<sl);j++) d[i][j]=inf;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> q;
    if (id[belong[1]]) d[1][1<<(id[belong[1]]-1)]=0,q.push(mp(0,mp(1,1<<(id[belong[1]]-1))));
    else d[1][0]=0,q.push(mp(0,mp(1,0)));
    while (!q.empty())
    {
        int u=q.top().se.fi,mask=q.top().se.se,w=q.top().fi;
        q.pop();
        for (int v : G_in[u])
            if (w+a<d[v][mask]) d[v][mask]=w+a,q.push(mp(w+a,mp(v,mask)));
        for (int v : G_out[u])
            if (belong[v]!=belong[u])
            {
                int nmask=mask,t=id[belong[v]];
                if (t)
                {
                    if ((mask>>(t-1))&1) continue;
                    nmask |= 1<<(t-1);
                }
                if (w+b<d[v][nmask]) d[v][nmask]=w+b,q.push(mp(w+b,mp(v,nmask)));
            }
        while (!q.empty() && d[q.top().se.fi][q.top().se.se]<q.top().fi) q.pop();
    }
    for (int i=1;i<=n;i++)
    {
        int res=inf;
        for (int j=0;j<(1<<sl);j++) res=min(res,d[i][j]);
        cout<<res<<" ";
    }
}
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    read();
    process();
    return 0;
}