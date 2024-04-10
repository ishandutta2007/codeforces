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
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;

vector<int> G[maxn];
int n,m,visit[maxn],mv;

void read()
{
    cin>>n>>m;
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int u=q.front();
        visit[u]=1;
        mv=max(u,mv);
        for (int v : G[u])
            if (!visit[v]) q.push(v);
        while (!q.empty() && visit[q.front()]) q.pop();
    }
}

void process()
{
    mv=0;
    int res=0;
    for (int i=1;i<=n;i++)
        if (!visit[i])
        {
            if (i<mv) res++;
            bfs(i);
        }
    cout<<res;
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