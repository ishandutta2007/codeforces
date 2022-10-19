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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 1e5 + 10;
vector<pair<ll , pll>> edge;
vector<pll> adj[MAXN];
ll n , m , k , v , u , w , ans , sp[MAXN] , x[MAXN] , mark[MAXN] , p[MAXN];

ll Find(ll v)
{
    return (p[v] == -1 ? v : p[v] = Find(p[v]));
}
void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    p[pu] = pv;
}

void MST()
{
    Sort(edge);
    for(ll i = 0 ; i < edge.size() ; i++)
    {
        ll v = edge[i].Y.X , u = edge[i].Y.Y , w = edge[i].X;
        if(Find(v) != Find(u))
        {
            Union(v , u);
            adj[v].push_back({u , w});
            adj[u].push_back({v , w});
        }
    }
}

void dfs(ll v , ll mx = 0)
{
    if(sp[v])   ans = max(ans , mx);
    mark[v] = 1;
    for(pll i : adj[v])
    {
        ll u = i.X , w = i.Y;
        if(!mark[u])
        {
            dfs(u , max(mx , w));
        }
    }
}

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/
    fill(p , p + MAXN , -1);

    cin >> n >> m >> k;
    for(ll i = 0 ; i < k ; i++)
    {
        cin >> x[i];
        sp[x[i]] = 1;
    }

    for(ll i = 0 ; i < m ; i++)
    {
        cin >> v >> u >> w;
        edge.push_back({w , {v , u}});
    }

    MST();
    dfs(x[0]);
    for(ll i = 0 ; i < k ; i++) cout << ans << sep;

    return 0;
}