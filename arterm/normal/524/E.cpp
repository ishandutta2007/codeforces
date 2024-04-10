#include <bits/stdc++.h>

using namespace std;

struct Query {
    int l, r, x, No;
    Query(int l, int r, int x, int No) : l(l), r(r), x(x), No(No) {}
};

const int M = 800800;
const int INF = 1000000000;
int n, m, k, q;
vector<int> p[2][M];
vector<Query> qs[2][M];
int ans[M];


struct Node {
    int mn;
    Node *l, *r;
    Node() : mn(0), l(nullptr), r(nullptr) {}
} store[2 * M];

int allocated = 0;

Node *getNode() {
    return store + allocated++;
}

int getMin(Node *v) {
    if (v == nullptr)
        return 0;
    return v->mn;
}

void upd(Node *v) {
    if (v == nullptr)
        return;
    v->mn = min(getMin(v->l), getMin(v->r));
}

Node *build(int l, int r) {
    if (r - l == 1) {
        return getNode();
    }
    int m = (l + r) / 2;
    Node *x = getNode();
    x->l = build(l, m);
    x->r = build(m, r);
    return x;
}

void upd(Node *v, int l, int r, int at, int val) {
    if (r - l == 1) {
        v->mn = val;
        return;
    }
    int m = (l + r) / 2;
    if (at < m)
        upd(v->l, l, m, at, val);
    else
        upd(v->r, m, r, at, val);
    upd(v);
}

int get(Node *v, int l, int r, int le, int re) {
    if (l == le && r == re)
        return v->mn;
    int m = (l + r) / 2, ans = INF;
    if (le < m)
        ans = min(ans, get(v->l, l, m, le, min(re, m)));
    if (m < re)
        ans = min(ans, get(v->r, m, r, max(le, m), re));
    return ans;
}

void read() {
    cin >> n >> m >> k >> q;
    for (int i = 0, x, y; i < k; ++i) {
        cin >> x >> y;
        p[0][x].push_back(y);
        p[1][y].push_back(x);
    }
    for (int i = 0, x1, y1, x2, y2; i < q; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        qs[0][x2].emplace_back(y1, y2, x1, i);
        qs[1][y2].emplace_back(x1, x2, y1, i);
    }
}

void kill() {
    int nn[] = {n, m};
    int r[] = {m + 1, n + 1};
    for (int j = 0; j < 2; ++j) {
        n = nn[j];
        Node *root = build(1, r[j]);
        for (int k = 1; k <= n; ++k) {
            for (int x : p[j][k])
                upd(root, 1, r[j], x, k);
            for (auto q : qs[j][k]) {
                if (get(root, 1, r[j], q.l, q.r + 1) < q.x)
                    ans[q.No]++;
            }
        }
    }

    for (int i = 0; i < q; ++i)
        if (ans[i] == 2)
            cout << "NO\n";
        else
            cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}