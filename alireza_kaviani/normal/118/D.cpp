#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;

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

const int MAXN = 110 , MOD = 1e8;
int dp[MAXN][MAXN][2];

int main()
{
    fast_io;

    int n1 , n2 , k1 , k2;
    cin >> n1 >> n2 >> k1 >> k2;

    dp[0][0][0] = dp[0][0][1] = 1;
    for(int i = 0 ; i <= n1 ; i++)
    {
        for(int j = 0 ; j <= n2 ; j++)
        {
            for(int k = 1 ; k <= min(i , k1) ; k++)
            {
                dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % MOD;
            }
            for(int k = 1 ; k <= min(j , k2) ; k++)
            {
                dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % MOD;
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD;

    return 0;
}