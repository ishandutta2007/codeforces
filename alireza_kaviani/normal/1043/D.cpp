#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e5 + 10 , MAXM = 11;
ll n , m , ans , sz = 0 , mark[MAXN] , p[MAXN][MAXM] , ind[MAXN][MAXM];
vector<ll> adj[MAXN];

void dfs(ll v)
{
    sz++;
    mark[v] = 1;
    for(ll u : adj[v])
    {
        if(!mark[u])
        {
            dfs(u);
        }
    }
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            cin >> p[j][i];
            ind[p[j][i]][i] = j;
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        ll t = 1;
        for(ll j = 0 ; j < m ; j++)
        {
            ll x = ind[i][j] , y = ind[i][0];
            if(p[x + 1][j] == 0 || p[y + 1][0] == 0 ||p[x + 1][j] != p[y + 1][0])  t = 0;
        }
        if(t)
        {
            adj[i].push_back(p[ind[i][0] + 1][0]);
            adj[p[ind[i][0] + 1][0]].push_back(i);
        }
    }

    for(ll i = 1 ; i <= n ; i++)
    {
        if(!mark[i])
        {
            sz = 0;
            dfs(i);
            ans += sz * (sz + 1) / 2;
        }
    }
    cout << ans << endl;

    return 0;
}