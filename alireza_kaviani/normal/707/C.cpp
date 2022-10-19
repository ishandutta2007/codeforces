#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

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

int main()
{
    fast_io;

    ll n , m = 1;
    cin >> n;

    while(n % 2LL == 0)
    {
        n /= 2LL;
        m *= 2LL;
    }

    if(n == 1LL)
    {
        n *= m;
        if(n < 3)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << (n / 4) * 3 << ends << (n / 4) * 5 << endl;
        }
        return 0;
    }

    n *= n;
    cout << n / 2 * m << ends << (n / 2 + 1) * m << endl;



    return 0;
}