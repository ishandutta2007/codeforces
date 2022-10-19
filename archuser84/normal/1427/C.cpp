#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define YN(flag) (flag? "YES": "NO")
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O3")
using namespace std;

const int N = 200'010;
const int R = 1'010;
int dp[N];
int maxdp[N];
int n, r;
int t[N], x[N], y[N];
int ans = 0;

int main()
{
    FAST;
    cin >> r >> n;
    Loop(i,0,n)
        cin >> t[i] >> x[i] >> y[i],
        x[i]--, y[i]--;
    dp[n-1] = 1;
    maxdp[n-1] = 1;
    if(t[n-1] >= x[n-1] + y[n-1])
        ans = max(ans, dp[n-1]);
    LoopR(i,0,n-1)
    {
        dp[i] = 0;
        Loop(j,i+1,n)
            if(j-i > 2*r+10)
                {dp[i] = max(dp[i], maxdp[j]); break;}
            else if(t[j] - t[i] >= abs(x[j]-x[i]) + abs(y[j]-y[i]))
                dp[i] = max(dp[i], dp[j]);
        dp[i]++;
        maxdp[i] = max(dp[i], maxdp[i+1]);
        if(t[i] >= x[i] + y[i])
            ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}