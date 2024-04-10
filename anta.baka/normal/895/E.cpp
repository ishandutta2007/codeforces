#include <bits/stdc++.h>
using namespace std;
using ld = double;
const int maxn = 1e5;
const ld eps = 1e-5;

struct node {
    ld add, mul, sum;
};

node merge(node a, node b) {
    node c;
    c.sum = a.sum + b.sum;
    c.mul = 1;
    c.add = 0;
    return c;
}

int n, q;
ld a[maxn];
node t[4 * maxn];

void build(int v, int l, int r) {
    if(l == r) {
        t[v].sum = a[l];
        t[v].mul = 1;
        t[v].add = 0;
    } else {
        int m = (l + r) / 2;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m + 1, r);
        t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

bool eq(ld a, ld b) {
    return abs(a - b) < eps;
}

void push(int v, int l, int r) {
    if(!eq(t[v].mul, 1.0)) {
        ld x = t[v].mul;
        t[v].mul = 1;
        t[v * 2 + 1].mul *= x;
        t[v * 2 + 1].sum *= x;
        t[v * 2 + 1].add *= x;
        t[v * 2 + 2].mul *= x;
        t[v * 2 + 2].sum *= x;
        t[v * 2 + 2].add *= x;
    }
    if(!eq(t[v].add, 0)) {
        ld x = t[v].add;
        t[v].add = 0;
        int m = (l + r) / 2;
        t[v * 2 + 1].sum += x * (m - l + 1);
        t[v * 2 + 1].add += x;
        t[v * 2 + 2].sum += x * (r - m);
        t[v * 2 + 2].add += x;
    }
}

void domul(int v, int l, int r, int l1, int r1, ld x) {
    if(r < l1 || r1 < l) return;
    if(l1 <= l && r <= r1) {
        t[v].sum *= x;
        t[v].mul *= x;
        t[v].add *= x;
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    domul(v * 2 + 1, l, m, l1, r1, x);
    domul(v * 2 + 2, m + 1, r, l1, r1, x);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void doadd(int v, int l, int r, int l1, int r1, ld x) {
    if(r < l1 || r1 < l) return;
    if(l1 <= l && r <= r1) {
        t[v].add += x;
        t[v].sum += x * (r - l + 1);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    doadd(v * 2 + 1, l, m, l1, r1, x);
    doadd(v * 2 + 2, m + 1, r, l1, r1, x);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

ld get(int v, int l, int r, int l1, int r1) {
    if(r < l1 || r1 < l) return 0;
    if(l1 <= l && r <= r1) return t[v].sum;
    push(v, l, r);
    int m = (l + r) / 2;
    return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m + 1, r, l1, r1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(7);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, 0, n - 1);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--; r1--; l2--; r2--;
            ld sum1 = get(0, 0, n - 1, l1, r1), sum2 = get(0, 0, n - 1, l2, r2);
            int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
            domul(0, 0, n - 1, l1, r1, 1.0 - 1.0 / len1);
            doadd(0, 0, n - 1, l1, r1, sum2 / len1 / len2);
            domul(0, 0, n - 1, l2, r2, 1.0 - 1.0 / len2);
            doadd(0, 0, n - 1, l2, r2, sum1 / len1 / len2);
        } else {
            int l, r; cin >> l >> r; l--; r--;
            cout << fixed << get(0, 0, n - 1, l, r) << '\n';
        }
    }
}