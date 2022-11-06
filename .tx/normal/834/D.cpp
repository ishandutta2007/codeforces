#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

struct STree {
    int s;
    STree *l, *r;

    STree(int s, STree *l, STree *r) : s(s), l(l), r(r) {}
};

int get_s(STree* t, int l, int r, int ql, int qr) {
    if (!t || r <= ql || qr <= l) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return t->s;
    }

    int m = (l + r) >> 1;
    return get_s(t->l, l, m, ql, qr) + get_s(t->r, m, r, ql, qr);
}

STree* set_v(STree* t, int l, int r, int qi, int qx) {
    if (l + 1 == r) {
        return new STree(qx, 0, 0);
    }
    int m = (l + r) >> 1;
    STree* res = new STree(0, t ? t->l : 0, t ? t->r : 0);
    if (qi < m) {
        res->l = set_v(res->l, l, m, qi, qx);
    } else {
        res->r = set_v(res->r, m, r, qi, qx);
    }
    res->s = (res->l ? res->l->s : 0) + (res->r ? res->r->s : 0);
    return res;
}

int n, k;
int d[55][44444];
int a[44444];
int nxt[44444];
int prv[44444];
int lst[44444];
STree* ts[44444];

int cnt_distinct(int l, int r) {
    return get_s(ts[r], 0, n + 1, l, n + 1);
}

void go(int k, int l, int r, int al, int ar) {
    if (l > r) {
        return;
    }
    int m = (l + r) >> 1;
    int o = min(m, ar);
    int cd = cnt_distinct(o, m);
    d[k][m] = cd + d[k - 1][o - 1];
    for (int i = o - 1; i >= al; i--) {
        if (nxt[i] == -1 || nxt[i] > m) {
            cd++;
        }
        if (cd + d[k - 1][i - 1] > d[k][m]) {
            d[k][m] = cd + d[k - 1][i - 1];
            o = i;
        }
    }
    go(k, l, m - 1, al, o);
    go(k, m + 1, r, o, ar);
}

void solve(istream& cin, ostream& cout) {
    cin >> n >> k;
    memset(lst, -1, sizeof(lst));
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(prv));
    rep(i, 1, n + 1) {
        cin >> a[i];
        if (lst[a[i]] != -1) {
            nxt[lst[a[i]]] = i;
            prv[i] = lst[a[i]];
        }
        lst[a[i]] = i;
    }

    rep(i, 1, n + 1) {
        ts[i] = set_v(ts[i - 1], 0, n + 1, i, 1);
        if (prv[i] != -1) {
            ts[i] = set_v(ts[i], 0, n + 1, prv[i], 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        d[1][i] = d[1][i - 1];
        if (prv[i] == -1) {
            d[1][i]++;
        }
    }

    for (int i = 2; i <= k; i++) {
        go(i, i, n, i, n);
    }

//    rep(i, 1, k + 1) {
//        rep(j, 1, n + 1) {
//            cout << d[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << d[k][n];
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//ddlori