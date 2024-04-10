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
vector<int> G[N],GC[N];
int n,val[N],visit[N];

void read()
{
    cin>>n;
    for (int i=1,x;i<=n;i++)
    {
        cin>>x;
        if (x)
        {
            G[x].pb(i);
            G[i].pb(x);
        }
    }
}

void dfs(int u,int p)
{
    for (int v : G[u])
        if (v!=p)
        {
            dfs(v,u);
            if (val[v]&1) GC[v].pb(u);
            else GC[u].pb(v),val[u]--;
        }
}

void dfs2(int u)
{
    visit[u]=1;
    for (int v : GC[u])
        if (!visit[v]) dfs2(v);
    cout<<u<<"\n";
}

void process()
{
    int root=1;
    for (int i=1;i<=n;i++)
    {
        if (G[i].size()!=1) root=i;
        val[i]=G[i].size();
    }
    dfs(root,0);
    if (val[root]&1)
    {
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;i++)
        if (!visit[i]) dfs2(i);
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