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
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const int MAXN = 1e5 + 10;
vector<ll> adj[MAXN];
ll n , m , ans = 0 , c[MAXN] , mark[MAXN];

ll dfs(ll v)
{
    mark[v] = 1;
    ll res = 8e18;
    for(int u : adj[v])
    {
        if(!mark[u])    res = min(res , dfs(u));
    }
    return min(res , c[v]);
}

int main()
{
    fast_io;

    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)   cin >> c[i];
    for(int i = 0 ; i < m ; i++)
    {
         ll x , y;
         cin >> x >> y;
         adj[x].push_back(y);
         adj[y].push_back(x);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!mark[i])
        {
            ans += dfs(i);
        }
    }
    cout << ans << endl;

    return 0;
}