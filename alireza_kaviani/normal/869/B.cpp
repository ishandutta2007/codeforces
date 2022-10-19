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

int main()
{
    fast_io;

    ll n , m;
    cin >> n >> m;

    if(m - n >= 5)
    {
        cout << 0 << endl;
    }
    else
    {
        ll t = 1;
        for(ll i = n + 1 ; i <= m ; i++)
        {
            t *= i;
            t %= 10;
        }
        cout << t << endl;
    }

    return 0;
}