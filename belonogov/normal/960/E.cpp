#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),a.end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;
const int MOD = 1e9 + 7;



int main() {
#define TASK "A"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] = (a[i] + MOD) % MOD;
    }
    vector<vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
    }

    vector<vector<int>> dp(n, vector<int>(2));
    ll answer = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        dp[v][0] = 1;
        for (auto u: e[v]) {
            if (u == p) continue;
            dfs(u, v);
            ll rem = n - dp[u][0] - dp[u][1];
            answer = (answer + ((-dp[u][0] + dp[u][1] + MOD) % MOD) * rem % MOD * a[v]) % MOD;
            dp[v][0] += dp[u][1];
            dp[v][1] += dp[u][0];
        }
        //db3(dp[v][0], dp[v][1], rem);
        //db2(v, answer);
    };

    dfs(0, 0);

    //db(answer);
    

    function<void(int, int, int, int)> dfs2 = [&](int v, int p, int dp0, int dp1) {
        ll cnt = dp[v][0] + dp[v][1];
        answer = (answer + ((dp0 - dp1 + MOD) % MOD) * cnt % MOD * a[v]) % MOD;
        dp0 += dp[v][0];
        dp1 += dp[v][1];
        for (auto u: e[v]) {
            if (u == p) continue;
            int c0 = dp0 - dp[u][1];
            int c1 = dp1 - dp[u][0];
            dfs2(u, v, c1, c0);
        }
    };
    dfs2(0, 0, 0, 0);
    for (int i = 0; i < n; i++) {
        answer = (answer + a[i] * 1ll * n + MOD) % MOD;
    }
    cout << answer << endl;
   
    return 0;
}