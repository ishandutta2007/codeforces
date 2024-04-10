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

    ll n , a[2] , ans = 1e18;
    cin >> n >> a[0] >> a[1];

    ll c[n];
    for(ll i = 0 ; i < n ; i++)    cin >> c[i];

    for(ll i = 0 ; i < (1LL << n) ; i++)
    {
        ll x[n] , res = 0;
        for(ll j = 0 ; j < n ; j++) x[j] = ((1LL << j) & i ? 1 : 0);
        for(ll j = 0 ; j < n ; j++)
        {
            if(c[j] == 2)   continue;
            if(x[j] != c[j])   res = 8e18;
        }
        for(ll j = 0 ; j < n ; j++)
        {
            if(x[j] != x[n - j - 1])    res = 8e18;
        }
        for(ll j = 0 ; j < n ; j++)
        {
            if(c[j] == 2)   res += a[x[j]];
        }
        ans = min(ans , res);
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;

    return 0;
}