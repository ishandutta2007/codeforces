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

const ll MAXN = 1010;
ll w , h , x , y , u[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> w >> h;
    for(ll i = 0 ; i < 2 ; i++)
    {
        cin >> x >> y;
        u[y] = x;
    }

    for(ll i = h ; i >= 0 ; i--)
    {
        w += i;
        w = max(0LL , w - u[i]);
    }
    cout << w << endl;

    return 0;
}