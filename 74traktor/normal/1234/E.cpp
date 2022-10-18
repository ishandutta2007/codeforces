#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5;
int a[maxn];
int tree[4 * maxn];

void update(int i, int l, int r, int lq, int rq, int x) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) tree[i] += x;
    else {
        int m = (r + l) / 2;
        update(2 * i + 1, l, m, lq, rq, x);
        update(2 * i + 2, m, r, lq, rq, x);
    }
}

void go(int i, int l, int r) {
    if (r - l == 1) {
        cout << tree[i] << " ";
    }
    else {
        int m = (r + l) / 2;
        tree[2 * i + 1] += tree[i];
        tree[2 * i + 2] += tree[i];
        go(2 * i + 1, l, m);
        go(2 * i + 2, m, r);
    }
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    int ans = 0;
    for (int i = 1; i < m; ++i) {
        int x = a[i], y = a[i + 1];
        if (x > y) swap(x, y);
        if (x == y) continue;
        /*ans += (x - 1) * (y - x);
        ans += (n - y) * (y - x);
        ans += (y - x - 1) * (y - x - 1);
        ans += (y - 1);
        ans += x;*/
        if (x != 1) update(0, 1, n + 1, 1, x, y - x);
        if (y != n) update(0, 1, n + 1, y + 1, n + 1, y - x);
        update(0, 1, n + 1, x, x + 1, y - 1);
        update(0, 1, n + 1, y, y + 1, x);
        if (x + 1 != y) update(0, 1, n + 1, x + 1, y, y - x - 1);
    }
    go(0, 1, n + 1);
    return 0;
}