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

const ll MAXN = 2e3 + 10,
         INF = 1e9,
         MOD = 1e9 + 7;

ll n , m , t , ans = 0 , sum , a[MAXN] , b[MAXN] , x[MAXN] , y[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/
    fill(x , x + MAXN , INF);
    fill(y , y + MAXN , INF);

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    for(ll i = 0 ; i < m ; i++) cin >> b[i];

    for(ll i = 0 ; i < n ; i++)
    {
        sum = 0;
        for(ll j = i ; j < n ; j++)
        {
            sum += a[j];
            x[j - i + 1] = min(x[j - i + 1] , sum);
        }
    }

    for(ll i = 0 ; i < m ; i++)
    {
        sum = 0;
        for(ll j = i ; j < m ; j++)
        {
            sum += b[j];
            y[j - i + 1] = min(y[j - i + 1] , sum);
        }
    }

    cin >> t;
    for(ll i = 0 ; i < MAXN ; i++)
    {
        for(ll j = 0 ; j < MAXN ; j++)
        {
            if(x[i] * y[j] <= t)    ans = max(ans , i * j);
        }
    }
    cout << ans << endl;

    return 0;
}