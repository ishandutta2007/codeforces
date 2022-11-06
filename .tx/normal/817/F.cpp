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

struct query {
    int t;
    lint l, r;
};

query qs[111111];

struct SegmentTree {
    int* a;
    int* st;
    bool* ni;
    int n;

    SegmentTree(int n) : n(n) {
        a = new int[4 * n];
        st = new int[4 * n];
        ni = new bool[4 * n];
        fill(a, a + 4 * n, 0);
        fill(st, st + 4 * n, -1);
        fill(ni, ni + 4 * n, false);
    }

    void push(int i, int l, int r) {
        if (st[i] != -1) {
            a[i] = (r - l) * st[i];
            if (l + 1 != r) {
                st[i * 2 + 1] = st[i];
                ni[i * 2 + 1] = false;
                st[i * 2 + 2] = st[i];
                ni[i * 2 + 2] = false;
            }
            st[i] = -1;
        }
        if (ni[i]) {
            a[i] = r - l - a[i];
            if (l + 1 != r) {
                ni[i * 2 + 1] ^= true;
                ni[i * 2 + 2] ^= true;
            }
            ni[i] = false;
        }
    }

    void set(int i, int l, int r, int ql, int qr, int x, bool inv) {
        push(i, l, r);
        if (r <= ql || qr <= l) {
            return;
        }
        if (ql <= l && r <= qr) {
            st[i] = x;
            ni[i] = inv;
            push(i, l, r);
            return;
        }
        int m = (l + r) >> 1;
        set(i * 2 + 1, l, m, ql, qr, x, inv);
        set(i * 2 + 2, m, r, ql, qr, x, inv);
        a[i] = a[i * 2 + 1] + a[i * 2 + 2];
    }

    int lz(int i, int l, int r) {
        push(i, l, r);
        if (a[i] == r - l) {
            return - 1;
        }
        if (a[i] == 0) {
            return l;
        }
        int m = (l + r) >> 1;
        int res = lz(i * 2 + 1, l, m);
        if (res == -1) {
            res = lz(i * 2 + 2, m, r);
        }
        return res;
    }
};

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    vector<lint> xs;
    rep(i, 0, n) {
        cin >> qs[i].t >> qs[i].l >> qs[i].r;
        xs.push_back(qs[i].l - 1);
        xs.push_back(qs[i].r);
    }
    xs.push_back(0);
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    SegmentTree st(xs.size() + 3);
    rep(i, 0, n) {
        query q = qs[i];
        q.l = lower_bound(xs.begin(), xs.end(), q.l - 1) - xs.begin();
        q.r = lower_bound(xs.begin(), xs.end(), q.r) - xs.begin();
        if (q.t == 1) {
            st.set(0, 0, st.n, q.l, q.r, 1, false);
        } else if (q.t == 2) {
            st.set(0, 0, st.n, q.l, q.r, 0, false);
        } else {
            st.set(0, 0, st.n, q.l, q.r, -1, true);
        }
        cout << xs[st.lz(0, 0, st.n)] + 1 << "\n";
    }
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
}//grrvly