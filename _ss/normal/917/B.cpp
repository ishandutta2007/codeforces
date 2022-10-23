#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e2+10;
vector<pii> G[N];
int n,m,dp[N][N][30][2];

void read()
{
    cin>>n>>m;
    for (int i=1,u,v;i<=m;i++)
    {
        char c;
        cin>>u>>v>>c;
        G[u].pb(mp(v,c-'a'+1));
    }
}

bool cmp(pii t1,pii t2) {return t1.se>t2.se;}

void dfs(int u,int v,int z)
{
    int j=0;
    for (int t=26;t;t--)
    {
        dp[u][v][t][z]=dp[u][v][t+1][z];
        if (z==0)
        {
            while (j<(int)G[u].size() && G[u][j].se>=t)
            {
                if (dp[G[u][j].fi][v][G[u][j].se][z^1]==-1) dfs(G[u][j].fi,v,z^1);
                if (dp[G[u][j].fi][v][G[u][j].se][z^1]==0) dp[u][v][t][z]=1;
                j++;
            }
        }
        else
        {
            while (j<(int)G[v].size() && G[v][j].se>=t)
            {
                if (dp[u][G[v][j].fi][G[v][j].se][z^1]==-1) dfs(u,G[v][j].fi,z^1);
                if (dp[u][G[v][j].fi][G[v][j].se][z^1]==0) dp[u][v][t][z]=1;
                j++;
            }
        }
    }
}

void process()
{
    for (int i=1;i<=n;i++) sort(all(G[i]),cmp);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int t=1;t<=26;t++)
                for (int z=0;z<=1;z++) dp[i][j][t][z]=-1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int z=0;z<=1;z++)
                if (dp[i][j][1][z]==-1) dfs(i,j,z);
            if (dp[i][j][1][0]) cout<<"A";
            else cout<<"B";
        }
        cout<<"\n";
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