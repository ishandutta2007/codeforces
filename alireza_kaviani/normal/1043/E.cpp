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

const ll MAXN = 3e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , m , v , u , x[MAXN] , y[MAXN] , ans[MAXN] , psl[MAXN] , psr[MAXN];
pair<ll , pair<ll , pll>> p[MAXN];

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 1 ; i <= n ; i++)
    {
        cin >> x[i] >> y[i];
        p[i] = {y[i] - x[i] , {i , {x[i] , y[i]}}};
    }
    sort(p + 1 , p + n + 1);
    for(ll i = n ; i >= 1 ; i--)    psl[i] = psl[i + 1] + p[i].Y.Y.X;
    for(ll i = 1 ; i <= n ; i++)    psr[i] = psr[i - 1] + p[i].Y.Y.Y;

    for(ll i = 1 ; i <= n ; i++)
    {
        ans[p[i].Y.X] = psl[i + 1] + (n - i) * p[i].Y.Y.Y + psr[i - 1] + (i - 1) * p[i].Y.Y.X;
    }

    for(ll i = 1 ; i <= m ; i++)
    {
        cin >> v >> u;
        ans[v] -= min(x[v] + y[u] , x[u] + y[v]);
        ans[u] -= min(x[v] + y[u] , x[u] + y[v]);
    }

    for(ll i = 1 ; i <= n ; i++)    cout << ans[i] << sep;

    return 0;
}
/*
todo :
    1- set constants
    2- check TimeLimit and MemoryLimit
    3- check special test cases
    4- don't forget BS can help you that is good idea(use for loop for floats)
    5- don't forget printf and scanf can help you in your code speed
*/