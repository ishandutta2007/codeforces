#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef long double ld;
const int arr=5e5+100;
const int md=1e9+7;
const int base=1e9+7;
///magic
/*
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
///

vector<pair<int,int> > vec[arr];
int use[arr],used[arr],go[arr];
vector<int> visited;
vector<int> cycl;
bool iscycl=0;

int mp[600][600];

void dfs(int u)
{
    visited.pb(u);
    use[u]=1;
    used[u]=1;

    for (auto i:vec[u])
    {
        if (used[i.sec] && cycl.empty())
        {
            int last=visited.size()-1;
            while (visited[last]!=i.sec)
            {
                cycl.pb(mp[visited[last-1]][visited[last]]);
                last--;
            }
            cycl.pb(i.fir);
        }
        if (!use[i.sec])
            dfs(i.sec);
    }

    visited.pop_back();
    used[u]=0;
}

void dfs2(int u)
{
    visited.pb(u);
    use[u]=1;
    used[u]=1;

    for (auto i:vec[u])
    if (!go[i.fir])
    {
        if (used[i.sec])
        {
            iscycl=1;
        }
        if (!use[i.sec])
            dfs2(i.sec);
    }

    visited.pop_back();
    used[u]=0;
}

signed main()
{
    int n,m;
    cin>>n>>m;

    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        mp[u][v]=i;
        vec[u].pb({i,v});
    }

    for (int i=1;i<=n;i++)
        if (!use[i])
        dfs(i);

    if (cycl.empty())
    {
        cout<<"YES";
        return(0);
    }


    for (auto i:cycl)
    {
        go[i]=1;
        iscycl=0;

        for (int i=1;i<=n;i++)
        {
            use[i]=0;
            used[i]=0;
        }
        for (int i=1;i<=n;i++)
            if (!use[i])
            dfs2(i);
        if (!iscycl)
        {
            cout<<"YES";
            return(0);
        }
        go[i]=0;
    }

    cout<<"NO";
}
/*
5
1 2 3 4 5
5
1 1
2 2
3 3
4 4
5 5
*/