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

ll t;
double ang;

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> t;
    while(t--)
    {
        ll res = -1;
        cin >> ang;
        for(ll i = 3 ; i <= 1000 ; i++)
        {
            for(ll j = 1 ; j <= i - 2 ; j++)
            {
                double deg = 180.0 / i * j;
                if(deg == ang && res == -1)
                {
                    res = i;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}