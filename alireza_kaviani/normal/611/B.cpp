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

    ll l , r , ans = 0;
    cin >> l >> r;

    for(int i = 1 ; i <= 62 ; i++)
    {
        for(int j = 0 ; j < i - 1 ; j++)
        {
            ll x = ((1LL << i) - 1 - (1LL << j));
            if(x >= l && x <= r)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}