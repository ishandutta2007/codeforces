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

const int MAXN = 1e5 + 10;
int a[MAXN] , l[MAXN] , r[MAXN];

int main()
{
    fast_io;

    int n , ans = 0;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);
        ans = max(ans , l[i]);
    }
    if(ans < n) ans++;

    for(int i = n ; i >= 1 ; i--)
    {
        r[i] = (a[i + 1] > a[i] ? r[i + 1] + 1 : 1);
        if(a[i + 1] > a[i - 1] + 1) ans = max(ans , l[i - 1] + r[i + 1] + 1);
    }
    cout << ans << endl;

    return 0;
}