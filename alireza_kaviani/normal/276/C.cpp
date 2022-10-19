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

    ll n , m , ans = 0;
    cin >> n >> m;

    ll ps[n] , a[n];
    for(int i = 0 ; i < n ; i++)    cin >> a[i];

    fill(ps , ps + n , 0);
    for(int i = 0 ; i < m ; i++)
    {
        ps[input() - 1]++;
        ps[input()]--;
    }

    partial_sum(ps , ps + n , ps);
    sort(ps , ps + n);
    sort(a , a + n);
    for(int i = 0 ; i < n ; i++)    ans += a[i] * ps[i];
    cout << ans << endl;

    return 0;
}