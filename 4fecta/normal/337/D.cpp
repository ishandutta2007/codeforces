#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, m, d, u, v, st, in[MN], tree[MN], dist[MN], dist1[MN], ans[MN], p1, p2, mx, rad = 0x3f3f3f3f, c1, c2 = -1, lim;
vector<int> a[MN];
stack<int> s;

void dfs(int cur, int par) {
    s.push(cur);
    if (in[cur]) {
        while (s.size()) {
            tree[s.top()] = 1;
            s.pop();
        }
    }
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
    }
    if (s.size() && s.top() == cur) s.pop();
}

void dfs(int cur, int par, int d) {
    dist[cur] = d;
    for (int nxt : a[cur]) {
        if (nxt == par || !tree[nxt]) continue;
        dfs(nxt, cur, d + 1);
    }
}

void dfs1(int cur, int par, int d) {
    dist1[cur] = d;
    for (int nxt : a[cur]) {
        if (nxt == par || !tree[nxt]) continue;
        dfs1(nxt, cur, d + 1);
    }
}

void mark(int cur, int par, int d) {
    if (d > lim) return;
    ans[cur] = 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        mark(nxt, cur, d + 1);
    }
}

int main() {
    boost();

    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        cin >> u;
        in[u] = 1;
        st = u;
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(st, 0);
    dfs(st, 0, 0);
    mx = -1;
    for (int i = 1; i <= n; i++) {
        if (!tree[i]) continue;
        if (dist[i] > mx) mx = dist[i], p1 = i;
    }
    dfs(p1, 0, 0);
    mx = -1;
    for (int i = 1; i <= n; i++) {
        if (!tree[i]) continue;
        if (dist[i] > mx) mx = dist[i], p2 = i;
    }
    dfs1(p2, 0, 0);
    for (int i = 1; i <= n; i++) {
        if (!tree[i]) continue;
        //printf("%d %d\n", dist[i], dist1[i]);
        if (max(dist[i], dist1[i]) < rad) {
            rad = max(dist[i], dist1[i]);
            c1 = i;
            c2 = -1;
        } else if (max(dist[i], dist1[i]) == rad) {
            c2 = i;
        }
    }
    //printf("\n%d\n", rad);
    //printf("%d %d %d %d\n", p1, p2, c1, c2);
    lim = d - rad;
    mark(c1, 0, 0);
    if (c2 != -1) mark(c2, 0, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += ans[i];
    printf("%d\n", cnt);

    return 0;
}