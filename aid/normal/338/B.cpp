#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int s, vector< vector<int> > &g, vector<char> &p, vector<int> &d) {
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++)
            if(d[g[v][i]] == -1) {
                d[g[v][i]] = d[v] + 1;
                q.push(g[v][i]);
            }
    }
    int maxd = 0, res = s;
    for(size_t i = 0; i < d.size(); i++)
        if(p[i] && d[i] > maxd) {
            maxd = d[i];
            res = i;
        }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    vector<char> p(n);
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        k--;
        p[k] = true;
    }
    vector< vector<int> > g(n);
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    vector<int> da(n, -1), db(n, -1);
    int a = bfs(0, g, p, db), b = bfs(a, g, p, da);
    for(int i = 0; i < n; i++)
        db[i] = -1;
    bfs(b, g, p, db);
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(da[i] <= d && db[i] <= d)
            ans++;
    cout << ans << '\n';
}