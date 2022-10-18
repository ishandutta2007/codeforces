#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
pair < int, int > tree[8 * maxn];
int psh[8 * maxn];
int a[maxn];
int ans[maxn];
int inf = 1e18;

void build(int i, int l, int r) {
    if (r - l == 1) {
        tree[i] = {a[l], -1 * l};
    }
    else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

void push(int i) {
    tree[i].first += psh[i];
    psh[2 * i + 1] += psh[i], psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int dx) {
    //if (dx == 2) cout << l << " " << r << " " << i << " " << psh[i] << '\n';
    push(i);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        psh[i] -= dx;
        push(i);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, dx);
    update(2 * i + 2, m, r, lq, rq, dx);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(0, 1, n + 1);
    for (int i = 1; i <= n; ++i) {
        pair < int, int > pos = tree[0];
        ans[-1 * pos.second] = i;
        //cout << psh[2] << '\n';
        //cout << go(0, 1, n + 1, 5, 6) << '\n';
        //cout << pos.first << " " << -1 * pos.second << '\n';
        //cout << tree[2].first << '\n';
        update(0, 1, n + 1, -1 * pos.second, -1 * pos.second + 1, -1 * inf);
        update(0, 1, n + 1, -1 * pos.second, n + 1, i);
    }
    for (int i = 1; i <= n ; ++i) cout << ans[i] << " ";
    return 0;
}