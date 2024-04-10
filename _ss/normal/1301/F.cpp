#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e3+10;
int a[N][N],n,m,k,dis[50][N][N],visit[N][N],visit_c[N];
vector<pii> vt[50];
pii dir[4]={mp(0,1),mp(0,-1),mp(1,0),mp(-1,0)};

void read()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
}

void bfs(int x)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) visit[i][j]=0;
    for (int i=1;i<=k;i++) visit_c[i]=0;
    queue<pii> q;
    for (pii p : vt[x]) visit[p.fi][p.se]=1,q.push(p);
    visit_c[x]=1;
    while (!q.empty())
    {
        int u=q.front().fi,v=q.front().se,w=a[u][v];
        q.pop();
        for (int i=0;i<4;i++)
        {
            int r=u+dir[i].fi;
            int c=v+dir[i].se;
            if (a[r][c] && !visit[r][c])
            {
                visit[r][c]=1;
                dis[x][r][c]=dis[x][u][v]+1;
                q.push(mp(r,c));
            }
        }
        if (!visit_c[w])
        {
            visit_c[w]=1;
            for (pii p : vt[w])
                if (!visit[p.fi][p.se])
                {
                    visit[p.fi][p.se]=1;
                    dis[x][p.fi][p.se]=dis[x][u][v]+1;
                    q.push(p);
                }
        }
    }
}

void process()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) vt[a[i][j]].pb(mp(i,j));
    for (int i=1;i<=k;i++) bfs(i);
    int q;
    cin>>q;
    for (int i=1,x,y,u,v;i<=q;i++)
    {
        cin>>x>>y>>u>>v;
        int res=abs(x-u)+abs(y-v);
        for (int j=1;j<=k;j++) res=min(res,dis[j][x][y]+dis[j][u][v]+1);
        cout<<res<<"\n";
    }
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read();
    process();
    return 0;
}