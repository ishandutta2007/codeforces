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

ll get(ll n , ll x , ll y , ll d)
{
    if(y != 1 && y != n && x % d != y % d)  return 8e18;
    return (abs(x - y) + d - 1) / d;
}

ll t , n , x , y , d , ans;

int main()
{
    fast_io;  /** if you sure yuor code is true but get TLE use scanf and printf*/

    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> d;
        ans = get(n , x , y , d);
        ans = min(ans , get(n , x , 1 , d) + get(n , 1 , y , d));
        ans = min(ans , get(n , x , n , d) + get(n , n , y , d));
        cout << (ans == ll(8e18) ? -1 : ans) << endl;
    }

    return 0;
}