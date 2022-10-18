#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5, maxc = 2e7;
pair < int, int > a[maxn];
pair < int, int > b[maxn];
int c[maxn], ok = 0;
vector < pair < int, int > > ask_suff[maxn];
int N = 1e9 + 1;
int cur = 1;
int tree[maxc], nxt_l[maxc], nxt_r[maxc];

void update(int i, int l, int r, int lq, int rq) {
    if (r - l == 1) {
        tree[i] = max(tree[i], rq);
        return;
    }
    int m = (r + l) / 2;
    if (lq < m) {
        if (nxt_l[i] == 0) nxt_l[i] = cur++;
        update(nxt_l[i], l, m, lq, rq);
    }
    else {
        if (nxt_r[i] == 0) nxt_r[i] = cur++;
        update(nxt_r[i], m, r, lq, rq);
    }
    if (nxt_l[i] != 0) tree[i] = max(tree[i], tree[nxt_l[i]]);
    if (nxt_r[i] != 0) tree[i] = max(tree[i], tree[nxt_r[i]]);
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return 0;
    if (lq <= l && r <= rq) return tree[i];
    int m = (r + l) / 2, ans = 0;
    if (nxt_l[i] != 0) ans = max(ans, get(nxt_l[i], l, m, lq, rq));
    if (nxt_r[i] != 0) ans = max(ans, get(nxt_r[i], m, r, lq, rq));
    return ans;
}

void go(int n) {
    for (int i = 1; i <= n; ++i) c[i] = i, ask_suff[i] = {};
    for (int i = 0; i <= cur; ++i) tree[i] = 0, nxt_l[i] = 0, nxt_r[i] = 0;
    sort(c + 1, c + n + 1, [](int x, int y) {
        return a[x] < a[y];
    });
    for (int i = 1; i <= n; ++i) {
        int la = a[c[i]].first, ra = a[c[i]].second;
        int lef = i, righ = n + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (a[c[mid]].first > ra) righ = mid;
            else lef = mid;
        }
        if (righ == n + 1) continue;
        int lb = b[c[i]].first, rb = b[c[i]].second;
        ask_suff[righ].push_back({lb, rb});
    }
    set < int > Q;
    for (int i = n; i >= 1; --i) {
        update(0, 1, N, b[c[i]].first, b[c[i]].second);
        Q.insert(b[c[i]].first);
        Q.insert(b[c[i]].second);
        for (auto u : ask_suff[i]) {
            auto it = Q.lower_bound(u.first);
            if (it != Q.end() && (*it) <= u.second) ok = 1;
            if (get(0, 1, N, 1, u.first + 1) > u.second) ok = 1;
        }
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    go(n);
    for (int i = 1; i <= n; ++i) swap(a[i], b[i]);
    go(n);
    if (ok) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return 0;
}