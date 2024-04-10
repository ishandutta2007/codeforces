#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char used[MAXN], col[MAXN];
vector< pair<int, char> > g[MAXN];

pair<int, int> dfs(int v) {
    used[v] = 1;
    pair<int, int> res = make_pair(col[v], 1);
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first;
        char c = g[v][i].second;
        if(!used[u]) {
            if(c == 'B')
                col[u] = col[v];
            else
                col[u] = (col[v] ^ 1);
            pair<int, int> p = dfs(u);
            if(p.first == -1)
                return make_pair(-1, -1);
            res.first += p.first;
            res.second += p.second;
        }
        else {
            if(c == 'B') {
                if(col[u] != col[v])
                    return make_pair(-1, -1);
            }
            else {
                if(col[u] == col[v])
                    return make_pair(-1, -1);
            }
        }
    }
    return res;
}

void recolor(int v) {
    col[v] = (col[v] ^ 1);
    used[v] = 2;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = g[v][i].first;
        if(used[u] < 2)
            recolor(u);
    }
}

void solve(int n, vector<int> &bestAns) {
    for(int i = 0; i < n; i++) {
        used[i] = 0;
        col[i] = false;
    }
    for(int i = 0; i < n; i++)
        if(!used[i]) {
            pair<int, int> p = dfs(i);
            if(p.first == -1)
                return;
            if(2 * p.first > p.second)
                recolor(i);
        }
    vector<int> ans;
    for(int i = 0; i < n; i++)
        if(col[i])
            ans.push_back(i);
    if(!bestAns.empty() && bestAns[0] == -1)
        bestAns = ans;
    else if(bestAns.size() > ans.size())
        bestAns = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        v--;
        u--;
        g[v].push_back(make_pair(u, c));
        g[u].push_back(make_pair(v, c));
    }
    vector<int> ans(1, -1);
    solve(n, ans);
    for(int i = 0; i < n; i++)
        for(size_t j = 0; j < g[i].size(); j++)
            if(g[i][j].second == 'B')
                g[i][j].second = 'R';
            else
                g[i][j].second = 'B';
    solve(n, ans);
    if(!ans.empty() && ans[0] == -1)
        cout << -1 << '\n';
    else {
        cout << ans.size() << '\n';
        for(size_t i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}