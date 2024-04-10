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

const ll MAXN = 3e5 + 10 , MOD = 998244353;
vector<ll> V , adj[MAXN];
vector<pll> E , edge[MAXN];
ll t , n , m , v , u , ans = 1 , mark[MAXN] , col[MAXN];

void dfs(ll v , ll c = 1)
{
    V.push_back(v);
    col[v] = c;
    mark[v] = 1;
    for(ll u : adj[v])
    {
        E.push_back({v , u});
        if(!mark[u])
        {
            dfs(u , 3 - c);
        }
    }
}

void check()
{
    ll cnt = 0 , fact = 1;
    for(ll i = 0 ; i < E.size() ; i++)
    {
        ll v = E[i].X , u = E[i].Y;
        if((col[v] + col[u]) % 2 == 0)  fact = 0;
    }
    for(ll i : V)
    {
        if(col[i] % 2 == 1) cnt++;
    }
    ans = (ans * (pw(2 , cnt , MOD) + pw(2 , V.size() - cnt , MOD)) % MOD * fact);
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> t;
    for(ll i = 0 ; i < t ; i++)
    {
        cin >> n >> m;
        for(ll j = 0 ; j < m ; j++)
        {
            cin >> v >> u;
            adj[v].push_back(u);
            adj[u].push_back(v);
            edge[i].push_back({v , u});
        }

        for(ll i = 1 ; i <= n ; i++)
        {
            if(!mark[i])
            {
                dfs(i);
                check();
                V = {};
                E = {};
            }
        }
        cout << ans << endl;

        ans = 1;
        for(ll i = 0 ; i <= n ; i++)
        {
            adj[i] = {};
            mark[i] = 0;
            col[i] = 0;
        }
    }

    return 0;
}