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

const ll MAXN = 1e6 + 10;
ll n , k , ans[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;
    if(n < k || (k == 1 && n != 1)) return cout << -1 << endl , 0;

    for(ll i = n - 1 , j = 1 ; j <= k - 2 ; i-- , j++)
    {
        ans[i] = 97 + k - j;
    }

    for(ll i = 0 ; i < n ; i++)
    {
        if(ans[i] != 0) break;
        ans[i] = (i % 2 == 0 ? 'a' : 'b');
    }
    for(ll i = 0 ; i < n ; i++) cout << char(ans[i]);

    return 0;
}