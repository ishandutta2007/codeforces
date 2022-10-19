// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

int gcd(int x, int y) {
    while (x) {
        y %= x;
        swap(x, y);
    }
    return y;
}

const int M = 500500;

int n;
int t[4 * M];
int a[M];
int m;
int curv[M], curl[M], curr[M];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
}

void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m, r);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int l, int r, int at) {
    if (l + 1 == r) {
        assert(l == at);
        t[v] = a[at];
        return;
    }
    int m = (l + r) / 2;
    if (at < m)
        upd(2 * v, l, m, at);
    else
        upd(2 * v + 1, m, r, at);
    t[v] = gcd(t[2 * v], t[2 * v + 1]);
}

bool req(int v, int l, int r, int x) {
    if (l + 1 == r)
        return true;
    int m = (l + r) / 2;
    if (t[2 * v] % x == 0) {
        return req(2 * v + 1, m, r, x);
    }
    if (t[2 * v + 1] % x == 0) {
        return req(2 * v, l, m, x);
    }
    return false;
}

bool was = false;

bool chop(int v, int le, int re, int l, int r, int x) {
    if (le == l && r == re) {
        if (t[v] % x == 0)
            return true;
        if (was)
            return false;
        was = true;
        return req(v, le, re, x);
    }
    int me = (le + re) / 2;
    bool ans = true;
    if (l < me)
        ans &= chop(2 * v, le, me, l, min(r, me), x);
    if (me < r)
        ans &= chop(2 * v + 1, me, re, max(l, me), r, x);
    return ans;
}

void kill() {
    build(1, 0, n);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            --l;

            was = false;
            bool ans = chop(1, 0, n, l, r, x);
            cout << (ans ? "YES\n" : "NO\n");
        }

        if (type == 2) {
            int i, x;
            scanf("%d%d", &i, &x);
            --i;
            a[i] = x;
            upd(1, 0, n, i);
        }
    }
}

int main() {
#ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    read();
    kill();

    return 0;
}