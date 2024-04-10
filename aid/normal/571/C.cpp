#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200 * 1000 + 5;
char ans[MAXN], used[MAXN], b[MAXN];
vector< pair<int, char> > c[MAXN];
vector< pair<int, pair<int, char> > > g[MAXN];

int dfs(int v, int p) {
    used[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second.first;
        if(used[u]) {
            if(id == p)
                continue;
            return v;
        }
        else {
            int res = dfs(u, id);
            if(res >= 0)
                return res;
        }
    }
    return -1;
}

void dfs0(int v) {
    used[v] = 2;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first, id = g[v][i].second.first;
        char val = g[v][i].second.second;
        if(!b[id]) {
            ans[id] = val;
            b[id] = true;
        }
        if(used[u] < 2)
            dfs0(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int v;
            cin >> v;
            if(v > 0) {
                v--;
                c[v].push_back(make_pair(i, true));
            }
            else {
                v = -v;
                v--;
                c[v].push_back(make_pair(i, false));
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(c[i].empty())
            continue;
        if(c[i].size() == 1 || c[i][0].second == c[i][1].second)
            for(size_t j = 0; j < c[i].size(); j++)
                g[c[i][j].first].push_back(make_pair(c[i][j].first,
                                                     make_pair(i, c[i][j].second)));
        else {
            g[c[i][0].first].push_back(make_pair(c[i][1].first,
                                                 make_pair(i, c[i][1].second)));
            g[c[i][1].first].push_back(make_pair(c[i][0].first,
                                                 make_pair(i, c[i][0].second)));
        }
    }
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            int v = dfs(i, -1);
            if(v == -1) {
                cout << "NO\n";
                return 0;
            }
            dfs0(v);
        }
    cout << "YES\n";
    for(int i = 0; i < m; i++)
        cout << (int)ans[i];
    cout << '\n';
    return 0;
}