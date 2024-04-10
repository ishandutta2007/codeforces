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

const ll MAXN = 2e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7; // 998244353;

ll n , m , k , l , r , mid , p[MAXN];

ll check(ll i)
{
    ll sum = 0 , ind = 0;
    for( ; i < n ; i++)
    {
        if(sum + p[i] > k)
        {
            sum = 0;
            ind++;
            if(ind == m)    break;
        }
        sum += p[i];
    }
    return i == n;
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> m >> k;
    for(ll i = 0 ; i < n ; i++) cin >> p[i];

    l = -1 , r = n - 1;
    while(r - l > 1)
    {
        ll mid = (l + r) / 2;
        if(check(mid))  r = mid;
        else            l = mid;
    }
    cout << n - r << endl;

    return 0;
}