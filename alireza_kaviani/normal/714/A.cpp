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

    ll l1 , l2 , r1 , r2 , k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;

    ll l = max(l2 , l1) , r = min(r2 , r1) , t = r - l + 1;
    if(l <= k && k <= r)
    {
        t--;
    }
    cout << max(0ll , t) << endl;

    return 0;
}