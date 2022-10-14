#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

vector<pii> t; /// (, - )
vector<int> tadd;
vector<int> cnt; /// - 

void build(int v, int vl, int vr, vector<int> &b) {
    if (vr - vl == 1) {
        if (b[vl] == INF) cnt[v] = 1;
        t[v] = {b[vl], vl};
        return;
    }
    int vm = (vl + vr) / 2;
    build(2 * v + 1, vl, vm, b);
    build(2 * v + 2, vm, vr, b);
    cnt[v] = cnt[2 * v + 1] + cnt[2 * v + 2];
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

void mod(int v, int vl, int vr, int l, int r, int d) {
    if (r <= vl || l >= vr) return;
    if (vl >= l && vr <= r) {
        tadd[v] += d;
        return;
    }
    int vm = (vl + vr) / 2;
    mod(2 * v + 1, vl, vm, l, r, d);
    mod(2 * v + 2, vm, vr, l, r, d);
    t[v] = min(make_pair(t[2 * v + 1].fi + tadd[2 * v + 1], t[2 * v + 1].se), make_pair(t[2 * v + 2].fi + tadd[2 * v + 2], t[2 * v + 2].se));
}

void push(int v, int vl, int vr) {
    if (vr - vl == 1) {
        t[v].fi += tadd[v];
        tadd[v] = 0;
        return;
    }
    t[v].fi += tadd[v];
    tadd[2 * v + 1] += tadd[v];
    tadd[2 * v + 2] += tadd[v];
    tadd[v] = 0;
}

pii get(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (r <= vl || l >= vr) return {INF, INF};
    if (vl >= l && vr <= r) return t[v];
    int vm = (vl + vr) / 2;
    return min(get(2 * v + 1, vl, vm, l, r), get(2 * v + 2, vm, vr, l, r));
}

void mod1(int v, int vl, int vr, int pos) {
    if (vr - vl == 1) {
        cnt[v] = 1;
        t[v] = {INF, INF};
        return;
    }
    int vm = (vl + vr) / 2;
    if (pos < vm) mod1(2 * v + 1, vl, vm, pos);
    else mod1(2 * v + 2, vm, vr, pos);
    cnt[v] = cnt[2 * v + 1] + cnt[2 * v + 2];
    t[v] = min(make_pair(t[2 * v + 1].fi + tadd[2 * v + 1], t[2 * v + 1].se), make_pair(t[2 * v + 2].fi + tadd[2 * v + 2], t[2 * v + 2].se));
}

int get1(int v, int vl, int vr, int l, int r) {
    if (r <= vl || l >= vr) return 0;
    if (vl >= l && vr <= r) return cnt[v];
    int vm = (vl + vr) / 2;
    return get1(2 * v + 1, vl, vm, l, r) + get1(2 * v + 2, vm, vr, l, r);
}

struct query{
    int x, y, ind;
    bool operator< (const query &q) {
        return x < q.x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &c : a) {
        cin >> c; c--;
    }
    vector<query> l(q);
    for (int i = 0; i < q; i++) {
        cin >> l[i].x >> l[i].y;
        l[i].ind = i;
    }
    sort(all(l));
    t.resize(4 * n);
    tadd.resize(4 * n);
    cnt.resize(4 * n);
    int cur = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (i - a[i] < 0) {
            b[i] = INF;
            continue;
        }
        if (cur >= i - a[i]) {
            b[i] = cur - (i - a[i]);
            cur++;
        } else b[i] = INF;
    }
    build(0, 0, n, b);
    int pr = -1;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        while (pr + 1 < l[i].x) {
            pr++;
            if (b[pr] == INF) continue;
            mod(0, 0, n, pr + 1, n, -1);
            mod1(0, 0, n, pr);
        }
        auto tmp = get(0, 0, n, 0, n);
        while (tmp.fi < 0) {
            b[tmp.se] = INF;
            mod1(0, 0, n, tmp.se);
            if (tmp.se + 1 < n) mod(0, 0, n, tmp.se + 1, n, -1);
            tmp = get(0, 0, n, 0, n);
        }
        ans[l[i].ind] = (n - get1(0, 0, n, 0, n)) - (l[i].y == 0 ? 0 : l[i].y - get1(0, 0, n, n - l[i].y, n));
    }
    for (auto &c : ans) cout << c << "\n";
    return 0;
}