#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=2e5+1;
vector<int> G[maxn],ans;
int n,a[maxn],st[maxn],visit[maxn],h[maxn];
queue<int> q;

void read()
{
    cin>>n;
    int u,v;
    for (int i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
}

bool cmp(int t1,int t2)
{
    return h[t1]<h[t2];
}

void bfs()
{
    q.push(1);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        visit[u]=1;
        ans.pb(u);
        for (int i=0;i<G[u].size();i++)
            if (!visit[G[u][i]]) q.push(G[u][i]);
    }
}

bool process()
{
    for (int i=1;i<=n;i++) h[a[i]]=i;
    for (int i=1;i<=n;i++) sort(G[i].begin(),G[i].end(),cmp);
    bfs();
    for (int i=0;i<ans.size();i++)
        if (ans[i]!=a[i+1]) return false;
    return true;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    if (process()) cout<<"Yes"; else cout<<"No";
    return 0;
}