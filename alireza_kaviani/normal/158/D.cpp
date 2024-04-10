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

    ll n;
    cin >> n;

    ll t[n] , ans = -1e18;
    for(int i = 0 ; i < n ; i++)    cin >> t[i];

    for(int i = 1 ; i <= n ; i++)
    {
        if(n % i == 0 && n / i >= 3)
        {
            for(int j = 0 ; j < i ; j++)
            {
                ll sum = 0;
                for(int k = j ; k < n ; k += i)
                {
                    sum += t[k];
                }
                ans = max(ans , sum);
            }
        }
    }
    cout << ans << endl;

    return 0;
}