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

const ll MAXN = 3e5 + 10,
         INF = 8e18,
         MOD = 1e9 + 7;

ll n , m , sa , sb , ans , ia , ib , a[MAXN] , b[MAXN];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n;
    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    cin >> m;
    for(ll i = 0 ; i < m ; i++) cin >> b[i];

    for(ll i = 0 ; i < n + m ; i++)
    {
        if(sa <= sb && ia < n)
        {
            sa += a[ia++];
        }
        else
        {
            sb += b[ib++];
        }
        if(sa == sb)    ans++;
    }
    cout << (sa == sb ? ans : -1) << endl;

    return 0;
}