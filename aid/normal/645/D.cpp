#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100 * 1000 + 5;
pair<int, int> e[MAXN];
int deg[MAXN];
vector<int> g[MAXN];

bool solve(int n, int m) {
    for(int i = 0; i < n; i++) {
        g[i].clear();
        deg[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        g[e[i].first].push_back(e[i].second);
        deg[e[i].second]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(!deg[i])
            q.push(i);
    while(!q.empty()) {
        if(q.size() > 1)
            return false;
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++) {
            deg[g[v][i]]--;
            if(!deg[g[v][i]])
                q.push(g[v][i]);
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].first >> e[i].second;
        e[i].first--;
        e[i].second--;
    }
    int l = 0, r = m;
    while(l < r - 1) {
        int mm = (l + r) / 2;
        if(solve(n, mm))
            r = mm;
        else
            l = mm;
    }
    if(!solve(n, r))
        cout << -1 << '\n';
    else
        cout << r << '\n';
    return 0;
}