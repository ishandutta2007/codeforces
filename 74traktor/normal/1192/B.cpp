#include<bits/stdc++.h>

using namespace std;

#define int long long

struct pt {
    int v, c, i;
};

int const maxn = 1e5 + 5, maxc = (1 << 20), logg = 20;
vector < pt > g[maxn];
int imax[2 * maxc], psh[4 * maxc];
multiset < int > ans;
multiset < int > best[maxn];
int sz[maxn], lst[maxn], oks[maxn], cur = 0, start[maxn];
pair < int, int > f[maxn][logg], go[maxn][logg];
int h[maxn], cost[maxn];
int good[maxn];
int MX = 0;

inline void push(int i) {
    imax[i] += psh[i];
    psh[2 * i + 1] += psh[i];
    psh[2 * i + 2] += psh[i];
    psh[i] = 0;
}

void add(int i, int l, int r, int lq, int rq, int x) {
    if (lq >= r || l >= rq) {
        push(i);
        return;
    }
    if (lq <= l && r <= rq) {
        psh[i] += x;
        push(i);
        return;
    }
    push(i);
    int m = (r + l) / 2;
    add(2 * i + 1, l, m, lq, rq, x);
    add(2 * i + 2, m, r, lq, rq, x);
    imax[i] = max(imax[2 * i + 1], imax[2 * i + 2]);
}

int get(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return 0;
    push(i);
    if (lq <= l && r <= rq) return imax[i];
    int m = (r + l) / 2;
    return max(get(2 * i + 1, l, m, lq, rq), get(2 * i + 2, m, r, lq, rq));
}

void build(int v, int p) {
    sz[v] = 1;
    for (auto u : g[v]) {
        if (u.v == p || oks[u.v]) continue;
        build(u.v, v);
        sz[v] += sz[u.v];
    }
}

void dfs1(int v, int p, int sum, int H) {
    int child = 0;
    MX = max(MX, sum);
    for (auto u : g[v]) {
        if (u.v == p || oks[u.v]) continue;
        child = 1;
        f[u.i][H].first = cur;
        dfs1(u.v, v, sum + u.c, H);
        f[u.i][H].second = cur - 1;
    }
    if (child == 0) {
        add(0, 0, maxc, cur, cur + 1, sum);
        cur++;
    }
}

void dfs2(int v, int p, int l, int r, int h) {
    for (auto u : g[v]) {
        if (oks[u.v] || u.v == p) continue;
        go[u.i][h] = {l, r};
        dfs2(u.v, v, l, r, h);
    }
}

void dfs(int v, int p) {
    build(v, -1);
    int N = sz[v], no = -1, find = 1;
    while (find) {
        find = 0;
        for (auto u : g[v]) {
            if (oks[u.v] || u.v == no) continue;
            if (sz[u.v] >= N / 2) {
                no = v, v = u.v, find = 1;
                break;
            }
        }
    }
    lst[v] = p;
    h[v] = h[p] + 1;
    for (auto u : g[v]) {
        if (oks[u.v]) continue;
        int lef = cur;
        f[u.i][h[v]].first = cur;
        MX = 0;
        dfs1(u.v, v, u.c, h[v]);
        f[u.i][h[v]].second = cur - 1;
        best[v].insert(MX);
        dfs2(u.v, v, lef, cur - 1, h[v]);
        go[u.i][h[v]] = {lef, cur - 1};
    }
    int answer = 0;
    if ((int)best[v].size() == 1) answer = (*best[v].rbegin());
    else if ((int)best[v].size() > 1) {
        answer = (*best[v].rbegin());
        int x = answer;
        best[v].erase(best[v].find(x));
        answer += (*best[v].rbegin());
        best[v].insert(x);
    }
    good[v] = answer;
    ans.insert(answer);
    oks[v] = 1;
    for (auto u : g[v]) {
        if (oks[u.v]) continue;
        start[u.i] = v;
        dfs(u.v, v);
    }
}

inline void update(int i, int c) {
    int s = c - cost[i];
    cost[i] = c;
    int v = start[i];
    while (v != 0) {
        int H = h[v];
        int was = get(0, 0, maxc, go[i][H].first, go[i][H].second + 1);
        add(0, 0, maxc, f[i][H].first, f[i][H].second + 1, s);
        int nxt = get(0, 0, maxc, go[i][H].first, go[i][H].second + 1);
        if (was != nxt) {
            best[v].erase(best[v].find(was));
            best[v].insert(nxt);
        }
        was = good[v];
        good[v] = 0;
        auto it = best[v].end();
        int cnt = 2;
        while (it != best[v].begin() && cnt--) {
            it--;
            good[v] += (*it);
        }
        if (was != good[v]) {
            ans.erase(ans.find(was));
            ans.insert(good[v]);
        }
        v = lst[v];
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, w, u, v, c, d, e, last = 0;
    cin >> n >> q >> w;
    //n = 100000, q = 100000, w = 100000;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v >> c;
        //u = i, v = i + 1, c = 1;
        cost[i] = c;
        g[u].push_back({v, c, i});
        g[v].push_back({u, c, i});
    }
    dfs(1, 0);
    /*MX = 0;
    for (int i = 1; i <= n; ++i) {
        u = i;
        int cnt = 0;
        while (u != 0) {
            cnt++;
            u = lst[u];
        }
        MX = max(MX, cnt);
    }*/
    //cout << MX << " " << cur << endl;
    for (int i = 1; i <= q; ++i) {
        cin >> d >> e;
        //d = rand(), e = rand();
        d = (d + last) % (n - 1) + 1, e = (e + last) % w;
        update(d, e);
        last = (*ans.rbegin());
        cout << last << '\n';
    }
    //cout << last << '\n';
    return 0;
}