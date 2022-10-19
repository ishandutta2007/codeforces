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

    ll n , k , s , p = 1 , t = 1;
    cin >> n >> k >> s;

    if((n - 1LL) * k < s || k > s) return cout << "NO" << endl , 0;

    k--;
    cout << "YES" << endl;
    while(s - k > 0LL && k > -1LL)
    {
        ll x = (t == 1 ? min(n - p , s - k) : min(p - 1LL , s - k));
        p += t * x;
        t *= -1LL;
        s -= x;
        k--;
        cout << p << ends;
    }

    for(int i = 0 ; i < k ; i++)
    {
        p += t;
        t *= -1LL;
        cout << p << ends;
    }

    return 0;
}