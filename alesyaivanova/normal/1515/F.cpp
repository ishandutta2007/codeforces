#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 3e5 + 9;
int n, m, x;
vector<pii> g[maxn];
int w[maxn];
int p[maxn];
int sz[maxn];

int find_p(int i) {
    if (p[i] != i)
        p[i] = find_p(p[i]);
    return p[i];
}

void merg(int i, int e) {
    i = find_p(i);
    e = find_p(e);
    if (i == e)
        return;
    if (sz[i] < sz[e]) {
        swap(i, e);
    }
    p[e] = i;
    sz[i] += sz[e];
    w[i] += w[e];
    for (pii to : g[e])
        g[i].pb(to);
    g[e] = {};
}

void solve() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b, i);
        g[b].pb(a, i);
    }
    int cnt = n;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        int v = find_p(i);
        while (cnt >= 2 && w[v] >= x && !g[v].empty()) {
            pii to = g[v].back();
            g[v].pop_back();
            to.ff = find_p(to.ff);
            if (to.ff == v)
                continue;
            ans.pb(to.ss);
            w[v] -= x;
            merg(v, to.ff);
            v = find_p(v);
            cnt--;
        }
    }
    for (int i = 0; i < n; i++) {
        int v = find_p(i);
        while (cnt >= 2 && !g[v].empty()) {
            pii to = g[v].back();
            g[v].pop_back();
            to.ff = find_p(to.ff);
            if (to.ff == v)
                continue;
            if (w[to.ff] + w[v] < x) {
                cout << "NO\n";
                return;
            }
            ans.pb(to.ss);
            w[v] -= x;
            merg(v, to.ff);
            v = find_p(v);
            cnt--;
        }
    }
    if (cnt == 1) {
        cout << "YES\n";
        for (int i : ans) {
            cout << i + 1 << "\n";
        }
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}