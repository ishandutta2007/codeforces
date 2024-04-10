#include <bits/stdc++.h>

using namespace std;

#define M 400400
#define A 60

int n, a[M];

struct Node {
    int l, r, w[A];

    Node(){}
    Node(int l, int r, int x) : l(l), r(r) {
        for (int i = 0; i < A; ++i)
            if (i % x == 0)
                w[i] = 1;
            else
                w[i] = 0;
    }

} tree[M];

Node comb(const Node &l, const Node &r) {
    assert(l.r == r.l);
    Node ans;
    ans.l = l.l;
    ans.r = r.r;

    for (int i = 0; i < A; ++i) {
        int to = i + l.r - l.l + l.w[i];
        ans.w[i] = l.w[i] + r.w[to % A];  
    }

    return ans;
}

Node get(int v, int le, int re) {
    int l = tree[v].l, r = tree[v].r;
    if (l == le && r == re)
        return tree[v];
    int m = (l + r) / 2;
    if (re <= m)
        return get(2 * v, le, re);
    if (m <= le)
        return get(2 * v + 1, le, re);

    return comb(get(2 * v, le, m), get(2 * v + 1, m, re));
}

void upd(int v, int pos, int val) {
    int l = tree[v].l, r = tree[v].r;
    if (l + 1 == r) {
        tree[v] = Node(l, r, val);
        return;
    }

    int m = (l + r) / 2;
    if (pos < m)
        upd(2 * v, pos, val);
    else
        upd(2 * v + 1, pos, val);

    tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
}

void ini(int v, int l, int r) {
    if (l + 1 == r) {
        tree[v] = Node(l, r, a[l]);
        return;
    }
    int m = (l + r) / 2;
    ini(2 * v, l, m);
    ini(2 * v + 1, m, r);
    tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ini(1, 0, n);
}

void kill() {
    int q;
    cin >> q;
    while (q--) {
        char type;
        int x, y;
        cin >> type >> x >> y;
        if (type == 'A') {
            --x;
            --y;
            cout << get(1, x, y).w[0] + y - x << "\n";
        }

        if (type == 'C') {
            --x;
            upd(1, x, y);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    read();
    kill();

    return 0;
}