#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=2e5+10;
vector<int> G[N];
int n,m,k,a[N],visit[N],d1[N],d2[N];

void read()
{
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void bfs(int x,int d[])
{
    queue<int> q;
    q.push(x);
    for (int i=1;i<=n;i++) visit[i]=0;
    d[x]=0;
    visit[x]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int v : G[u])
            if (!visit[v])
            {
                d[v]=d[u]+1;
                visit[v]=1;
                q.push(v);
            }
    }
}

bool cmp(int x,int y) { return d1[x]>d1[y]; }

void process()
{
    bfs(1,d1);
    bfs(n,d2);
    sort(a+1,a+k+1,cmp);
    int best=d2[a[1]],res=0;
    for (int i=2;i<=k;i++)
    {
        res=max(res,d1[a[i]]+best+1);
        best=max(best,d2[a[i]]);
    }
    cout<<min(res,d1[n]);
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