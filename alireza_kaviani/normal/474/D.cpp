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

const int MAXN = 1e5 + 10 , mod = 1e9 + 7;
ll dp[MAXN] , ps[MAXN];

int main()
{
    fast_io;

    int t , k;
    cin >> t >> k;

    dp[0] = 1;
    ps[0] = 1;
    for(int i = 1 ; i <= MAXN ; i++)
    {
        dp[i] = (dp[i - 1] + (i >= k ? dp[i - k] : 0)) % mod;
        ps[i] = (ps[i - 1] + dp[i]) % mod;
    }

    while(t--)
    {
        int x , y;
        cin >> x >> y;

        cout << ((ps[y] - ps[x - 1]) + mod )% mod << endl;
    }

    return 0;
}