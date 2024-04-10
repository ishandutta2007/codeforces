#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;


mt19937 gen(time(NULL));

vector <long long> t;
vector <long long> t1;

void build(int v, int vl, int vr, vector <int> &a) {
    if (vl == vr - 1) {
        t[v] = a[vl];
        t1[v] = a[vl];
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v + 1, vl, vm, a);
    build(2 * v + 2, vm, vr, a);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
}

long long get(int v, int vl, int vr, int l, int r) {
    if (vl == l && vr == r) {
        return t[v];
    }
    int vm = (vl + vr) / 2;
    if (r <= vm) {
        return get(2 * v + 1, vl, vm, l, r);
    }
    if (l >= vm) {
        return get(2 * v + 2, vm, vr, l, r);
    }
    return get(2 * v + 1, vl, vm, l, vm) + get(2 * v + 2, vm, vr, vm, r);
}

void mod1(int v, int vl, int vr, int ind, int x) {
    if (vl == vr - 1) {
        t[v] = x;
        t1[v] = x;
        return;
    }
    int vm = (vl + vr) / 2;
    if (ind < vm) {
        mod1(2 * v + 1, vl, vm, ind, x);
    }
    else {
        mod1(2 * v + 2, vm, vr, ind, x);
    }
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
}

void mod2(int v, int vl, int vr, int l, int r, int mod) {
    if (t1[v] < mod) {
        return;
    }
    if (vl == vr - 1) {
        t[v] = t[v] % mod;
        t1[v] = t1[v] % mod;
        return;
    }
    int vm = (vl + vr) / 2;
    if (r <= vm) {
        mod2(2 * v + 1, vl, vm, l, r, mod);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
        t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
        return;
    }
    if (l >= vm) {
        mod2(2 * v + 2, vm, vr, l, r, mod);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
        t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
        return;
    }
    mod2(2 * v + 1, vl, vm, l, vm, mod);
    mod2(2 * v + 2, vm, vr, vm, r, mod);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    t1[v] = max(t1[2 * v + 1], t1[2 * v + 2]);
}

int main() {
    //freopen("input.cpp", "r", stdin);
    //freopen("output.cpp", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    t.resize(4 * n);
    t1.resize(4 * n);
    vector <int> a(n);
    for (auto &c : a) {
        cin >> c;
    }
    build(0, 0, n, a);
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << get(0, 0, n, l - 1, r) << "\n";
        }
        if (type == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            mod2(0, 0, n, l - 1, r, x);
        }
        if (type == 3) {
            int k, x;
            cin >> k >> x;
            mod1(0, 0, n, k - 1, x);
        }
    }
    return 0;
}