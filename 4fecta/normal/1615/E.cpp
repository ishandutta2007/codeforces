#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, k, u, v, lzy[MN * 8], in[MN * 8], out[MN * 8], rev[MN * 8], tim = 1, lvs, pre[MN * 8], vis[MN * 8];
pii seg[MN * 8];
vector<int> a[MN * 8];

void build(int l, int r, int idx) {
    if (l == r) {seg[idx].s = l; return;}
    int mid = (l + r) >> 1;
    build(l, mid, idx * 2), build(mid + 1, r, idx * 2 + 1);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

void push_down(int idx, int l, int r) {
    if (!lzy[idx]) return;
    seg[idx].f += lzy[idx];
    if (l != r) lzy[idx * 2] += lzy[idx], lzy[idx * 2 + 1] += lzy[idx];
    lzy[idx] = 0;
}

void upd(int l, int r, int x, int y, ll amt, int idx) {
    push_down(idx, l, r);
    if (r < x || l > y) return;
    if (r <= y && l >= x) {
        lzy[idx] += amt;
        push_down(idx, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    upd(l, mid, x, y, amt, idx * 2), upd(mid + 1, r, x, y, amt, idx * 2 + 1);
    seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
}

void dfs(int cur, int par) {
    pre[cur] = par;
    in[cur] = tim;
    rev[tim++] = cur;
    for (int nxt : a[cur]) if (nxt != par) dfs(nxt, cur);
    out[cur] = tim;
    rev[tim++] = cur;
    if (in[cur] + 1 == out[cur]) lvs++;
}

int32_t main() {
    boost();

    cin >> n >> k;
    int K = k;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    build(1, n * 2, 1);
    for (int i = 1; i <= n; i++) upd(1, n * 2, in[i], out[i], 1, 1);
    while (k--) {
        push_down(1, 1, n * 2);
        pii tmp = seg[1];
        int cur = rev[tmp.s];
        while (cur && !vis[cur]) {
            upd(1, n * 2, in[cur], out[cur], -1, 1);
            vis[cur] = 1;
            cur = pre[cur];
        }
    }
    int blue = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) blue++;
    assert(tim - 1 == 2 * n);
    if (K >= lvs) assert(blue == 0);
    int red = K;
    while (red > lvs && red > n / 2) red--;
    if (blue) {
        int best = LLONG_MAX, id = blue;
        for (int i = 0; i <= blue; i++) {
            if ((n - i - red) * (red - i) < best) {
                best = (n - i - red) * (red - i);
                id = i;
            }
        }
        blue = id;
    }
    /*if (blue) {
        red = K;
    } else if (lvs <= n / 2) {
        while (red > n / 2) red--;
    } else {
        red = lvs;
    }*/
   // printf("%lld %lld\n", red, blue);
    printf("%lld\n", (n - blue - red) * (red - blue));

    return 0;
}