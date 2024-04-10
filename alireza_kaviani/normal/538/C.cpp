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

const ll MAXN = 1e5 + 10;
ll n , m , ans , d[MAXN] , h[MAXN];

int main()
{
    fast_io;

    cin >> n >> m;
    for(ll i = 1 ; i <= m ; i++) cin >> d[i] >> h[i];
    d[0] = 1;
    h[0] = h[1] + d[1] - d[0];
    for(ll i = 1 ; i <= m ; i++)
    {
        if(abs(h[i] - h[i - 1]) > d[i] - d[i - 1])  return cout << "IMPOSSIBLE" << endl , 0;
        ll x = ((d[i] - d[i - 1]) - (h[i] - h[i - 1])) / 2;
        ans = max(ans , h[i] + x);
    }
    cout << max(ans , h[m] + n - d[m]) << endl;

    return 0;
}