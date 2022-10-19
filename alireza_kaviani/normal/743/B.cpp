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

ll ans(ll n , ll k)
{
    if(k == (1LL << (n - 1LL)))
    {
        return n;
    }
    if(k > (1LL << (n - 1LL)))
    {
        k -= 1LL << (n - 1LL);
    }
    return ans(n - 1LL , k);
}

int main()
{
    fast_io;

    ll n , k;
    cin >> n >> k;
    cout << ans(n , k);

    return 0;
}