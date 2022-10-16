#include <iostream>

using namespace std;

struct Node {
    int val, upd;
    Node *l, *r;

    Node(): val(0), upd(0), l(0), r(0) {}

    Node(int _val): val(_val), upd(_val), l(0), r(0) {}
};

const int MAXN = 1005, MAXX = 40 * 1000 * 1000 + 5,
    INF = 1000 * 1000 * 1000 + 5;
int a[MAXN][MAXN];
Node *st;

int cp(int x0, int y0, int x1, int y1) {
    return x0 * y1 - y0 * x1;
}

void push(Node *v) {
    if(v->l == 0)
        v->l = new Node(v->val);
    else {
        v->l->upd = max(v->l->upd, v->upd);
        v->l->val = max(v->l->val, v->l->upd);
    }
    if(v->r == 0)
        v->r = new Node(v->val);
    else {
        v->r->upd = max(v->r->upd, v->upd);
        v->r->val = max(v->r->val, v->r->upd);
    }
}

int get(Node *v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return v->val;
    push(v);
    int tm = (tl + tr) / 2, res = INF;
    if(l < tm)
        res = min(res, get(v->l, tl, tm, l, min(r, tm)));
    if(r > tm)
        res = min(res, get(v->r, tm, tr, max(l, tm), r));
    return res;
}

void update(Node *v, int tl, int tr, int l, int r, int val) {
    if(l == tl && r == tr) {
        v->upd = max(v->upd, val);
        v->val = max(v->val, v->upd);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        update(v->l, tl, tm, l, min(r, tm), val);
    if(r > tm)
        update(v->r, tm, tr, max(l, tm), r, val);
    v->val = min(v->l->val, v->r->val);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    if(x < 0) {
        x *= -1;
        for(int i = 0; i < n - i - 1; i++)
            for(int j = 0; j < n; j++)
                swap(a[i][j], a[n - i - 1][j]);
    }
    if(y < 0) {
        y *= -1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n - j - 1; j++)
                swap(a[i][j], a[i][n - j - 1]);
    }
    st = new Node();
    long long ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int l = cp(i + 1, j, x, y), r = cp(i, j + 1, x, y);
            if(l > r)
                swap(l, r);
            l += MAXX / 2;
            r += MAXX / 2;
            int h = get(st, 0, MAXX, l, r);
            if(h < a[i][j])
                ans += a[i][j] - h;
            update(st, 0, MAXX, l, r, a[i][j]);
        }
    cout << ans << '\n';
    return 0;
}