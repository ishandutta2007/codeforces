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
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
inline int input(){int n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 , INF = 8e18;
ll minxl[MAXN] , minxr[MAXN] , maxxl[MAXN] , maxxr[MAXN] , minyl[MAXN] , minyr[MAXN] , maxyl[MAXN] , maxyr[MAXN];

int main()
{
    fast_io;

    ll n;
    cin >> n;

    ll p[n + 1][4];
    for(int i = 1 ; i <= n ; i++)    cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];

    minxl[0] = minyl[0] = minxr[n + 1] = minyr[n + 1] = INF;
    maxxl[0] = maxyl[0] = maxxr[n + 1] = maxyr[n + 1] = -INF;
    for(int i = 1 ; i <= n ; i++)
    {
        maxxl[i] = max(maxxl[i - 1] , p[i][0]);
        maxyl[i] = max(maxyl[i - 1] , p[i][1]);
        minxl[i] = min(minxl[i - 1] , p[i][2]);
        minyl[i] = min(minyl[i - 1] , p[i][3]);
    }
    for(int i = n ; i >= 1 ; i--)
    {
        maxxr[i] = max(maxxr[i + 1] , p[i][0]);
        maxyr[i] = max(maxyr[i + 1] , p[i][1]);
        minxr[i] = min(minxr[i + 1] , p[i][2]);
        minyr[i] = min(minyr[i + 1] , p[i][3]);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        ll xl , yl , xr , yr;
        xl = max(maxxl[i - 1] , maxxr[i + 1]);
        yl = max(maxyl[i - 1] , maxyr[i + 1]);
        xr = min(minxl[i - 1] , minxr[i + 1]);
        yr = min(minyl[i - 1] , minyr[i + 1]);
        if(xl <= xr && yl <= yr)    return cout << xl << ends << yl << endl , 0;
    }

    return 0;
}