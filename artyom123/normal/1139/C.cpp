#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;
const int mod = 1e9 + 7;
vector <bool> usd;
vector <int> comp;
vector <vector<int>> g;

void dfs(int v, vector <int> &now) {
    now.push_back(v);
    usd[v] = true;
    for (auto &to : g[v]) {
        if (!usd[to]) {
            dfs(to, now);
        }
    }
}

long long my_pow(long long n, int m) {
    if (m == 0) {
        return 1;
    }
    long long now = my_pow(n, m / 2);
    if (m % 2 == 0) {
        return (now * now) % mod;
    }
    return (((now * now) % mod) * n) % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    g.resize(n);
    usd.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        if (x == 1) {
            continue;
        }
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for (int i = 0; i < n; i++) {
        if (!usd[i]) {
            vector <int> now;
            dfs(i, now);
            comp.push_back(now.size());
        }
    }
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans *= n;
        ans %= mod;
    }
    for (int i = 0; i < comp.size(); i++) {
        ans -= my_pow(comp[i], k);
        ans += mod;
        ans %= mod;
    }
    cout << ans;
    return 0;
}