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

ll mod(ll n , ll m)
{
    return (n % m == 0 ? m : n % m);
}

ll dive(ll n , ll m)
{
    return (n % m == 0 ? n / m : n / m + 1);
}

int main()
{
    fast_io;

    ll n , m , k;
    cin >> n >> m >> k;

    if(k < n)
    {
        cout << k + 1 << ends << 1 << endl;
        return 0;
    }

    k -= (n - 1);
    ll t = dive(k , m - 1);
    if(t % 2 == 1)
    {
        cout << n - t + 1 << ends << mod(k , m - 1) + 1;
        return 0;
    }
    cout << n - t + 1 << ends << m - mod(k , m - 1) + 1;

    return 0;
}