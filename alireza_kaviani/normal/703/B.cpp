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

const ll MAXN = 1e5 + 10;
ll n , k , sum = 0 , csum = 0 , ans = 0 , c[MAXN] , id[MAXN] , mark[MAXN];

int main()
{
    fast_io;

    cin >> n >> k;

    for(int i = 0 ; i < n ; i++)    { cin >> c[i]; sum += c[i];}

    for(int i = 0 ; i < k ; i++)
    {
        id[i] = input() - 1;
        mark[id[i]] = 1;
        csum += c[id[i]];
        ans += (sum - c[id[i]]) * c[id[i]];
    }

    for(int i = 0 ; i < k ; i++)
    {
        ans -= (csum - c[id[i]]) * c[id[i]];
        csum -= c[id[i]];
    }

    for(int i = 1 ; i < n ; i++)
        if(!mark[i] && !mark[i - 1])    ans += c[i] * c[i - 1];
    if(!mark[0] && !mark[n - 1])    ans += c[0] * c[n - 1];

    cout << ans << endl;

    return 0;
}