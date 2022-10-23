#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
vector<int> G[N];
int a[N],n,m,root=0,visit[N],cnt[N];

void read()
{
    cin>>n>>m;
    for (int i=1,u,v;i<=m;i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]) root=i;
    }
}

vector<int> ans;

void dfs(int u)
{
    visit[u]=1;
    ans.pb(u);
    cnt[u]^=1;
    for (int v : G[u])
        if (!visit[v])
        {
            dfs(v);
            ans.pb(u);
            cnt[u]^=1;
            if (cnt[v]!=a[v])
            {
                ans.pb(v);
                ans.pb(u);
                cnt[u]^=1;
            }
        }
}

void process()
{
    if (root==0)
    {
        cout<<0;
        return;
    }
    dfs(root);
    if (cnt[root]!=a[root])
    {
        ans.pb(G[root].back());
        ans.pb(root);
        ans.pb(G[root].back());
    }
    for (int i=1;i<=n;i++)
        if (a[i] && !visit[i])
        {
            cout<<-1;
            return;
        }
    cout<<ans.size()<<"\n";
    for (int x : ans) cout<<x<<" ";
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