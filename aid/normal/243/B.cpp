#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char used[MAXN];
vector<int> g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, h, t;
    cin >> n >> m >> h >> t;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int v = 0; v < n; v++) {
        if((int)g[v].size() < h + 1)
            continue;
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if((int)g[u].size() < h + t + 1)
                continue;
            cout << "YES\n" << v + 1 << ' ' << u + 1 << '\n';
            for(size_t j = 0, jj = 0; jj < h; j++)
                if(g[v][j] != u) {
                    cout << g[v][j] + 1 << ' ';
                    used[g[v][j]] = true;
                    jj++;
                }
            cout << '\n';
            for(size_t j = 0, jj = 0; jj < t; j++)
                if(g[u][j] != v && !used[g[u][j]]) {
                    cout << g[u][j] + 1 << ' ';
                    jj++;
                }
            return 0;
        }
    }
    for(int v = 0; v < n; v++) {
        if((int)g[v].size() < h + t + 1)
            continue;
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if((int)g[u].size() < t + 1)
                continue;
            cout << "YES\n" << v + 1 << ' ' << u + 1 << '\n';
            for(size_t j = 0, jj = 0; jj < t; j++)
                if(g[u][j] != v) {
                    used[g[u][j]] = true;
                    jj++;
                }
            for(size_t j = 0, jj = 0; jj < h; j++)
                if(g[v][j] != u && !used[g[v][j]]) {
                    cout << g[v][j] + 1 << ' ';
                    jj++;
                }
            cout << '\n';
            for(size_t j = 0, jj = 0; jj < t; j++)
                if(used[g[u][j]]) {
                    cout << g[u][j] + 1 << ' ';
                    jj++;
                }
            return 0;
        }
    }
    for(int v = 0; v < n; v++) {
        if((int)g[v].size() < h + 1)
            continue;
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if((int)g[u].size() < t + 1)
                continue;
            for(size_t j = 0; j < g[v].size(); j++)
                if(g[v][j] != u)
                    used[g[v][j]]++;
            for(size_t j = 0; j < g[u].size(); j++)
                if(g[u][j] != v)
                    used[g[u][j]]++;
            vector<int> hh, tt;
            for(size_t j = 0; j < g[v].size() && hh.size() < h; j++)
                if(used[g[v][j]] == 1)
                    hh.push_back(g[v][j]);
            for(size_t j = 0; j < g[v].size() && hh.size() < h; j++)
                if(used[g[v][j]] == 2) {
                    hh.push_back(g[v][j]);
                    used[g[v][j]]++;
                }
            for(size_t j = 0; j < g[u].size() && tt.size() < t; j++)
                if(used[g[u][j]] == 1)
                    tt.push_back(g[u][j]);
            for(size_t j = 0; j < g[u].size() && tt.size() < t; j++)
                if(used[g[u][j]] == 2)
                    tt.push_back(g[u][j]);
            for(size_t j = 0; j < g[v].size(); j++)
                used[g[v][j]] = 0;
            for(size_t j = 0; j < g[u].size(); j++)
                used[g[u][j]] = 0;
            if(tt.size() < t)
                continue;
            cout << "YES\n" << v + 1 << ' ' << u + 1 << '\n';
            for(size_t j = 0; j < hh.size(); j++)
                cout << hh[j] + 1 << ' ';
            cout << '\n';
            for(size_t j = 0; j < tt.size(); j++)
                cout << tt[j] + 1 << ' ';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}