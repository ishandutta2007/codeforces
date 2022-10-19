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

const ll MAXN = 2e5 + 10;
ll n , k , sum = 0 , ans = 0 , h[MAXN] , r[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++) cin >> h[i];
    sort(h , h + n);

    for(ll i = MAXN - 1 ; i >= 0 ; i--)
    {
        r[MAXN - i - 1] = n - (lower_bound(h , h + n , i) - h);
    }

    for(ll i = 0 ; i < MAXN - h[0] - 1 ; i++)
    {
        if(sum + r[i] <= k)
        {
            sum += r[i];
            continue;
        }
        else
        {
            ans++;
            sum = r[i];
        }
    }
    cout << ans + (sum != 0) << endl;


    return 0;
}