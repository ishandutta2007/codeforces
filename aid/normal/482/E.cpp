#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 50 * 1000 + 5, K = 500;
int p[MAXN], comp[MAXN], snd[MAXN];
char root[MAXN];
long long s[MAXN], ts[MAXN], pv[MAXN], pvs[MAXN], sv[MAXN];
pair<char, pair<int, int> > q[MAXN];
vector<int> g[MAXN], gc[MAXN];

bool dfsLca(int v) {
    int cnt = root[v];
    for(size_t i = 0; i < g[v].size(); i++)
        cnt += dfsLca(g[v][i]);
    if(cnt > 1)
        root[v] = true;
    return cnt;
}

void dfs0(int v) {
    ts[v] = 1;
    sv[v] = 1;
    for(size_t i = 0; i < g[v].size(); i++) {
        dfs0(g[v][i]);
        sv[v] += 2ll * ts[g[v][i]] * ts[v];
        ts[v] += ts[g[v][i]];
    }
}

void dfs1(int v, int c) {
    comp[v] = c;
    if(root[v])
        pvs[v] = 0;
    else {
        pvs[v] = pv[v] + pvs[p[v]];
        snd[v] = (root[p[v]]? v : snd[p[v]]);
    }
    for(size_t i = 0; i < g[v].size(); i++)
        if(!root[g[v][i]])
            dfs1(g[v][i], c);
}

bool anc(int v, int u) {
    for(int w = u;; w = comp[p[w]]) {
        if(w == v)
            return true;
        if(w == 0)
            return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        g[p[i]].push_back(i);
    }
    for(int i = 0; i < n; i++)
        cin >> s[i];
    dfs0(0);
    for(int i = 1; i < n; i++)
        pv[i] = (ts[p[i]] - ts[i]) * s[p[i]];
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += s[i] * sv[i];
    cout << (long double)ans / ((long long)n * n) << '\n';
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> q[i].first >> q[i].second.first >> q[i].second.second;
        q[i].second.first--;
        if(q[i].first == 'P')
            q[i].second.second--;
    }
    for(int bl = 0; bl < m; bl += K) {
        int br = min(m, bl + K);
        for(int i = 0; i < n; i++)
            root[i] = false;
        root[0] = true;
        for(int i = bl; i < br; i++) {
            root[q[i].second.first] = true;
            if(q[i].first == 'P')
                root[q[i].second.second] = true;
        }
        dfsLca(0);
        dfs0(0);
        for(int i = 1; i < n; i++)
            pv[i] = 2 * (ts[p[i]] - ts[i]) * s[p[i]];
        for(int i = 0; i < n; i++)
            if(root[i])
                dfs1(i, i);
        vector<int> roots;
        for(int i = 0; i < n; i++)
            if(root[i])
                roots.push_back(i);
        int k = roots.size();
        for(int i = 0; i < k; i++)
            if(roots[i] != 0)
                gc[comp[p[roots[i]]]].push_back(roots[i]);
        for(int i = bl; i < br; i++) {
            if(q[i].first == 'P') {
                int v = q[i].second.first, u = q[i].second.second;
                if(anc(v, u))
                    swap(v, u);
                for(int w = v; w != 0; w = comp[p[w]]) {
                    ans -= ts[v] * (pv[w] + pvs[p[w]]);
                    if(p[w] != comp[p[w]])
                        ts[snd[p[w]]] -= ts[v];
                    ts[comp[p[w]]] -= ts[v];
                    sv[comp[p[w]]] -=
                        2 * (ts[comp[p[w]]] -
                             (p[w] == comp[p[w]]? (w == v? 0 : ts[w]) :
                              ts[snd[p[w]]])) * ts[v];
                    for(size_t j = 0; j < gc[comp[p[w]]].size(); j++)
                        if(gc[comp[p[w]]][j] != w) {
                            if(p[gc[comp[p[w]]][j]] == comp[p[w]])
                                pv[gc[comp[p[w]]][j]] -=
                                    2 * ts[v] * s[comp[p[w]]];
                            else
                                pvs[p[gc[comp[p[w]]][j]]] -=
                                    2 * ts[v] * s[comp[p[w]]];
                        }
                }
                for(size_t j = 0; j < gc[comp[p[v]]].size(); j++)
                    if(gc[comp[p[v]]][j] == v) {
                        gc[comp[p[v]]].erase(gc[comp[p[v]]].begin() + j);
                        break;
                    }
                p[v] = u;
                gc[u].push_back(v);
                pv[v] = 2 * ts[u] * s[u];
                for(int w = v; w != 0; w = comp[p[w]]) {
                    ans += ts[v] * (pv[w] + pvs[p[w]]);
                    if(p[w] != comp[p[w]])
                        ts[snd[p[w]]] += ts[v];
                    ts[comp[p[w]]] += ts[v];
                    sv[comp[p[w]]] +=
                        2 * (ts[comp[p[w]]] - (p[w] == comp[p[w]]? ts[w] :
                                               ts[snd[p[w]]])) * ts[v];
                    for(size_t j = 0; j < gc[comp[p[w]]].size(); j++)
                        if(gc[comp[p[w]]][j] != w) {
                            if(p[gc[comp[p[w]]][j]] == comp[p[w]])
                                pv[gc[comp[p[w]]][j]] +=
                                    2 * ts[v] * s[comp[p[w]]];
                            else
                                pvs[p[gc[comp[p[w]]][j]]] +=
                                    2 * ts[v] * s[comp[p[w]]];
                        }
                }
            }
            else {
                int v = q[i].second.first, x = q[i].second.second;
                ans += (x - s[v]) * sv[v];
                for(size_t j = 0; j < gc[v].size(); j++)
                    if(p[gc[v][j]] == v)
                        pv[gc[v][j]] += 2 * (x - s[v]) * (ts[v] - ts[gc[v][j]]);
                    else
                        pvs[p[gc[v][j]]] += 2 * (x - s[v]) *
                            (ts[v] - ts[snd[p[gc[v][j]]]]);
                s[v] = x;
            }
            cout << (long double)ans / ((long long)n * n) << '\n';
        }
        for(int i = 0; i < n; i++) {
            g[i].clear();
            gc[i].clear();
        }
        for(int i = 1; i < n; i++)
            g[p[i]].push_back(i);
    }
    return 0;
}