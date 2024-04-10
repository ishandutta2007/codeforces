#include <bits/stdc++.h>

using namespace std;

inline int max(const int& a, const int& b) {
    if (a > b) return a;
    else return b;
}

#define int long long
const int INF = 1e11;
vector <int> a;

struct vert {
    int mc, mn, pc, pn;
};

vector <vert> t;

inline vert merge(const vert& af, const vert& bf) {
    vert ans;
    ans.mc = max(af.mc, bf.mc);
    ans.mc = max(ans.mc, af.mc + bf.mc);
    ans.mc = max(ans.mc, af.mn + bf.pn);
    ans.mn = max(af.mn, bf.mn);
    ans.mn = max(ans.mn, af.mn + bf.pc);
    ans.mn = max(ans.mn, af.mc + bf.mn);
    ans.pc = max(af.pc, bf.pc);
    ans.pc = max(ans.pc, af.pc + bf.pc);
    ans.pc = max(ans.pc, af.pn + bf.mn);
    ans.pn = max(af.pn, bf.pn);
    ans.pn = max(ans.pn, af.pc + bf.pn);
    ans.pn = max(ans.pn, af.pn + bf.mc);
    return ans;
}

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = {-INF, -a[l], -INF, a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int i, int x) {
    if (l > i || i > r) return;
    if (l == r) {
        t[v] = {-INF, -x, -INF, x};
        return;
    }
    int m = (l + r) / 2;
    update(2 * v, l, m, i, x);
    update(2 * v + 1, m + 1, r, i, x);
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        int n, q;
        cin >> n >> q;
        int len = (1 << (int)ceil(log2(n)));
        a.assign(len, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];
        t.assign(2 * len, {});
        build(1, 0, len - 1);
        cout << max(max(t[1].mc, t[1].mn), max(t[1].pc, t[1].pn)) << "\n";
        while (q--) {
            int l, r;
            cin >> l >> r; --l; --r;
            update(1, 0, len - 1, l, a[r]);
            update(1, 0, len - 1, r, a[l]);
            swap(a[l], a[r]);
            cout << max(max(t[1].mc, t[1].mn), max(t[1].pc, t[1].pn)) << "\n";
        }
    }
}