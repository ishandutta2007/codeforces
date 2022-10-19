#include <bits/stdc++.h>

using namespace std;

#define INF 1000000100
#define M 400100

int n, a[M], s, l, d[M], corr[M], lc[M], rc[M];

void read() {
    cin >> n >> s >> l;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

struct Node {
    int mn, mx, mind;
    Node() : mn(INF), mx(-INF), mind(INF) {}
    Node(int mn, int mx, int mnd) : mn(mn), mx(mx), mind(mind) {}
    int diff() {
        return mx - mn;
    }
} tree[M];

Node comb(const Node &x, const Node &y) {
    return Node(min(x.mn, y.mn), max(x.mx, y.mx), min(x.mind, y.mind));
}

void build(int v, int l, int r) {
    lc[v] = l;
    rc[v] = r;
    if (r - l == 1) {
        tree[v].mn = tree[v].mx = a[l];
        tree[v].mind = INF;
        corr[l] = v;
        return;
    }

    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
}

void upd(int v, int l, int r, int pos) {
    if (r - l == 1) {
        tree[v].mind = d[pos];
        return;
    }

    int m = (l + r) / 2;
    if (pos < m)
        upd(2 * v, l, m, pos);
    else
        upd(2 * v + 1, m, r, pos);
    tree[v].mind = min(tree[2 * v].mind, tree[2 * v + 1].mind);
}

int get(int rb) {
    int v = corr[rb - 1];
    Node x = tree[v];
    while (v > 1) {
        Node y = v % 2 == 1 ? comb(tree[2 * (v / 2)], x) : x;
        if (y.diff() > s)
            break;
        x = y;
        v /= 2;
    }

    if (v == 1 && x.diff() <= s)
        return 0;

    v = 2 * (v / 2);
    int l = lc[v], r = rc[v];

    while (true) {
        if (r - l == 1)
            if (comb(tree[v], x).diff() > s)
                return r;
            else
                return l;

        Node y = comb(tree[2 * v + 1], x);
        if (y.diff() <= s) {
            x = y;
            v = 2 * v;
            r = (l + r) / 2;
        } else {
            v = 2 * v + 1;
            l = (l + r) / 2;
        }
    }
}

int getMinD(int v, int l, int r, int lb, int rb) {
    if (l == lb && r == rb)
        return tree[v].mind;
    int m = (l + r) / 2, ans = INF;
    if (lb < m)
        ans = min(ans, getMinD(2 * v, l, m, lb, min(m, rb)));
    if (m < rb)
        ans = min(ans, getMinD(2 * v + 1, m, r, max(m, lb), rb));
    return ans;
}

void din() {
    build(1, 0, n);
    d[0] = 0;
    upd(1, 0, n, 0);
    for (int i = 1; i <= n; ++i) {
        int pos = get(i);
        d[i] = INF;
        //cerr << i << ", " << pos << "\n";
        if (i - pos >= l)
            d[i] = min(d[i], getMinD(1, 0, n, pos, i - l + 1) + 1);
        upd(1, 0, n, i);
    }  
    cout << (d[n] >= INF ? -1 : d[n]) << "\n";
}

int main() {
    read();
    din();
    return 0;
}