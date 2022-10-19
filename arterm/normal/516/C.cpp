#include <bits/stdc++.h>

using namespace std;

#define M 900800
#define long long long
#define INF 100000000ll

struct Data {
    long ans;
    long mx, mi;
} tree[M];

Data comb(const Data &l, const Data &r) {
    Data ans;
    ans.mx = max(l.mx, r.mx);
    ans.mi = min(l.mi, r.mi);
    ans.ans = max(r.mx - l.mi, max(l.ans, r.ans));
    return ans;
}

int n, m;
long h[M], d[M];

void read() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> d[i + 1];

    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < n; ++i) {
        h[i + n] = h[i];
        d[i + n + 1] = d[i + 1];
    }
    for (int i = 1; i < 2 * n; ++i)
        d[i] += d[i - 1];

    //for (int i = 0; i < 2 * n; ++i)
    //  cerr << i << ": " << d[i] << ", " << h[i] << "\n";
}

void build(int v, int l, int r) {
    if (r - l == 1) {
        tree[v].mx = 2 * h[l] + d[l];
        tree[v].mi = -2 * h[l] + d[l];
        tree[v].ans = -INF;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    tree[v] = comb(tree[2 * v], tree[2 * v + 1]);
}

Data get(int v, int l, int r, int le, int re) {
    if (l == le && r == re)
        return tree[v];
    int m = (l + r) / 2;
    if (re <= m)
        return get(2 * v, l, m, le, re);
    if (m <= le)
        return get(2 * v + 1, m, r, le, re);
    return comb(get(2 * v, l, m, le, m), get(2 * v + 1, m, r, m, re));
}

void kill() {
    build(1, 0, 2 * n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        Data ans;
        cin >> a >> b;
        --a, --b;
        if (b < a)
            ans = get(1, 0, 2 * n, b + 1, a);
        else
            ans = get(1, 0, 2 * n, b + 1, a + n);
        cout << ans.ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    kill();
    return 0;
}