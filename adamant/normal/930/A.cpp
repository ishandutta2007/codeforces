#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42;

vector<int> g[maxn];

int ans[maxn];

void dfs(int v = 0, int h = 0) {
    ans[h] ^= 1;
    for(auto u: g[v]) {
        dfs(u, h + 1);
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
        g[a[i] - 1].push_back(i + 1);
    }
    dfs(0);
    cout << accumulate(ans, ans + n, 0) << endl;
    return 0;
}