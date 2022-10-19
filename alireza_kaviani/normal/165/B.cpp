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

ll n , k;

ll check(ll x)
{
    ll sum = 0;
    while(x)
    {
        sum += x;
        x /= k;
    }
    return (sum >= n);
}

ll ans(ll l , ll r)
{
    if(l == r)  return l;
    ll mid = (l + r) / 2;
    if(check(mid))  return ans(l , mid);
    return ans(mid + 1 , r);
}

int main()
{
    fast_io;

    cin >> n >> k;
    cout << ans(0 , n);

    return 0;
}