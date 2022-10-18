#pragma target("sse4")
#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int p[maxn], q[maxn], add[(1 << 20)], imax[(1 << 20)], pos[maxn];
pair < int, int > imin[(1 << 20)];

void build(int i, int l, int r) {
    imin[i].second = l;
    if (r - l == 1) {
        pos[p[l]] = l;
        imax[i] = p[l];
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
    imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
}

inline void push(int i, int l, int r) {
    imin[i].first += add[i];
    if (r - l > 1) {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void update(int i, int l, int r, int lq, int rq, int x) {
    push(i, l, r);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, x);
    update(2 * i + 2, m, r, lq, rq, x);
    imin[i] = min(imin[2 * i + 1], imin[2 * i + 2]);
}

void dels(int i, int l, int r, int lq) {
    if (r - l == 1) imax[i] = 0;
    else {
        int m = (r + l) / 2;
        if (lq < m) dels(2 * i + 1, l, m, lq);
        else dels(2 * i + 2, m, r, lq);
        imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
    }
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return 0;
    if (lq <= l && r <= rq) return imax[i];
    int m = (r + l) / 2;
    return max(get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq));
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) cin >> q[i];
    build(0, 1, n + 1);
    cout << n << " ";
    for (int i = 1; i < n; ++i) {
        update(0, 1, n + 1, q[i], n + 1, -1);
        int good = imin[0].second;
        int x = get(0, 1, n + 1, 1, good + 1);
        update(0, 1, n + 1, pos[x], n + 1, 1);
        dels(0, 1, n + 1, pos[x]);
        cout << imax[0] << " ";
    }
    return 0;
}