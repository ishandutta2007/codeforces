#include <bits/stdc++.h>
#define _ << " " <<
#define int long long

using namespace std;

const int MOD = 998244353;

vector<vector<int>> g;

main() {
    const int MAXN = 5e5;
    vector<int> fact(MAXN);
    fact[0] =1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        ans *= fact[g[i].size()];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}