#include <iostream>

using namespace std;

struct Node {
    int val, add;
};

const int MAXN = 100 * 1000 + 5;
Node st[4 * MAXN];
int l[MAXN], r[MAXN], q[MAXN];

void push(int v) {
    if(!st[v].add)
        return;
    st[2 * v].val |= st[v].add;
    st[2 * v].add |= st[v].add;
    st[2 * v + 1].val |= st[v].add;
    st[2 * v + 1].add |= st[v].add;
    st[v].add = 0;
}

void update(int v, int tl, int tr, int l, int r, int q) {
    if(l == tl && r == tr) {
        st[v].add |= q;
        st[v].val |= q;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if(l < tm)
        update(2 * v, tl, tm, l, min(r, tm), q);
    if(r > tm)
        update(2 * v + 1, tm, tr, max(l, tm), r, q);
    st[v].val = (st[2 * v].val & st[2 * v + 1].val);
}

int get(int v, int tl, int tr, int l, int r) {
    if(l == tl && r == tr)
        return st[v].val;
    push(v);
    int tm = (tl + tr) / 2, res = (1 << 30) - 1;
    if(l < tm)
        res &= get(2 * v, tl, tm, l, min(r, tm));
    if(r > tm)
        res &= get(2 * v + 1, tm, tr, max(l, tm), r);
    return res;
}

void printst(int v, int tl, int tr) {
    if(tl == tr - 1) {
        cout << st[v].val << ' ';
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    printst(2 * v, tl, tm);
    printst(2 * v + 1, tm, tr);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
        update(1, 0, n, l[i], r[i], q[i]);
    }
    for(int i = 0; i < m; i++)
        if(get(1, 0, n, l[i], r[i]) != q[i]) {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    printst(1, 0, n);
    cout << '\n';
    return 0;
}