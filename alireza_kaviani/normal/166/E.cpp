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

const ll MAXN = 1e7 + 10 , mod = 1e9 + 7;
ll dp[MAXN];

int main()
{
    fast_io;

    int n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 3;

    for(int i = 3 ; i <= n ; i++)
    {
        dp[i] = (dp[i - 2] * 3 + dp[i - 1] * 2) % mod;
    }
    cout << dp[n] << endl;

    return 0;
}