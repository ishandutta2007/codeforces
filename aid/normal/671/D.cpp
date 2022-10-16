#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 300 * 1000 + 5;
int dep[MAXN];
long long cheap[MAXN], x[MAXN];
vector<int> g[MAXN];
vector< pair<int, int> > w[MAXN];
map<int, long long> *mp[MAXN];

void add(int dep, long long c, map<int, long long> *mp, long long x) {
    map<int, long long>::iterator it = mp->upper_bound(dep);
    if(it != mp->begin()) {
        it--;
        if(it->second + x < c)
            return;
    }
    while(true) {
        map<int, long long>::iterator it = mp->lower_bound(dep);
        if(it == mp->end() || it->second + x < c)
            break;
        mp->erase(it);
    }
    if(mp->find(dep) == mp->end())
        (*mp)[dep] = c - x;
}

bool dfs(int v, int p) {
    bool leaf = true;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            dep[g[v][i]] = dep[v] + 1;
            if(!dfs(g[v][i], v))
                return false;
            leaf = false;
        }
    for(size_t i = 0; i < w[v].size(); i++)
        w[v][i].first = dep[w[v][i].first];
    if(p == -1) {
        cheap[v] = 0;
        for(size_t i = 0; i < g[v].size(); i++)
            if(g[v][i] != p)
                cheap[v] += cheap[g[v][i]];
        return true;
    }
    if(leaf) {
        mp[v] = new map<int, long long>();
        x[v] = 0;
        for(size_t i = 0; i < w[v].size(); i++)
            add(w[v][i].first, w[v][i].second, mp[v], x[v]);
        mp[v]->erase(dep[v]);
        if(mp[v]->empty())
            return false;
        cheap[v] = mp[v]->rbegin()->second + x[v];
        return true;
    }
    int maxSon = -1;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p && (maxSon == -1 ||
                            (mp[g[v][i]]->size() > mp[maxSon]->size())))
            maxSon = g[v][i];
    mp[v] = mp[maxSon];
    x[v] = x[maxSon];
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p && g[v][i] != maxSon)
            x[v] += cheap[g[v][i]];
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p && g[v][i] != maxSon)
            for(map<int, long long>::iterator it = mp[g[v][i]]->begin();
                it != mp[g[v][i]]->end(); it++)
                add(it->first, it->second + x[g[v][i]] + x[v] - x[maxSon] -
                    cheap[g[v][i]] + cheap[maxSon], mp[v], x[v]);
    for(size_t i = 0; i < w[v].size(); i++)
        add(w[v][i].first, w[v][i].second + x[v] - x[maxSon] +
            cheap[maxSon], mp[v], x[v]);
    mp[v]->erase(dep[v]);
    if(mp[v]->empty())
        return false;
    cheap[v] = mp[v]->rbegin()->second + x[v];
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--;
        u--;
        w[v].push_back(make_pair(u, c));
    }
    if(!dfs(0, -1))
        cout << -1 << '\n';
    else
        cout << cheap[0] << '\n';
    return 0;
}