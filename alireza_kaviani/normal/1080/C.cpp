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

ll q , w , w2 , b , b2 , b3 , sz[2] , x[3][2] , y[3][2];

ll black(ll x1 , ll y1 , ll x2 , ll y2)
{
    if(x1 > x2 || y1 > y2)  return 0;
    ll size = (x2 - x1 + 1) * (y2 - y1 + 1);
    return (size / 2 + (x1 % 2 != y1 % 2) * (size % 2));
}

ll white(ll x1 , ll y1 , ll x2 , ll y2)
{
    if(x1 > x2 || y1 > y2)  return 0;
    ll size = (x2 - x1 + 1) * (y2 - y1 + 1);
    return (size / 2 + (x1 % 2 == y1 % 2) * (size % 2));
}

void solve()
{
    cin >> sz[0] >> sz[1];
    cin >> x[0][0] >> y[0][0] >> x[0][1] >> y[0][1];
    cin >> x[1][0] >> y[1][0] >> x[1][1] >> y[1][1];
    x[2][0] = max(x[0][0] , x[1][0]);
    y[2][0] = max(y[0][0] , y[1][0]);
    x[2][1] = min(x[0][1] , x[1][1]);
    y[2][1] = min(y[0][1] , y[1][1]);

    w = white(1 , 1 , sz[0] , sz[1]);
    b = black(1 , 1 , sz[0] , sz[1]);
    w2 = black(x[0][0] , y[0][0] , x[0][1] , y[0][1]);
    b2 = white(x[1][0] , y[1][0] , x[1][1] , y[1][1]);
    b3 = black(x[2][0] , y[2][0] , x[2][1] , y[2][1]);

    w += w2 - b2 - b3;
    b += b2 + b3 - w2;
    cout << w << sep << b << endl;
}

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> q;
    while(q--)
    {
        solve();
    }

    return 0;
}