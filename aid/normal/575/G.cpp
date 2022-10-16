#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>


using namespace std;

const int MAXN = 100 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
char z[MAXN], ok[MAXN];
int d[MAXN], dz[MAXN], pz[MAXN], par[MAXN];
vector< pair<int, int> > g[MAXN];
vector<int> p[MAXN];

void bfs0(int s, int n) {
    for(int i = 0; i < n; i++)
        dz[i] = INF;
    dz[s] = 0;
    z[s] = true;
    pz[s] = -1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++)
            if(!z[g[v][i].first] && g[v][i].second == 0) {
                z[g[v][i].first] = true;
                dz[g[v][i].first] = dz[v] + 1;
                pz[g[v][i].first] = v;
                q.push(g[v][i].first);
            }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
    }
    bfs0(n - 1, n);
    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        p[d[v]].push_back(v);
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++)
            if(d[v] + 1 < d[g[v][i].first]) {
                d[g[v][i].first] = d[v] + 1;
                q.push(g[v][i].first);
            }
    }
    int len = INF;
    for(int i = 0; i < n; i++)
        if(z[i])
            len = min(len, d[i]);
    for(int i = 0; i < n; i++)
        if(z[i] && d[i] == len)
            ok[i] = true;
    string ans;
    for(int i = len; i > 0; i--) {
        int dig = INF;
        for(size_t j = 0; j < p[i].size(); j++)
            if(ok[p[i][j]])
                for(size_t k = 0; k < g[p[i][j]].size(); k++)
                    if(d[g[p[i][j]][k].first] == d[p[i][j]] - 1)
                        dig = min(dig, g[p[i][j]][k].second);
        ans += char('0' + dig);
        for(size_t j = 0; j < p[i].size(); j++)
            if(ok[p[i][j]])
                for(size_t k = 0; k < g[p[i][j]].size(); k++)
                    if(d[g[p[i][j]][k].first] == d[p[i][j]] - 1 && 
                       dig == g[p[i][j]][k].second)
                        ok[g[p[i][j]][k].first] = true;
    }
    for(int i = 0; i < n; i++)
        ok[i] = false;
    ok[0] = true;
    par[0] = -1;
    for(int i = 0; i < len; i++)
        for(size_t j = 0; j < p[i].size(); j++)
            if(ok[p[i][j]])
                for(size_t k = 0; k < g[p[i][j]].size(); k++)
                    if(d[g[p[i][j]][k].first] == d[p[i][j]] + 1 &&
                       g[p[i][j]][k].second == ans[len - i - 1] - '0') {
                        ok[g[p[i][j]][k].first] = true;
                        par[g[p[i][j]][k].first] = p[i][j];
                    }
    int d0 = INF, v = 0;
    for(size_t i = 0; i < p[len].size(); i++)
        if(ok[p[len][i]] && dz[p[len][i]] < d0) {
            d0 = dz[p[len][i]];
            v = p[len][i];
        }
    vector<int> path;
    for(int u = v; u >= 0; u = par[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    for(int u = pz[v]; u >= 0; u = pz[u])
        path.push_back(u);
    if(ans.empty())
        cout << 0 << '\n';
    else
        cout << ans << '\n';
    cout << path.size() << '\n';
    for(size_t i = 0; i < path.size(); i++)
        cout << path[i] << ' ';
    cout << '\n';
    return 0;
}