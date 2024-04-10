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

const ll mod = 1e9 + 7;

int main()
{
    fast_io;

    ll n , x , y , ans = 0;
    cin >> x >> y >> n;
    n--;

    switch(n % 6)
    {
    case 0:
        ans = x;
        break;
    case 1:
        ans = y;
        break;
    case 2:
        ans = y - x;
        break;
    case 3:
        ans = -x;
        break;
    case 4:
        ans = -y;
        break;
    case 5:
        ans = x - y;
        break;
    }

    cout << (ans + mod * 5) % mod << endl;

    return 0;
}