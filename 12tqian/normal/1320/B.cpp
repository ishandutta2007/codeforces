#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#ifdef LOCAL
#define dbg(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define dbg(...) 17;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) { bool f = true; os << "{"; for (const auto &x : c) { if (!f) os << ", "; f = false; os << x; } return os << "}"; }
template<typename T> void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template<typename T, typename... Args> void debug(string s, T x, Args... args) { cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> go(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        go[u].push_back(v);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> dist(n, 0);
    vector<bool> vis(n, false);
    list<int> que;
    que.push_back(p.back());
    vis[p.back()] = true;
    while (!que.empty()) {
        int src = que.front();
        que.pop_front();
        for (int nxt : adj[src]) {
            if (vis[nxt]) {
                continue;
            }
            que.push_back(nxt);
            vis[nxt] = true;
            dist[nxt] = dist[src] + 1;
        }
    }
    vector<int> good(n);
    for (int i = 0; i < n; i++) { 
        for (int nxt: go[i]) {
            if (dist[nxt] == dist[i] - 1) {
                good[i]++;
            }
        }
    }
    int mn = 0;
    int mx = 0;
    for (int i = 0; i < k - 1; i++) {
        if (dist[p[i]] - 1 != dist[p[i + 1]]) {
            mn++;
            mx++;
        } else if (good[p[i]] > 1) {
            mx++;
        }
    }
    cout << mn << " " << mx << "\n";
}