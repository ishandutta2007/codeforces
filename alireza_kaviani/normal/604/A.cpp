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

    ll m[5] , w[5], hs , hu , ans = 0;
    for(int i = 0 ;i < 5 ; i++)     cin >> m[i];
    for(int i = 0 ;i < 5 ; i++)
    {
        cin >> w[i];

        ll x = (i + 1) * 500;
        ans += max(x * 3 / 10 , (x * (250 - m[i])) / 250 - w[i] * 50);
    }
    cin >> hs >> hu;
    ans += hs * 100 - hu * 50;
    cout << ans << endl;

    return 0;
}