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

    ll n , h , k , sum = 0 , ans = 0;
    cin >> n >> h >> k;

    ll a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    for(int i = 0 ; i < n ; i++)
    {
        if(sum + a[i] > h){
            ll x = sum - (h - a[i]);
            x = x / k * k + (x % k == 0 ? 0 : k);
            ans += x / k;
            sum = max(0LL , sum - x);
        }
        sum += a[i];
    }
    cout << ans + sum / k + (sum % k == 0 ? 0 : 1) << endl;

    return 0;
}