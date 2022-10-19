#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define M 400400

int t[M];

void upd(int v, int l, int r, int lb, int rb, int val) {
    if (l == lb && r == rb) {
        t[v] |= val;
        return;
    }
    int m = (l + r) >> 1;
    if (lb < m)
        upd(2 * v, l, m, lb, min(rb, m), val);
    if (m < rb)
        upd(2 * v + 1, m, r, max(lb, m), rb, val);
}

int get(int v, int l, int r, int lb, int rb) {
    if (l == lb && r == rb) {
        return t[v];
    }
    int ans = (1 << 30) - 1;
    int m = (l + r) >> 1;
    if (lb < m)
        ans &= get(2 * v, l, m, lb, min(rb, m));
    if (m < rb)
        ans &= get(2 * v + 1, m, r, max(lb, m), rb);
    return ans | t[v];
}

int n, m, l[M], r[M], q[M];

void kill() {
    cin >> n >> m;
    ++n;
    for (int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i] >> q[i];
        ++r[i];
    }

    for (int i = 0; i < m; ++i)
        upd(1, 1, n, l[i], r[i], q[i]);

    bool yes = true;

    for (int i = 0; i < m; ++i)
        if (get(1, 1, n, l[i], r[i]) != q[i])
            yes = false;

    if (!yes) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    for (int i = 1; i < n; ++i, cout << " ")
        cout << get(1, 1, n, i, i + 1);
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);

    kill();

    return 0;
}