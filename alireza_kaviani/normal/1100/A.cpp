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
         MOD = 1e9 + 7;

ll n , k , a , b , ans , p[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> p[i];
        if(p[i] == 1)   a++;
        else            b++;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        ll x = 0 , y = 0;
        for(ll j = -1000 ; j < 1000 ; j ++)
        {
            ll ind = j * k + i;
            if(ind >= n || ind < 0) continue;
            if(p[ind] == 1) x++;
            else            y++;
        }
        ans = max(ans , abs((a - x) - (b - y)));
    }
    cout << ans << endl;

    return 0;
}