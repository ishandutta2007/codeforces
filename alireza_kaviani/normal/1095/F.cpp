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
vector<pair<ll , pll>> E;
ll n , m , v , u , w , ans , p[MAXN] , a[MAXN] , ind[MAXN];

ll cmp(ll x , ll y)
{
    return a[x] < a[y];
}

ll Find(ll v)
{
    return (p[v] == -1 ? v : p[v] = Find(p[v]));
}

void Union(ll v , ll u , ll w)
{
    ll pv = Find(v) , pu = Find(u);
    if(pv != pu)
    {
        p[pu] = pv;
        ans += w;
    }
}

void KMST()
{
    Sort(E);
    for(ll i = 0 ; i < E.size() ; i++)
    {
        ll v = E[i].Y.X , u = E[i].Y.Y , w = E[i].X;
        Union(v , u , w);
    }
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    fill(p , p + MAXN , -1);

    cin >> n >> m;

    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        ind[i] = i;
    }
    sort(ind + 1 , ind + n + 1 , cmp);

    for(ll i = 0 ; i < m ; i++)
    {
        cin >> v >> u >> w;
        E.push_back({w , {v , u}});
    }
    for(ll i = 2 ; i <= n ; i++)
    {
        E.push_back({a[ind[i]] + a[ind[1]] , {ind[1] , ind[i]}});
    }
    KMST();
    cout << ans << endl;

    return 0;
}