///
///    "Excuse me... What did you say about my hair?!"
///
///                                    -Josuke Higashikata

#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) exit((cout << (x) << '\n', 0))
#define YN(flag) ((flag)? "YES": "NO")
#define F first
#define S second
typedef          long long   ll;
typedef unsigned long long  ull;
typedef std::pair<int,int>  pii;
typedef std::pair<ll ,ll >  pll;
using namespace std;
//#pragma GCC optimize("O0")

const int N = 300'010;

int dp[N][42];

int main()
{
    FAST;
    dp[0][0] = 0; Loop(i,1,42) dp[0][i] = 1e6;
    int n;
    cin >> n;
    Loop(i,0,n)
    {
        int a;
        cin >> a; a /= 1000;
        Loop(j,0,42)
        {
            dp[i+1][j] = dp[i][max(j-a, 0)] + 10*a;
            for(int k = 0; k <= 10*a && j+k<42; ++k)
                dp[i+1][j] = min(dp[i+1][j], dp[i][j+k] + 10*a-k);
        }
    }
    cout << dp[n][0]*100;
}