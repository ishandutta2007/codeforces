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

    ll n , h , a , b , k;
    cin >> n >> h >> a >> b >> k;

    while(k--)
    {
        ll x1 , y1 , x2 , y2 , ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        ans = abs(x1 - x2);
        if(x1 == x2)    { cout << (abs(y1 - y2)) << endl; continue;}
        if(a <= y1 && y1 <= b)  ans += abs(y1 - y2);
        if(y1 < a)  ans += a - y1 + abs(a - y2);
        if(y1 > b)  ans += y1 - b + abs(b - y2);
        cout << ans << endl;
    }

    return 0;
}