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

const int MAXN = 5010;
ll dp[MAXN][MAXN];

int main()
{
    fast_io;

    int n , m , k;
    cin >> n >> m >> k;

    ll q[n] , ps[n];
    for(int i = 0 ; i < n ; i++)    cin >> q[i];
    partial_sum(q , q + n , ps);
    for(int i = 0 ; i < n ; i++)
    {
        if(i < m - 1)   continue;
        if(i == m - 1)  { dp[i][1]  = ps[i]; continue; }
        for(int j = 1 ; j <= k ; j++)
        {
            if(j * m - 1 > i)   break;
            dp[i][j] = max(dp[i - 1][j] , dp[i - m][j - 1] + ps[i] - ps[i - m]);
        }
    }
    cout << dp[n - 1][k] << endl;

    return 0;
}