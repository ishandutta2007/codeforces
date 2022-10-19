#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> tree;
vector<int> a;
vector<int> b;


void build(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = {b[l], l};
    } else {
        int m = l + (r - l) / 2;
        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

pair<int, int> query() {
    return tree[0];
}

void update(int v, int l, int r, int ind) {
    if (l > ind) {
        return;
    }
    if (r <= ind) {
        return;
    }
    if (l + 1 == r) {
        tree[v] = {1e9, ind};
    } else {
        int m = l + (r - l) / 2;
        update(2 * v + 1, l, m, ind);
        update(2 * v + 2, m, r, ind);
        tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i];
    }
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    tree.resize(4 * n);
    build(0, 0, n);
    bool lol = false;
    for (int i = 0; i < m; i++) {
        if (lol) {
            cout << 0 << endl;
            continue;
        }
        int t, d;
        cin >> t >> d;
        t--;
        if (a[t] <= d) {
            if (cnt < d) {
                lol = true;
                cout << 0 << endl;
                continue;
            }
            long long ans = 0;
            ans += b[t] * a[t];
            cnt -= d;
            d -= a[t];
            a[t] = 0;
            update(0, 0, n, t);
            while (d) {
                auto min_ = query();
                if (a[min_.second] <= d) {
                    ans += min_.first * a[min_.second];
                    d -= a[min_.second];
                    update(0, 0, n, min_.second);
                    a[min_.second] = 0;
                } else {
                    ans += d * min_.first;
                    a[min_.second] -= d;
                    d = 0;
                }
            }
            cout << ans << endl;
        } else {
            cout << (long long) b[t] * d << endl;
            a[t] -= d;
            cnt -= d;
        }
    }
    return 0;
}