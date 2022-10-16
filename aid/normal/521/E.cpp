#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Edge {
    int v, u, c;

    Edge(int _v, int _u): v(_v), u(_u), c(-1) {}
};

const int MAXN = 200 * 1000 + 5;
char cut[MAXN], onCycle[MAXN];
int tin[MAXN], f[MAXN], s[MAXN], used[MAXN], tt, freec, freeus;
vector<int> g[MAXN], ans[3], cycle, path;
map<int, vector<int> > gc[MAXN];
vector<Edge> e;

void findCut(int v, int p) {
    used[v] = true;
    tin[v] = tt++;
    f[v] = tin[v];
    int cnt = 0;
    for(size_t i = 0; i < g[v].size(); i++) {
        int u = (e[g[v][i]].v == v? e[g[v][i]].u : e[g[v][i]].v);
        if(used[u])
            f[v] = min(f[v], tin[u]);
        else {
            cnt++;
            findCut(u, v);
            f[v] = min(f[v], f[u]);
            if(p != -1 && f[u] >= tin[v])
                cut[v] = true;
        }
    }
    if(p == -1 && cnt > 1)
        cut[v] = true;
}

void findComps(int v, int col) {
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); i++) {
        if(e[g[v][i]].c >= 0)
            continue;
        int u = (e[g[v][i]].v == v? e[g[v][i]].u : e[g[v][i]].v);
        if(used[u])
            e[g[v][i]].c = col;
        else {
            if((cut[v] && f[u] >= tin[v]) || col == -1) {
                e[g[v][i]].c = freec;
                s[freec] = v;
                freec++;
            }
            else
                e[g[v][i]].c = col;
            findComps(u, e[g[v][i]].c);
        }
    }
}

bool getCycle(int v, int col, int pe, int us) {
    used[v] = us;
    onCycle[v] = true;
    cycle.push_back(v);
    vector<int> &gv = gc[v][col];
    for(size_t i = 0; i < gv.size(); i++) {
        if(gv[i] == pe)
            continue;
        int u = (e[gv[i]].v == v? e[gv[i]].u : e[gv[i]].v);
        if(onCycle[u]) {
            cycle.push_back(u);
            return true;
        }
        if(used[u] != us && getCycle(u, col, gv[i], us))
            return true;
    }
    cycle.pop_back();
    onCycle[v] = false;
    return false;
}

bool dfs(int v, int col, int us) {
    used[v] = us;
    path.push_back(v);
    if(onCycle[v])
        return true;
    vector<int> &gv = gc[v][col];
    for(size_t i = 0; i < gv.size(); i++) {
        int u = (e[gv[i]].v == v? e[gv[i]].u : e[gv[i]].v);
        if(e[gv[i]].c == col && used[u] != us && dfs(u, col, us))
            return true;
    }
    path.pop_back();
    return false;
}

bool getAns(int s, int col) {
    if(!getCycle(s, col, -1, ++freeus))
        return false;
    int beg;
    for(int i = (int)cycle.size() - 2; i >= 0; i--)
        if(cycle[i] == cycle.back()) {
            beg = i;
            break;
        }
    for(int i = 0; i < beg; i++)
        onCycle[cycle[i]] = false;
    copy(cycle.begin() + beg + 1, cycle.end(), cycle.begin());
    cycle.resize((int)cycle.size() - beg - 1);
    int len = cycle.size();
    for(int i = 0; i < len; i++)
        cycle.push_back(cycle[i]);
    for(int i = 0; i < len; i++) {
        int v = cycle[i], prv = (i? cycle[i - 1] : cycle[len - 1]),
            nxt = cycle[i + 1];
        vector<int> &gv = gc[v][col];
        for(size_t j = 0; j < gv.size(); j++) {
            int u = (e[gv[j]].v == v? e[gv[j]].u : e[gv[j]].v);
            if(u != prv && u != nxt) {
                used[v] = freeus + 1;
                path.push_back(v);
                dfs(u, col, ++freeus);
                int t = path.back(), p = 0;
                for(int k = i; k <= i + len; k++) {
                    ans[p].push_back(cycle[k]);
                    if(cycle[k] == t) {
                        p++;
                        ans[p].push_back(cycle[k]);
                    }
                }
                reverse(ans[1].begin(), ans[1].end());
                ans[2].resize(path.size());
                copy(path.begin(), path.end(), ans[2].begin());
                return true;
            }
        }
    }
    for(int i = 0; i < len; i++)
        onCycle[cycle[i]] = false;
    cycle.clear();
    return false;
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
        e.push_back(Edge(v, u));
    }
    for(int i = 0; i < n; i++)
        if(!used[i])
            findCut(i, -1);
    for(int i = 0; i < n; i++)
        used[i] = false;
    for(int i = 0; i < n; i++)
        if(!used[i])
            findComps(i, -1);
    for(int i = 0; i < n; i++)
        for(size_t j = 0; j < g[i].size(); j++) {
            if(gc[i].find(e[g[i][j]].c) == gc[i].end())
                gc[i][e[g[i][j]].c] = vector<int>();
            gc[i][e[g[i][j]].c].push_back(g[i][j]);
        }
    for(int i = 0; i < n; i++)
        used[i] = false;
    for(int i = 0; i < freec; i++)
        if(getAns(s[i], i)) {
            cout << "YES\n";
            for(int j = 0; j < 3; j++) {
                cout << ans[j].size() << ' ';
                for(size_t k = 0; k < ans[j].size(); k++)
                    cout << ans[j][k] + 1 << ' ';
                cout << '\n';
            }
            return 0;
        }
    cout << "NO\n";
    return 0;
}