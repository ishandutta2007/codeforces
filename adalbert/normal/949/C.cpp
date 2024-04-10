#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#define left eorgjrptgj
#define right rtyjtokh
#define time ddfkjgofidhj
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int md=1e9+7;
const int arr=2e5;

bool used[300000];
int u[300000];
int cnt;
vector<int> visited,vec[200000],rvec[200000];

void dfs(int u)
{
    used[u]=1;
    for (auto i:vec[u])
        if (!used[i])
        dfs(i);
    visited.pb(u);
}
vector<int> vis;

void dfs2(int u)
{
    used[u]=1;
    vis.pb(u);
    for (auto i:rvec[u])
        if (!used[i])
        dfs2(i);
}

signed main()
{
    int n,m,h;
    cin>>n>>m>>h;

    for (int i=1;i<=n;i++)
        cin>>u[i];

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        if ((u[a]+1)%h==u[b])
        {
            vec[a].pb(b);
            rvec[b].pb(a);
        }
        if ((u[b]+1)%h==u[a])
        {

            vec[b].pb(a);
            rvec[a].pb(b);
        }
    }

    for (int i=1;i<=n;i++)
        used[i]=0;
    for (int i=1;i<=n;i++)
        if (!used[i])
        dfs(i);

    for (int i=1;i<=n;i++)
        used[i]=0;

    vector<int> ans;
    reverse(visited.begin(),visited.end());
    for (auto i:visited)
        if (!used[i])
        {
            vis.clear();
            dfs2(i);
            bool ch=1;
            for (auto u:vis)
                for (auto j:vec[u])
                if (!used[j])
                    ch=0;
            if (ch)
            {
                if (ans.empty())
                    ans=vis; else
                    if (ans.size()>vis.size())
                    ans=vis;
            }
        }

    cout<<ans.size()<<'\n';
    for (auto i:ans)
        cout<<i<<' ';
}