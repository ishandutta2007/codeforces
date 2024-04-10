#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;

int c[N];
vector <int> g[N];
map <int, int> cnt[N];
ll sum[N];
int mx[N];
int sz[N];
int num[N];
ll ans[N];

void add(int v, int c, int s) {
    cnt[v][c] += s;
    if (cnt[v][c] > mx[v]) {
        sum[v] = c;
        mx[v] = cnt[v][c];
    } else if (cnt[v][c] == mx[v]) {
        sum[v] += c;
    }
}

void dfs(int v, int pr) {
    int res = -1;
    sz[v] = 1;
    for (auto to : g[v]) {
        if (to == pr) continue;
        dfs(to, v);
        sz[v] += sz[to];
        if (res == -1 || sz[to] > sz[res]) res = to;
    }
    if (res == -1) {
        num[v] = v;
        add(v, c[v], 1);
    } else {
        int w = res;
        res = num[res];
        num[v] = res;
        add(res, c[v], 1);
        for (auto to : g[v]) {
            if (to != pr && to != w) {
                for (auto c : cnt[num[to]]) {
                    add(res, c.first, c.second);
                }
            }
        }
    }
    ans[v] = sum[num[v]];
}


int main() {
    srand('M' + 'R' + '.' + 'D' + 'U' + 'D' + 'E' + 'C');
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #else
        //freopen("a.in", "r", stdin);
        //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}