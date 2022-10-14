#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

struct vertex{
    int ans = 0, sz = 0, lenl = 0, lenr = 0, typel = 0, typer = 0;
    vertex(){}
};

vector<vertex> t, trev;
vector<int> f;

vertex merge(vertex left, vertex right) {
    if (left.sz == 0) return right;
    if (right.sz == 0) return left;
    vertex res;
    res.sz = left.sz + right.sz;
    res.typel = left.typel;
    res.typer = right.typer;
    res.lenl = left.lenl;
    res.lenr = right.lenr;
    if (left.lenl == left.sz && !(left.typer == 0 && right.typel == 1)) res.lenl = left.sz + right.lenl;
    if (right.lenr == right.sz && !(left.typer == 0 && right.typel == 1)) res.lenr = right.sz + left.lenr;
    res.ans = max({left.ans, right.ans, res.lenl, res.lenr});
    if (!(left.typer == 0 && right.typel == 1)) res.ans = max(res.ans, left.lenr + right.lenl);
    return res;
}

void build(int v, int vl, int vr, string &s) {
    if (vr - vl == 1) {
        t[v].lenl = t[v].lenr = trev[v].lenl = trev[v].lenr = t[v].ans = trev[v].ans = t[v].sz = trev[v].sz = 1;
        if (s[vl] == '<') trev[v].typel = trev[v].typer = 1;
        else t[v].typel = t[v].typer = 1;
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v + 1, vl, vm, s);
    build(2 * v + 2, vm, vr, s);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    trev[v] = merge(trev[2 * v + 1], trev[2 * v + 2]);
}

void push(int v, int vl, int vr) {
    if (f[v] == 0) return;
    if (vr - vl != 1) {
        f[2 * v + 1] ^= 1;
        f[2 * v + 2] ^= 1;
    }
    f[v] = 0;
    swap(t[v], trev[v]);
}

void modify(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (vr <= l || vl >= r) return;
    if (vl >= l && vr <= r) {
        f[v] ^= 1;
        push(v, vl, vr);
        return;
    }
    int vm = (vl + vr) / 2;
    modify(2 * v + 1, vl, vm, l, r);
    modify(2 * v + 2, vm, vr, l, r);
    t[v] = merge(t[2 * v + 1], t[2 * v + 2]);
    trev[v] = merge(trev[2 * v + 1], trev[2 * v + 2]);
}

vertex get(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (r <= vl || l >= vr) return vertex();
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) / 2;
    return merge(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    t.resize(4 * n);
    trev.resize(4 * n);
    f.resize(4 * n);
    build(0, 0, n, s);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        modify(0, 0, n, l, r);
        vertex res = get(0, 0, n, l, r);
        cout << res.ans << "\n";
    }
    return 0;
}