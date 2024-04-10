#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5, lg = 30;

struct node {
    array<array<int, 2>, 2> dp;
    array<int, 2> go;

    node() {
        go[0] = go[1] = -1;
        dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
    }
};

node tree[maxn * lg];

int sz = 1;

int get(int a, int p) {
    int ans = 0, nw = 0;
    for (int i = lg - 1; i >= 0 && nw != -1; --i) {
        ans = max(ans, tree[nw].dp[(p >> i) & 1][((a >> i) & 1) ^ 1]);
        nw = tree[nw].go[((a ^ p) >> i) & 1];
    }
    return ans;
}

void update(int a, int p, int val) {
    int nw = 0;
    for (int i = lg - 1; i >= 0; --i) {
        tree[nw].dp[(a >> i) & 1][(p >> i) & 1] = max(tree[nw].dp[(a >> i) & 1][(p >> i) & 1], val);
        if (tree[nw].go[((a ^ p) >> i) & 1] == -1) {
            tree[nw].go[((a ^ p) >> i) & 1] = sz;
            tree[sz] = node();
            sz++;
        }
        nw = tree[nw].go[((a ^ p) >> i) & 1];
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sz = 1;
    tree[0] = node();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int dp_nw = get(a[i], i) + 1;
        ans = max(ans, dp_nw);
        update(a[i], i, dp_nw);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}