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

ll solve(ll d[] , ll n)
{
    ll x[n] , ans = 0;
    fill(x , x + n , 0);
    for(int i = 0 ; i < n ; i++)
    {
        x[i] = (i == 0 ? d[i] : max(x[i - 1] + d[i] , d[i]));
        ans = max(ans , x[i]);
    }
    return ans;
}

int main()
{
    fast_io;

    ll n;
    cin >> n;

    ll a[n] , d[n - 1], ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(i != 0)
        {
            d[i - 1] = abs(a[i] - a[i - 1]);
        }
    }

    for(int i = 1 ; i < n - 1 ; i += 2) d[i] *= -1;
    ans = max(ans , solve(d , n - 1));
    for(int i = 0 ; i < n - 1 ; i++)    d[i] *= -1;
    ans = max(ans , solve(d , n - 1));
    cout << ans << endl;

    return 0;
}