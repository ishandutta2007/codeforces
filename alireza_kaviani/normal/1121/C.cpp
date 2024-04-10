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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

ll n , k , m , ans , par[MAXN] , p[MAXN] , q[MAXN] , mark[MAXN] , running[MAXN];

ll Find(ll v)
{
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(ll v , ll u)
{
    ll pv = Find(v) , pu = Find(u);
    if(pv != pu)    par[min(pu , pv)] = max(pu , pv);
}

int main()
{
    fast_io;
    fill(par , par + MAXN , -1);

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    while(1)
    {
        ll t = 0;

        ll x = ll(100.0 * double(m) / double(n) + 0.5);
        for(ll i = 0 ; i < n && t < k ; i = Find(i + 1))
        {
            if(p[i] != q[i])
            {
                q[i]++;
                t++;
                if(q[i] == x && !mark[i])
                {
                    mark[i] = 1;
                    ans++;
                }
                if(p[i] == q[i])
                {
                    m++;
                    running[i] = 0;
                }
            }
            if(p[i] == q[i])    Union(i , i + 1);
        }

        if(t == 0)  break;

    }
    cout << ans << endl;

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