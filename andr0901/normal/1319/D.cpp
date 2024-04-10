#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

vector <vector <int>> gr;

int n;

vector <int> bfs(int st) {
    vector <int> dst(n, 1e9);
    dst[st] = 0;
    deque <int> q = {st};
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (int u : gr[v])
            if (dst[v] + 1 < dst[u]) {
                dst[u] = dst[v] + 1;
                q.push_back(u);
            }
    }
    return dst;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> n >> m;
    gr.resize(n);
    vector <vector <int>> g(n);
    forn (i, 0, m) {
        int v, u;
        cin >> v >> u, --v, --u;
        gr[u].pb(v);
        g[v].pb(u);
    }
    int k;
    cin >> k;
    vector <int> path(k);
    forn (i, 0, k)
        cin >> path[i], --path[i];

    auto dst = bfs(path.back());
    map <int, int> cnt;
    for (int i : dst)
        cnt[i]++;

    int mn = 0, mx = 0;
    int prev = -1;
    for (int i : path) {
        if (prev == -1) {
            prev = i;
            continue;
        }

        if (dst[i] != dst[prev] - 1)
            mn++, mx++; 
        else {
            int cnt = 0;
            for (int u : g[prev]) {
                if (dst[u] == dst[i])
                    cnt++;
            }
            if (cnt > 1)
                mx++;
        }

        prev = i;
    }
    cout << mn << " " << mx;
    return 0;
}