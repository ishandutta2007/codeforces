#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll int64_t
#define ull uint64_t
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int mod = 998244353;
const int N = 2005;
ll dp[N][N];
ll powD[N];
int a[N][N];
int n;

struct fen
{
    int a[N] = {};
    void add(int i, int v)
    {
        ++i;
        while(i < N)
        {
            a[i] += v;
            i += i&(-i);
        }
    }
    int get(int r)
    {
        int ans = 0;
        while(r > 0)
        {
            ans += a[r];
            r -= r&(-r);
        }
        return ans;
    }
    bool exist(int i){return get(i+1)-get(i);}
};

void calc_dp()
{
    dp[0][0] = 1; Loop(i,1,N) dp[i][i] = dp[i-1][i-1]*i % mod;
    Loop(j,1,N) dp[j-1][j] = dp[j-1][j-1]*(j-1) % mod;
    Loop(i,2,N) Loop(j, i, N) dp[j-i][j] = (dp[j-i][j-1]*(j-i) + dp[j-i+1][j-1]*(i-1)) % mod;
    powD[0] = 1; Loop(i,1,N) powD[i] = powD[i-1]*dp[0][n] % mod;
}

ll cnt_first()
{
    ll ans = 0;
    fen ghabli; Loop(i,0,n) ghabli.add(i, 1);
    Loop(i,0,n)
    {
        ans += dp[n-1-i][n-1-i]*ghabli.get(a[0][i]);
        ans %= mod;
        ghabli.add(a[0][i], -1);
    }
    return ans*powD[n-1] % mod;
}

ll cnt(int i)
{
    fen azad, zendan; Loop(i,0,n) zendan.add(i, 1);
    ll ans = 0;
    Loop(j,0,n)
    {
        ans += azad.get(a[i][j]) *
               dp[azad.get(N)-1 + zendan.exist(a[i-1][j])][n-1-j]
               % mod;
        ans += (zendan.get(a[i][j]) - (a[i-1][j] < a[i][j] && zendan.exist(a[i-1][j]))) *
               dp[azad.get(N) + zendan.exist(a[i-1][j])][n-1-j]
               % mod;
        ans %= mod;
        if(azad  .exist(a[i][j])) azad  .add(a[i][j], -1);
        if(zendan.exist(a[i][j])) zendan.add(a[i][j], -1);
        if(zendan.exist(a[i-1][j])) zendan.add(a[i-1][j], -1), azad.add(a[i-1][j], 1);
    }
    return ans*powD[n-1-i] % mod;
}

int main()
{
    FAST;
    cin >> n;
    Loop(i,0,n) Loop(j,0,n) cin >> a[i][j], a[i][j]--;
    calc_dp();
    ll ans = 0;
    ans += cnt_first();
    Loop(i,1,n) ans = (ans + cnt(i)) % mod;
    cout << ans << '\n';
}