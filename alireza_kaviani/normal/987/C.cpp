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

const int MAXN = 3010;
ll dp[3][MAXN];

int main()
{
    fast_io;

    int n;
    cin >> n;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ;j < n ;j ++)
        {
            dp[i][j] = 1e15;
        }
    }

    ll s[n] , c[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }
    for(int i = 0 ;i < n; i++)
    {
        cin >> c[i];
    }

    for(int i = 0 ;i < 3 ; i++)
    {
        for(int j = i ;j < n ; j++)
        {
            if(i == 0)
            {
                dp[i][j] = c[j];
            }
            else
            {
                for(int k = i - 1 ; k < j ; k++)
                {
                    if(s[j] > s[k] && k < j)
                    {
                        dp[i][j] = min(dp[i][j] , dp[i - 1][k] + c[j]);
                    }
                }
            }
        }
    }

    ll ans = 1e15;
    for(int i = 0 ; i < n ;i++)
    {
        ans = min(ans, dp[2][i]);
    }
    cout << (ans == 1e15 ? -1 : ans) << endl;

    return 0;
}