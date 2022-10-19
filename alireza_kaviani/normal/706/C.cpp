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

const ll MAXN = 1e5 + 10 , INF = 1e18;
ll c[MAXN] , dp[2][MAXN];
string s[2][MAXN];

int main()
{
    fast_io;

    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++)    cin >> c[i];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[0][i]; s[1][i] = s[0][i] ; reverse(s[1][i].begin() , s[1][i].end());
    }

    dp[0][0] = 0;
    dp[1][0] = c[0];

    for(int i = 1 ; i < n ; i++)
    {
        dp[0][i] = dp[1][i] = INF;
        if(s[0][i] >= s[0][i - 1])
        {
            dp[0][i] = min(dp[0][i] , dp[0][i - 1]);
        }
        if(s[0][i] >= s[1][i - 1])
        {
            dp[0][i] = min(dp[0][i] , dp[1][i - 1]);
        }
        if(s[1][i] >= s[0][i - 1])
        {
            dp[1][i] = min(dp[1][i] , dp[0][i - 1] + c[i]);
        }
        if(s[1][i] >= s[1][i - 1])
        {
            dp[1][i] = min(dp[1][i] , dp[1][i - 1] + c[i]);
        }
    }

    ll ans = min(dp[0][n - 1] , dp[1][n - 1]);
    cout << (ans >= INF ? -1 : ans) << endl;

    return 0;
}