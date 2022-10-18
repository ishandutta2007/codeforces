#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 5e5 + 5;
int a[maxn], p[maxn], b[maxn], inf = 1e18, tree[(1 << 20)], add[(1 << 20)];
map < int, int > pos;

void build(int i, int l, int r) {
    if (r - l == 1) {
        tree[i] = inf;
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
}

inline void push(int i) {
    add[2 * i + 1] += add[i];
    add[2 * i + 2] += add[i];
    add[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int x) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        add[i] += x;
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
}

int get(int i, int l, int r, int lq) {
    if (r - l == 1) return add[i] + tree[i];
    push(i);
    int m = (r + l) / 2;
    if (lq < m) return get(2 * i + 1, l, m, lq);
    return get(2 * i + 2, m, r, lq);
}

void modify(int i, int l, int r, int lq, int x) {
    if (r - l == 1) {
        tree[i] = min(tree[i] + add[i], x);
        add[i] = 0;
        return;
    }
    push(i);
    int m = (r + l) / 2;
    if (lq < m) modify(2 * i + 1, l, m, lq, x);
    else modify(2 * i + 2, m, r, lq, x);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    for (int i = 1; i <= m; ++i) pos[b[i]] = i;
    build(0, 1, m + 1);
    for (int i = 1; i <= n; ++i) {
        int lef = 0, righ = m + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (b[mid] < a[i]) lef = mid;
            else righ = mid;
        }
        if (p[i] < 0) lef = m;
        if (pos[a[i]] != 0) {
            int x = pos[a[i]], w = 0;
            if (x == 1) w = sum;
            else w = get(0, 1, m + 1, x - 1);
            if (lef != 0) update(0, 1, m + 1, 1, lef + 1, p[i]);
            modify(0, 1, m + 1, x, w);
        }
        else {
            if (lef != 0) update(0, 1, m + 1, 1, lef + 1, p[i]);
        }
        sum += p[i];
    }
    int f = get(0, 1, m + 1, m);
    if (f >= inf / 2) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        cout << f << '\n';
    }
    return 0;
}