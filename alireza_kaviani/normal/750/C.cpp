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
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

const ll MAXN = 2e5 + 10 , INF = 1e9;
ll n , ans , r[MAXN] , d[MAXN];

bool check(ll x)
{
    for(ll i = 0 ; i < n ; i++)
    {
        if(x >= 1900 && d[i] == 2)  return 0;
        x += r[i];
    }
    return 1;
}

ll BS(ll l , ll r)
{
    if(l == r)  return l;
    ll mid = (l + r >> 1) + 1;
    if(check(mid))  return BS(mid , r);
    return BS(l , mid - 1);
}

bool ok()
{
    for(ll i = 0 ; i < n ; i++)
    {
        if(ans >= 1900 && d[i] == 2 || ans < 1900 && d[i] == 1) return 0;
        ans += r[i];
    }
    return 1;
}

int main()
{
    fast_io;

    cin >> n;

    for(ll i = 0 ; i < n ; i++) cin >> r[i] >> d[i];
    ans = BS(-INF , INF);
    if(ok())  (ans >= INF / 10 ? cout << "Infinity" : cout << ans << endl);
    else    cout << "Impossible" << endl;

    return 0;
}