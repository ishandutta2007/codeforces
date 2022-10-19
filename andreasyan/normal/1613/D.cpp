#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005, M = 998244353;
 
int n;
int a[N];
 
int dp[N][2];
 
void ph(int& x, int y)
{
    x = (x + y) % M;
}
 
void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    for (int i = 0; i <= n; ++i)
        dp[i][0] = dp[i][1] = 0;
 
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        int dpl[2], dpm[2], dpr[2];
        if (a[i] - 1 >= 0)
        {
            dpl[0] = dp[a[i] - 1][0];
            dpl[1] = dp[a[i] - 1][1];
        }
        dpm[0] = dp[a[i]][0];
        dpm[1] = dp[a[i]][1];
        dpr[0] = dp[a[i] + 1][0];
        dpr[1] = dp[a[i] + 1][1];
 
        if (a[i] - 1 >= 0)
        {
            ph(dp[a[i] - 1][1], dpl[0]);
            ph(dp[a[i] - 1][1], dpl[1]);
        }
 
        ph(dp[a[i] + 1][0], dpr[0]);
        ph(dp[a[i] + 1][1], dpr[1]);
 
        ph(dp[a[i] + 1][0], dpm[0]);
    }
 
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        ans = (ans + dp[i][0]) % M;
        ans = (ans + dp[i][1]) % M;
    }
    ans = (ans - 1 + M) % M;
 
    cout << ans << "\n";
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
 
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}