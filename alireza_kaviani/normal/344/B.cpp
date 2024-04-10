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

ll ans[3] , a[3];

int main()
{
    fast_io;

    cin >> a[0] >> a[1] >> a[2];
    ans[0] = (a[0] + a[1] + a[2]) / 2 - a[2];
    ans[1] = (a[0] + a[1] + a[2]) / 2 - a[0];
    ans[2] = (a[0] + a[1] + a[2]) / 2 - a[1];

    if(min({ans[0] , ans[1] , ans[2]}) < 0 || (ans[0] + ans[1] + ans[2]) * 2 != (a[0] + a[1] + a[2])) return cout << "Impossible" << endl , 0;
    cout << ans[0] << ends << ans[1] << ends << ans[2] << endl;

    return 0;
}