#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto csz = [](const auto& c) { return int(c.size());};

mt19937 rng((size_t) make_shared<char>().get());

const int N = 4e6;

int v[N];
int y[N];
int l[N];
int r[N];
int s[N];
int sz[N];
int tsz = 1;

int make_treap(int v) {
    ::v[tsz] = v;
    y[tsz] = rng();
    s[tsz] = v;
    sz[tsz] = 1;
    return tsz++;
}

int make_copy(int t) {
    v[tsz] = v[t];
    y[tsz] = y[t];
    s[tsz] = s[t];
    sz[tsz] = sz[t];
    l[tsz] = l[t];
    r[tsz] = r[t];
    return tsz++;
}

int getSz(int t) {
    return t ? sz[t] : 0;
}

int getS(int t) {
    return t ? s[t] : 0;
}

void recalc(int t) {
    if (t) {
        sz[t] = getSz(l[t]) + getSz(r[t]) + 1;
        s[t] = getS(l[t]) + getS(r[t]) + v[t];
    }
}

pair<int, int> split(int t, int k) {
    if (!t) {
        return {0, 0};
    }

    int ql = getSz(l[t]);
    pair<int, int> s;
    t = make_copy(t);
    if (k <= ql) {
        s = split(l[t], k);
        l[t] = s.second;
        s.second = t;
    } else {
        s = split(r[t], k - ql - 1);
        r[t] = s.first;
        s.first = t;
    }
    recalc(t);
    return s;
}

int merge(int a, int b) {
    if (!a || !b) {
        return a ? a : b;
    }
    int t;
    if (y[a] < y[b]) {
        t = make_copy(a);
        r[t] = merge(r[t], b);
    } else {
        t = make_copy(b);
        l[t] = merge(a, l[t]);
    }
    recalc(t);
    return t;
}

int sset(int t, int k, int x) {
    t = make_copy(t);
    int ql = getSz(l[t]);
    if (k == ql) {
        v[t] = x;
    } else if (k < ql) {
        l[t] = sset(l[t], k, x);
    } else {
        r[t] = sset(r[t], k - ql - 1, x);
    }
    recalc(t);
    return t;
}

int findS(int t, int ql, int qr) {
    if (!t || ql >= qr) {
        return 0;
    }
    if (ql == 0 && qr == sz[t]) {
        return s[t];
    }
    int m = getSz(l[t]);
    int res = findS(l[t], ql, min(m, qr)) + findS(r[t], max(0, ql - m - 1), qr - m - 1);
    if (ql <= m && m < qr) {
        res += v[t];
    }
    return res;
}

int main() {
#ifdef VSE
    freopen("input.txt", "r", stdin);
    rng.seed(0);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<queue<int>> z(111111);
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t[i] = merge((i ? t[i - 1] : 0), make_treap(1));
        z[x].push(i);
        if (csz(z[x]) > k) {
            t[i] = sset(t[i], z[x].front(), 0);
            z[x].pop();
        }
    }

    int q;
    cin >> q;
    int last = 0;
    for (int iq = 0; iq < q; iq++) {
        int x, y;
        cin >> x >> y;
        int l = (x + last) % n;
        int r = (y + last) % n;
        if (l > r) {
            swap(l, r);
        }
//        auto a = split(t[r], l);
//        cout << (last = getS(a.second)) << "\n";
        last = findS(t[r], l, r + 1);
        cout << last << "\n";
    }

    return 0;
}