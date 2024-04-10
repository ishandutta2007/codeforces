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
ll pw(ll a , ll b)  { return (!b ? 1 : (b & 1 ? a * pw(a * a , b / 2) : pw(a * a , b / 2))); }

int main()
{
    fast_io;

    int n , ans = 2e9;
    cin >> n;

    int x[n] , y[n] , a[4] = {0 , 0 , 1 , 1} , b[4] = {0 , 1 , 0 , 1};
    for(int i = 0 ; i < n ; i++)    cin >> x[i] >> y[i];

    for(int i = 0 ; i < 4 ; i++)
    {
        int cnt = 0;
        for(int j = 0 ; j < n ; j++)
        {
             cnt += abs(x[j] - a[i]) + abs(y[j] - b[i]);
        }
        ans = min(ans , cnt);
    }
    cout << ans << endl;

    return 0;
}