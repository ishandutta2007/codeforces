#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
vector< pair<int, int> > e, ep;
vector<int> g[MAXN];

void dfs(int v) {
    while(!g[v].empty()) {
        int id = g[v].back(),
            u = (e[id].first == v? e[id].second : e[id].first);
        g[v].pop_back();
        if(u == -1)
            continue;
        e[id] = make_pair(-1, -1);
        dfs(u);
        if(ep.size() & 1)
            ep.push_back(make_pair(v, u));
        else
            ep.push_back(make_pair(u, v));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(e.size());
        g[u].push_back(e.size());
        e.push_back(make_pair(v, u));
    }
    int lastv = -1;
    for(int i = 0; i < n; i++)
        if(g[i].size() & 1) {
            if(lastv == -1)
                lastv = i;
            else {
                g[i].push_back(e.size());
                g[lastv].push_back(e.size());
                e.push_back(make_pair(lastv, i));
                lastv = -1;
            }
        }
    dfs(0);
    if(ep.size() & 1)
        ep.push_back(make_pair(0, 0));
    cout << ep.size() << '\n';
    for(size_t i = 0; i < ep.size(); i++)
        cout << ep[i].first + 1 << ' ' << ep[i].second + 1 << '\n';
    return 0;
}