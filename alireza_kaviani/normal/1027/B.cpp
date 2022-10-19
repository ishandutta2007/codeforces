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

    ll n , q;
    cin >> n >> q;

    while(q--)
    {
        ll x , y;
        cin >> x >> y;
        if(x % 2 == y % 2)
        {
            ll p;
            if(n % 2 == 1)  p = (x - 1) / 2 * n + (x % 2 == 1 ? 0 : (n + 1) / 2);
            else    p = (x - 1) * (n / 2);
            cout << p + (y + 1) / 2 << endl;
        }
        else
        {
            ll p = n * n / 2 + n * n % 2;
            if(n % 2 == 1)  p += (x - 1) / 2 * n + (x % 2 == 1 ? 0 : n / 2);
            else    p += (x - 1) * n / 2;
            cout << p + (y + 1) / 2 << endl;
        }
    }

    return 0;
}