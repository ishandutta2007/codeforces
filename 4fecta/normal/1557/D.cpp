// Problem: D. Ezzat and Grid
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 300005;

int n, m, row, l, r, dp[MN], bck[MN];
vector<pii> v[MN];
vector<int> xs;
map<int, int> mp;
pii st[MN * 12], lzy[MN * 12]; //min, id of min

pii push_up(pii x, pii y) {
    if (x.f < y.f) return x;
    else return y;
}

void push_down(int l, int r, int idx) {
    if (!lzy[idx].s) return;
    st[idx] = min(st[idx], lzy[idx]);
    if (l != r) lzy[idx * 2] = lzy[idx * 2 + 1] = min(lzy[idx * 2], lzy[idx]);
    lzy[idx] = {0, 0};
}

void build(int l, int r, int idx) {
    if (l == r) {
        st[idx] = {-1, 0};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

void upd(int l, int r, int x, int y, pii val, int idx) {
    push_down(l, r, idx);
    if (r < x || l > y) return;
    if (r <= y && l >= x) {
        lzy[idx] = val;
        push_down(l, r, idx);
        return;
    }
    int mid = (l + r) >> 1;
    upd(l, mid, x, y, val, idx * 2), upd(mid + 1, r, x, y, val, idx * 2 + 1);
    st[idx] = push_up(st[idx * 2], st[idx * 2 + 1]);
}

pii qry(int l, int r, int x, int y, int idx) {
    push_down(l, r, idx);
    if (r < x || l > y) return {0x3f3f3f3f, 0x3f3f3f3f};
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return push_up(qry(l, mid, x, y, idx * 2), qry(mid + 1, r, x, y, idx * 2 + 1));
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> row >> l >> r;
        xs.push_back(l);
        xs.push_back(r);
        v[row].push_back({l, r});
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < xs.size(); i++) mp[xs[i]] = i + 1;
    v[n + 1].push_back({xs[0], xs.back()});
    build(1, xs.size(), 1);
    for (int i = 1; i <= n + 1; i++) {
        pii val = {-1, 0};
        for (pii p : v[i]) {
            l = mp[p.f], r = mp[p.s];
            pii tmp = qry(1, xs.size(), l, r, 1);
            val = min(val, tmp);
        }
        dp[i] = val.f + i;
        bck[i] = val.s;
        for (pii p : v[i]) {
            l = mp[p.f], r = mp[p.s];
            upd(1, xs.size(), l, r, {dp[i] - i - 1, i}, 1);
        }
       /* sort(v[i].begin(), v[i].end());
        vector<pii> tmp;
        int l = 0, r = 0;
        for (pii p : v[i]) {
            if (p.f > r + 1) {
                if (l) tmp.push_back({l, r});
                l = p.f, r = p.s;
            } else r = max(r, p.s);
        }
        if (l) tmp.push_back({l, r});
        v[i] = tmp;*/
    }
    printf("%lld\n", dp[n + 1]);
    vector<int> out;
    int cur = n + 1;
    while (cur) {
        int pre = bck[cur];
        for (int i = pre + 1; i < cur; i++) out.push_back(i);
        cur = pre;
    }
    sort(out.begin(), out.end());
    for (int p : out) printf("%lld ", p);

    return 0;
}