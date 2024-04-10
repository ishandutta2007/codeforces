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

int main()
{
    fast_io;

    ll n , ans = 0;
    cin >> n;

    vector<ll> a(n * 2);
    for(int i = 0 ; i < n * 2 ; i++)    cin >> a[i];
    sort(all(a));

    ans = (a[n - 1] - a[0]) * (a[n * 2 - 1] - a[n]) ;
    for(int i = 1 ; i < n ; i++)
    {
        ans = min(ans , (a[n * 2 - 1] - a[0]) * (a[i + n - 1] - a[i]));
    }
    cout << ans << endl;

    return 0;
}