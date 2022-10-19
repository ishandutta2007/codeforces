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
#define tab                         '\t'
#define sep                         ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e5 + 10;
vector<ll> ans , adj[MAXN];
ll n , rev , v[MAXN] , u[MAXN] , mark[MAXN];

void dfs(ll v)
{
    ans.push_back(v);
    mark[v] = 1;
    for(ll u : adj[v])
    {
        if(!mark[u])    dfs(u);
    }
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> v[i] >> u[i];
        adj[v[i]].push_back(u[i]);
        adj[u[i]].push_back(v[i]);
    }
    dfs(1);

    for(ll i = 0 ; i < n ; i++)
    {
        ll a = ans[i] , x = ans[(i + 1) % n] , y = ans[(i + 2) % n];
        if(!((x == v[a] && y == u[a]) || (y == v[a] && x == u[a])))
        {
            rev = 1;
        }
    }

    if(rev) reverse(all(ans));
    for(ll i : ans) cout << i << sep;

    return 0;
}