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
#define tab                         '\t'
#define sep                         ' '
#define endl                        '\n'
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
inline ll input(){ll n; cin >> n ; return n;}
ll pw(ll a , ll b , ll md)  { return (!b ? 1 : (b & 1 ? a * pw(a * a % md , b / 2 , md) % md : pw(a * a % md , b / 2 , md) % md)); }

const ll MAXN = 2e3 + 10,
         INF = 8e18,
         MOD = 998244353;

ll n , m , dp[MAXN][MAXN][4];

int main()
{
    fast_io;  /** if you sure your code is true but get TLE use scanf and printf*/

    cin >> n >> m;

    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][2] = 1;
    dp[1][2][3] = 1;
    for(ll i = 2 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= m ; j++)
        {
            // white - white
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][0] = (dp[i][j + 1][0] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][0] = (dp[i][j + 0][0] + dp[i - 1][j][3]) % MOD;
            //black - black
            dp[i][j + 1][1] = (dp[i][j + 1][1] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][1] = (dp[i][j + 0][1] + dp[i - 1][j][3]) % MOD;
            //white - black
            dp[i][j + 1][2] = (dp[i][j + 1][2] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][2] = (dp[i][j + 1][2] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 0][2] = (dp[i][j + 0][2] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 2][2] = (dp[i][j + 2][2] + dp[i - 1][j][3]) % MOD;
            //black - white
            dp[i][j + 1][3] = (dp[i][j + 1][3] + dp[i - 1][j][0]) % MOD;
            dp[i][j + 1][3] = (dp[i][j + 1][3] + dp[i - 1][j][1]) % MOD;
            dp[i][j + 2][3] = (dp[i][j + 2][3] + dp[i - 1][j][2]) % MOD;
            dp[i][j + 0][3] = (dp[i][j + 0][3] + dp[i - 1][j][3]) % MOD;
        }
    }
    cout << (dp[n][m][0] + dp[n][m][1] + dp[n][m][2] + dp[n][m][3]) % MOD << endl;

    return 0;
}