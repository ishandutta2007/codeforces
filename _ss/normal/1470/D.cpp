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
const int N=3e5+10;
int n,m;
vi G[N];
void read()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) G[i].clear();
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[u].eb(v);
        G[v].eb(u);
    }
}

vi ans;
int vis[N],d[N],mark[N];

bool check()
{
    for (int i=1;i<=n;i++) mark[i]=vis[i]=d[i]=0;
    ans.clear();
    vis[1]=d[1]=1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        if (d[u])
        {
            if (mark[u])
            {
                d[u]=0;
                q.push(u);
                continue;
            }
            ans.eb(u);
            for (int v : G[u]) mark[v]=1;
        }
        for (int v : G[u])
            if (!vis[v])
            {
                vis[v]=1;
                d[v]=d[u]^1;
                q.push(v);
            }
    }
    for (int i=1;i<=n;i++)
        if (!vis[i]) return false;
    return true;
}

void process()
{
    if (check())
    {
        cout<<"YES\n"<<ans.size()<<"\n";
        for (int x : ans) cout<<x<<" ";
        cout<<"\n";
        return;
    }
    cout<<"NO\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}