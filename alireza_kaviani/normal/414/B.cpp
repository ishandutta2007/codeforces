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

const ll MAXN = 2010 , mod = 1e9 + 7;
ll dp[MAXN][MAXN];

int main()
{
    fast_io;

    ll n , k , ans = 0;
    cin >> n >> k;

    for(int i = 1 ; i <= k; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(i == 1)
            {
                dp[i][j] = 1;
            }
            for(int l = j ; l <= n ; l += j)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][l] + mod) % mod;
            }
        }
    }

    for(int i = 1 ; i <= n; i++)
    {
        ans = (ans + dp[k][i] + mod) % mod;
    }
    cout << ans % mod << endl;

    return 0;
}