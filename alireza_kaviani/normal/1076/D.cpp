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
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 3e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , m , k , v , u , w , dist[MAXN] , mark[MAXN];
vector<pair<pll , ll>> adj[MAXN];
vector<pll> g[MAXN];
vector<ll> ans;
priority_queue<pll , vector<pll> , greater<pll>> pq;
pll par[MAXN];

void dijkstra(ll v)
{
    dist[v] = 0;
    pq.push({0 , v});

    while(!pq.empty())
    {
        v = pq.top().Y;
        pq.pop();

        if(mark[v]) continue;
        mark[v] = 1;

        for(ll i = 0 ; i < adj[v].size() ; i++)
        {
            ll u = adj[v][i].X.X , w = adj[v][i].X.Y , ind = adj[v][i].Y;
            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                par[u] = {v , ind};
                pq.push({dist[u] , u});
            }
        }
    }
}

void dfs(ll v , ll p = -1)
{
    for(pll i : g[v])
    {
        ll u = i.X , ind = i.Y;
        if(u != p)
        {
            ans.push_back(ind);
            dfs(u , v);
        }
    }
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    fill(dist , dist + MAXN , INF);

    cin >> n >> m >> k;
    for(ll i = 1 ; i <= m ; i++)
    {
        cin >> v >> u >> w;
        adj[v].push_back({{u , w} , i});
        adj[u].push_back({{v , w} , i});
    }
    dijkstra(1);

    for(ll i = 2 ; i <= n ; i++)
    {
        g[i].push_back(par[i]);
        g[par[i].X].push_back({i , par[i].Y});
    }
    dfs(1);

    cout << min(k , (ll)ans.size()) << endl;
    for(ll i = 0 ; i < min(k , (ll)ans.size()) ; i++)   cout << ans[i] << sep;

    return 0;
}