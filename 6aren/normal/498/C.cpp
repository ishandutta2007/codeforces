#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define vi vector<int> 
#define oo 1000000000

struct Matching {
    int m, n;
    vector<vi> adj;
    vi match;
    vi dist;

    Matching(int _m, int _n) {
        m = _m, n = _n;
        match.resize(m + n + 1, 0);
        adj.resize(m + 1, {});
        dist.resize(m + 1, oo);
    }

    void addEdge(int u, int v) {
        // cout << u << ' ' << v << endl;
        adj[u].pb(v + m);
    }

    bool bfs() {
        queue<int> q;
        for (int i = 1; i <= m; i++) {
            if (!match[i]) {
                q.push(i);
                dist[i] = 0;
            } else {
                dist[i] = oo;
            }
        }

        bool found = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!match[v]) {
                    found = true;
                } else if (dist[match[v]] == oo) {
                    dist[match[v]] = dist[u] + 1;
                    q.push(match[v]);
                }
            }
        }
        
        return found;
    }

    bool dfs(int u) {
        if (dist[u] == oo) return false;
        for (int v : adj[u]) {
            if (!match[v] || (dist[match[v]] == dist[u] + 1 && dfs(match[v]))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        int ans = 0;
        while (bfs()) {
            for (int i = 1; i <= m; i++) {
                if (!match[i]) ans += dfs(i);
            }
        }
        return ans;
    }
};

const int N = 105;

int nn, mm;
vector<int> divs[N];
int a[N];
int pref[2][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> nn >> mm;
    for (int i = 1; i <= nn; i++) {
        cin >> a[i];
        for (int j = 2; j * j <= a[i]; j++) {
            while (a[i] % j == 0) {
                divs[i].pb(j);
                a[i] /= j;
            }
        }
        if (a[i] != 1) divs[i].pb(a[i]);
    }
    for (int i = 1; i <= nn; i++) {
        int ty = i % 2;
        int id = (i + 1) / 2;
        pref[ty][id] = pref[ty][id - 1] + divs[i].size();
    }
 
    Matching mat = Matching(pref[0][nn / 2], pref[1][(nn + 1) / 2]);
    
    for (int i = 1; i <= mm; i++) {
        int u, v;
        cin >> u >> v;
        if (u % 2 == 1) swap(u, v);
        int idu = (u + 1) / 2;
        int idv = (v + 1) / 2;
        for (int j = 0; j < divs[u].size(); j++) {
            for (int k = 0; k < divs[v].size(); k++) {
                if (divs[u][j] == divs[v][k]) mat.addEdge(pref[0][idu - 1] + j + 1, pref[1][idv - 1] + k + 1);
            }
        }
    }

    cout << mat.maxMatching();

    return 0;
}