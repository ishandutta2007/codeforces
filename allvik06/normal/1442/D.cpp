#include <bits/stdc++.h>

using namespace std;
#define int long long
int n, k;

vector <vector <int>> a;
vector <int> sum;
int maxx = 0;

void add(vector <int>&g, int x, int w) {
    for (int i = k - w; i >= 0; --i) {
        g[i + w] = max(g[i + w], g[i] + x);
    }
}

void calc(int l, int r, vector <int>&g) {
    if (l > r) return;
    if (l == r) {
        if (l >= n) return;
        int cur = 0;
        for (int kol = 0; kol <= min(k, (int)a[l].size()); ++kol) {
            maxx = max(maxx, cur + g[k - kol]);
            if (kol < a[l].size()) cur += a[l][kol];
        }
        return;
    }
    int m = (l + r) / 2;
    vector <int> left = g;
    vector <int> right = g;
    for (int i = l; i <= m; ++i) {
        if (i < n) add(left, sum[i], a[i].size());
    }
    calc(m + 1, r, left);
    for (int i = m + 1; i <= r; ++i) {
        if (i < n) add(right, sum[i], a[i].size());
    }
    calc(l, m, right);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    a.resize(n);
    sum.resize(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i].resize(x);
        for (int j = 0; j < x; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
    }
    int len = 1 << (int)ceil(log2(n));
    vector <int> g(k + 1);
    calc(0, len - 1, g);
    cout << maxx;
}