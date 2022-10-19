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

const ll MAXN = 1e6 + 10;
ll n , x[MAXN] , y[MAXN] , a[MAXN] , b[MAXN];
map<pll , ll> cnt;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> x[i] >> y[i];
    for(ll i = 0 ; i < n ; i++) cin >> a[i] >> b[i];

    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            ll nx = x[i] + a[j] , ny = y[i] + b[j];
            cnt[{nx , ny}]++;
            if(cnt[{nx , ny}] == n)
            {
                return cout << nx << sep << ny << endl , 0;
            }
        }
    }

    return 0;
}