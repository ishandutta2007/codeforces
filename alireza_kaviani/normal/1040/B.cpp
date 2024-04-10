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

    ll n , k , t , l , r , st , imin = 8e18;
    cin >> n >> k;

    for(int i = 1 ; i <= min(k + 1 , n) ; i++)
    {
        ll t = 0 , x;
        for(int j = i ; j <= n ; j += (k * 2 + 1))  t = t + 1 , x = j;
        if(x + k >= n && t < imin)    imin = t , st = i;
    }
    cout << imin << endl;
    for(int i = st ; i <= n ; i += (k * 2 + 1))   cout << i << ends;

    return 0;
}