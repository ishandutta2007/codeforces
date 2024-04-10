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

const ll MAXN = 4e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , m , q , r , c , ans , par[MAXN];

ll Find(ll v)
{
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    if(pv != pu)
    {
        par[pu] = pv;
    }
}

int main()
{
    fast_io;
    fill(par , par + MAXN , -1);

    cin >> n >> m >> q;
    for(ll i = 0 ; i < q ; i++)
    {
        cin >> r >> c;
        Union(r , c + n);
    }

    for(ll i = 1 ; i <= n + m ; i++)
    {
        if(par[i] == -1)    ans++;
    }
    cout << ans - 1 << endl;

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