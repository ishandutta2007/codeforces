#include <bits/stdc++.h>

using namespace std;

const int maxn = 10, maxm = 1e5 + 5, inf = 1e9 + 7;

vector<int> a[maxn];
int b[maxm][maxn];

int n, m;

int ans = 0;

int bld[maxn], nw[maxn];

void gen(int pos, int ans_nw, vector<int> fb) {
    if (pos == n + 1) {
        if (ans_nw > ans) {
            ans = ans_nw;
            for (int i = 0; i < n; ++i) {
                bld[i] = nw[i];
            }
        }
        return;
    }
    if (fb.empty()) {
        for (int i = pos; i < n; ++i) {
            ans_nw += a[i].back();
            nw[i] = a[i].size();
        }
        if (ans_nw > ans) {
            ans = ans_nw;
            for (int i = 0; i < n; ++i) {
                bld[i] = nw[i];
            }
        }
        return;
    }
    map<int, vector<int>> mp;
    for (auto ind : fb) {
        mp[b[ind][pos]].push_back(ind);
    }
    for (int i = (int)a[pos].size() - 1; i >= 0; --i) {
        nw[pos] = i + 1;
        gen(pos + 1, ans_nw + a[pos][i], mp[i]);
        if (mp[i].empty()) {
            break;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
            b[i][j]--;
        }
    }
    vector<int> ind(m);
    iota(ind.begin(), ind.end(), 0);
    gen(0, 0, ind);
    for (int i = 0; i < n; ++i) {
        cout << bld[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}