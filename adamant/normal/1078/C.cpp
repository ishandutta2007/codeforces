#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define int int64_t

const int maxn = 4e5 + 42;
const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}
int mul(int a, int b) {
    return a * b % mod;
}
int sub(int a, int b) {
    return (a - b + mod) % mod;
}

vector<int> g[maxn];
int dp[maxn][3];
// 0 --  
// 1 --  
// 2 --  

void dfs(int v = 0, int p = 0) {
    dp[v][1] = 1;
    vector<int> pref;
    int isol = 1;
    for(auto u: g[v]) {
        if(u != p) {
            dfs(u, v);
            int t = add(dp[u][0], dp[u][2]);
            dp[v][1] = mul(dp[v][1], t);
            pref.push_back(t);
            isol = mul(isol, dp[u][0]);
        }
    }
    vector<int> suf(rall(pref));
    int m = pref.size();
    for(int i = 1; i < m; i++) {
        suf[i] = mul(suf[i], suf[i - 1]);
        pref[i] = mul(pref[i], pref[i - 1]);
    }
    reverse(all(suf));
    dp[v][0] = isol;
    dp[v][2] = 0;
    int cur = 0;
    for(auto u: g[v]) {
        if(u != p) {
            int t = mul(mul(cur == 0 ? 1 : pref[cur - 1], 
                            cur == m - 1 ? 1 : suf[cur + 1]), dp[u][1]);
            dp[v][0] = add(dp[v][0], t);
            dp[v][2] = add(dp[v][2], t);
            cur++;
        }
    }
    //cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << ' ' << dp[v][2] << endl;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    cout << dp[0][0] << endl;
    return 0;
}