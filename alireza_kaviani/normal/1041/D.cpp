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
         INF = 1e9,
         MOD = 1e9 + 7; // 998244353;

ll n , h , t , x = 1 , pos , ans , l[MAXN] , r[MAXN];
pll p[ll(1e7)];
vector<ll> vec;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> h;
    for(ll i = 1 ; i <= n ; i++)    cin >> l[i] >> r[i];

    for(ll i = n ; i >= 1 ; i--)
    {
        p[t++] = {x - 1 , r[i] + 1};
        p[t++] = {x , l[i]};
        for(ll j = l[i] + 50 ; j < r[i - 1] ; j += 50)
        {
            p[t++] = {x + j - l[i] , j};
        }
        x += l[i] - r[i - 1];
    }
    sort(p , p + t);

    for(ll i = 0 ; i < t ; i++)
    {
        pll val = p[upper_bound(p , p + t , Mp(p[i].X + h , INF + 10)) - p - 1];
        pos = val.Y - (p[i].X + h - val.X);
        ans = max(ans , abs(pos - p[i].Y));
    }
    cout << ans << endl;

    return 0;
}