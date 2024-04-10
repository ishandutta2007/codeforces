#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 42;
const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}
int sub(int a, int b) {
    return (a - b % mod + mod) % mod;
}

int mul(int a, int b) {
    return a * b % mod;
}

int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

int F[maxn], RF[maxn];

int fact(int n) {
    return n ? F[n] ? F[n] : F[n] = mul(fact(n - 1), n) : 1;
}

int rfact(int n) {
    return inv(fact(n));
}

int nCr(int n, int r) {
    if(r < 0 || r > n) {
        return 0;
    } else {
        return mul(mul(fact(n), rfact(r)), rfact(n - r));
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> g[n];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int sz[n];
    int ans = 0;
    
    auto process = [&](vector<int> szs) {
        assert(n - 1 == accumulate(begin(szs), end(szs), 0));
        int total = 0;
        for(auto it: szs) {
            total = add(total, nCr(it, k));
        }
        for(auto it: szs) {
            int cur = sub(nCr(n - it, k), sub(total, nCr(it, k)));
            ans = add(ans, mul(cur, mul(it, n - it)));
        }
        ans = add(ans, mul(nCr(n - 1, k - 1), n));
        ans = add(ans, mul(sub(nCr(n - 1, k), total), n));
        //cout << endl;
    };
    function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        vector<int> S;
        for(auto u: g[v]) {
            if(u != p) {
                dfs(u, v);
                sz[v] += sz[u];
                S.push_back(sz[u]);
            }
        }
        S.push_back(n - sz[v]);
        process(S);
    };
    dfs(0, 0);
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << endl;
}