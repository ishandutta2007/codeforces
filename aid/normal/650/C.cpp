#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
char used[MAXN];
int c[MAXN], dp[MAXN];
vector<int> g[MAXN], gr[MAXN], gc[MAXN], ts;
vector< vector<int> > a;

void dfs0(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(!used[g[v][i]])
            dfs0(g[v][i]);
    ts.push_back(v);
}

void dfs1(int v, int comp) {
    used[v] = true;
    c[v] = comp;
    for(size_t i = 0; i < gr[v].size(); i++)
        if(!used[gr[v][i]])
            dfs1(gr[v][i], comp);
}

void getDp(int v) {
    used[v] = true;
    dp[v] = 0;
    for(size_t i = 0; i < gc[v].size(); i++) {
        if(!used[gc[v][i]])
            getDp(gc[v][i]);
        dp[v] = max(dp[v], dp[gc[v][i]]);
    }
    dp[v]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        a[i].resize(m);
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for(int i = 0; i < n; i++) {
        vector< pair<int, int> > p(m);
        for(int j = 0; j < m; j++)
            p[j] = make_pair(a[i][j], j);
        sort(p.begin(), p.end());
        for(int j = 0; j + 1 < m; j++) {
            g[i * m + p[j + 1].second].push_back(i * m + p[j].second);
            if(p[j].first == p[j + 1].first)
                g[i * m + p[j].second].push_back(i * m + p[j + 1].second);
        }
    }
    for(int i = 0; i < m; i++) {
        vector< pair<int, int> > p(n);
        for(int j = 0; j < n; j++)
            p[j] = make_pair(a[j][i], j);
        sort(p.begin(), p.end());
        for(int j = 0; j + 1 < n; j++) {
            g[p[j + 1].second * m + i].push_back(p[j].second * m + i);
            if(p[j].first == p[j + 1].first)
                g[p[j].second * m + i].push_back(p[j + 1].second * m + i);
        }
    }
    int vs = n * m;
    for(int i = 0; i < vs; i++)
        for(size_t j = 0; j < g[i].size(); j++)
            gr[g[i][j]].push_back(i);
    for(int i = 0; i < vs; i++)
        if(!used[i])
            dfs0(i);
    for(int i = 0; i < vs; i++)
        used[i] = false;
    int cs = 0;
    for(int i = vs - 1; i >= 0; i--)
        if(!used[ts[i]])
            dfs1(ts[i], cs++);
    for(int i = 0; i < vs; i++)
        for(size_t j = 0; j < g[i].size(); j++)
            gc[c[i]].push_back(c[g[i][j]]);
    for(int i = 0; i < cs; i++)
        used[i] = false;
    for(int i = 0; i < cs; i++)
        if(!used[i])
            getDp(i);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << dp[c[i * m + j]] << ' ';
        cout << '\n';
    }
    return 0;
}