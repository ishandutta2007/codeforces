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

const int MAXN = 105 , mod = 1e9 + 7;
int dp[MAXN][2];

int main()
{
    fast_io;

    int n , k , d , ans = 0;
    cin >> n >> k >> d;

    dp[0][0] = 1;
    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ;j < 2 ; j++)
        {
            for(int l = 1 ; l <= k ; l++)
            {
                if(i + l <= n)
                {
                    dp[i + l][j | (l >= d ? 1 : 0)] += dp[i][j];
                    dp[i + l][j | (l >= d ? 1 : 0)] %= mod;
                }
            }
        }
    }

    /**for(int i = 1 ; i <= d ; i++)
    {
        for(int j = 1 ;j <= n ; j++)
        {
            cout << i << endt << j << endt << dp[i][j] << endl;
        }
    }*/

    cout << dp[n][1];

    return 0;
}