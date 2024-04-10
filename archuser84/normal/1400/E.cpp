#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 5'010;
int a[N];
int16_t dp[N][N];
int16_t dpu[N][N];
int16_t dpd[N][N];
int n;

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n)
        cin >> a[i];

    Loop(i,0,N)
        Loop(j,0,N)
            dp[i][j] = dpu[i][j] = dpd[i][j] = N;

    Loop(j,0,min(a[0], n)+1)
        dp[0][j] = j + (j < a[0]);
    dpd[0][0] = dp[0][0];
    Loop(j,1,n+1)
        dpd[0][j] = min(int16_t(dpd[0][j-1] + 1), dp[0][j]);
    dpu[0][n] = dp[0][n];
    LoopR(j,0,n)
        dpu[0][j] = min(dpu[0][j+1], dp[0][j]);

    Loop(i,1,n)
    {
        Loop(j,0,min(a[i], n)+1)
            dp[i][j] = min(dpu[i-1][j], dpd[i-1][j]) + (j < a[i]);

        dpd[i][0] = dp[i][0];
        Loop(j,1,n+1)
            dpd[i][j] = min(int16_t(dpd[i][j-1] + 1), dp[i][j]);
        dpu[0][n] = dp[0][n];
        LoopR(j,0,n)
            dpu[i][j] = min(dpu[i][j+1], dp[i][j]);
    }

    int16_t ans = N;
    Loop(i,0,n+1)
        ans = min(ans, dp[n-1][i]);
    cout << ans << '\n';
}