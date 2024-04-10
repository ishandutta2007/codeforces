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

const ll MAXN = 1e5 + 10 , INF = 8e18;
ll n , k , ans = -8e18 , a[MAXN] , l[MAXN] , r[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    for(int i = 1 ; i <= n ; i++)   cin >> a[i];

    if(k >= 3)
    {
        for(int i = 1 ; i <= n ; i++)   ans = max(ans , a[i]);
        return cout << ans << endl , 0;
    }
    if(k == 1)
    {
        ans = 8e18;
        for(int i = 1 ; i <= n ; i++)   ans = min(ans , a[i]);
        return cout << ans << endl , 0;
    }

    l[0] = r[n + 1] = INF;
    for(int i = 1 ; i <= n ; i++)   l[i] = min(l[i - 1] , a[i]);
    for(int i = n ; i >= 0 ; i--)   r[i] = min(r[i + 1] , a[i]);
    for(int i = 2 ; i <= n ; i++)
    {
        ans = max(ans , max(l[i - 1] , r[i]));
    }
    cout << ans << endl;

    return 0;
}