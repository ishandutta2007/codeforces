#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int tree[(1 << 21)], psh[(1 << 21)], a[maxn], p[maxn], pref[maxn];
int go[maxn];

inline void push(int i) {
    tree[i] += psh[i];
    psh[2 * i + 1] += psh[i];
    psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void build(int i, int l, int r) {
    if (r - l == 1) tree[i] = pref[l];
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

void update(int i, int l, int r, int lq, int rq, int x) {
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0, R = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) go[p[i]] = i;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[go[i]];
    }
    build(0, 0, n + 1);
    ans = a[1];
    for (int i = 1; i < n; ++i) {
        update(0, 0, n + 1, p[i], n + 1, -a[i]);
        update(0, 0, n + 1, 0, p[i], a[i]);
        ans = min(ans, tree[0]);
    }
    cout << ans << '\n';
    return 0;
}