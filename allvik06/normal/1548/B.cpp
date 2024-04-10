#include <bits/stdc++.h>

using namespace std;
#define int long long

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

vector <int> tree, a;

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    tree[v] = gcd(tree[2 * v], tree[2 * v + 1]);
}

inline int get_gcd(int l, int r, int len) {
    l += len;
    r += len;
    int g = 0;
    while (l < r) {
        if (l & 1) {
            g = gcd(tree[l], g);
            ++l;
        }
        if (!(r & 1)) {
            g = gcd(tree[r], g);
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    if (l == r) g = gcd(g, tree[l]);
    return g;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    int max_len = (1 << (int)ceil(log2(2 * 100000)));
    tree.resize(2 * max_len);
    a.resize(max_len);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i];
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int len = (1 << (int)ceil(log2(n - 1)));
        for (int i = 0; i < n - 1; ++i) {
            a[i] = abs(b[i] - b[i + 1]);
        }
        build(1, 0, len - 1);
        int r = 0, curg = a[0], ans = 1;
        for (int l = 0; l < n - 1; ++l) {
            if (a[l] == 1) continue;
            r = max(r, l);
            curg = get_gcd(l, r, len);
            while (r + 1 < n - 1 && gcd(curg, a[r + 1]) > 1) {
                ++r;
                curg = gcd(curg, a[r]);
            }
            ans = max(ans, r - l + 2);
        }
        cout << ans << "\n";
    }
}