#include<bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define left eorgjrptgjs
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const int base=3;
const ll INF=1e18;
const int md=1e9+9;
const int arr=1e5+10;

vector<int> reb[3*arr];
vector<int> vec[3*arr];
bool use[3*arr];

void dfs(int u)
{
    use[u]=1;

    for (auto to:reb[u])
        if (!use[to])
        dfs(to);
}

signed main()
{
    int n,m,q;
    cin>>n>>m>>q;

    while (q--)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
    }

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (vec[i].empty())
            ans++;
        for (int j=0;j+1<vec[i].size();j++)
        {
            reb[vec[i][j]].pb(vec[i][j+1]);
            reb[vec[i][j+1]].pb(vec[i][j]);
        }
    }

    for (int i=1;i<=m;i++)
        if (!use[i])
    {
        ans++;
        dfs(i);
    }

    cout<<ans-1;
}