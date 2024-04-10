#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N];

struct SegTree {
    int mx[4 * N];
    long long sum[4 * N];

    void combine(int k) {
        mx[k] = max(mx[2 * k], mx[2 * k + 1]);
        sum[k] = sum[2 * k] + sum[2 * k + 1];
    }

    void build(int k, int l, int r) {
        if (l == r) {
            sum[k] = mx[k] = a[l];
            return; 
        }
        int mid = (l + r) / 2;
        build(2 * k, l, mid);
        build(2 * k + 1, mid + 1, r);
        combine(k);
    } 

    void update_val(int k, int l, int r, int id, int val) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            sum[k] = mx[k] = val;
            return;
        }
        int mid = (l + r) / 2;
        update_val(2 * k, l, mid, id, val);
        update_val(2 * k + 1, mid + 1, r, id, val);
        combine(k);
    }

    void update_mod(int k, int l, int r, int u, int v, int x) {
        if (l > v || r < u || mx[k] < x) return;
        if (l == r) {
            sum[k] = mx[k] = mx[k] % x;
            return;
        }
        int mid = (l + r) / 2;
        update_mod(2 * k, l, mid, u, v, x);
        update_mod(2 * k + 1, mid + 1, r, u, v, x);
        combine(k);
    }

    long long get(int k, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return sum[k];
        int mid = (l + r) / 2;
        return get(2 * k, l, mid, u, v) + get(2 * k + 1, mid + 1, r, u, v);
    }
} segTree;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    segTree.build(1, 1, n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << segTree.get(1, 1, n, l, r) << '\n';
        } else if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            segTree.update_mod(1, 1, n, l, r, x);
        } else {
            int k, x;
            cin >> k >> x;
            segTree.update_val(1, 1, n, k, x);
        }
    }

    return 0;
}