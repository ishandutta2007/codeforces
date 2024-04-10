#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 105;

vector<int> G[NMAX];
int Mdeg[NMAX][NMAX], deg[NMAX];
int minlvl[NMAX], level[NMAX];
bool used[NMAX];
vector<pair<int, int>> edges;

void dfs(int node, int prev, int lvl) {
    level[node] = lvl;
    minlvl[node] = lvl;
    used[node] = true;

    for (int p: G[node]) {
        if (p == prev) continue;
        int to = edges[p].first ^ edges[p].second ^ node;
        if (used[to]) {
            minlvl[node] = min(minlvl[node], level[to]);
        } else {
            dfs(to, p, lvl + 1);
            minlvl[node] = min(minlvl[node], minlvl[to]);
        }
    }
}

bool isBridge(int n1, int n2) {
    if (level[n1] > level[n2]) swap(n1, n2);
    return minlvl[n2] > level[n1];
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> euler1(m + 1);
    for (int i = 0; i < m + 1; ++i)
        cin >> euler1[i];
    
    for (int i = m - 1; i >= 0; --i) {
        vector<int> euler2 = euler1;
        for (int j = i + 2; j < m + 1; ++j)
            euler2[j] = 0;

        memset(deg, 0, sizeof deg);
        memset(Mdeg, 0, sizeof Mdeg);
        for (int j = i; j < m; ++j) {
            int n1 = euler1[j], n2 = euler1[j + 1];
            deg[n1]++;
            deg[n2]++;
            Mdeg[n1][n2]++;
            Mdeg[n2][n1]++;
        }

        for (int j = i + 1; j < m + 1; ++j) {
            edges.clear();
            for (int i = 1; i <= n; ++i) G[i].clear();
            for (int i = 1; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    for (int p = Mdeg[i][j]; p > 0; --p) {
                        G[i].push_back(SZ(edges));
                        G[j].push_back(SZ(edges));
                        edges.push_back(make_pair(i, j));
                    }
                }
            }
            
            memset(used, 0, sizeof used);
            int prev = euler2[j - 1], k;
            dfs(prev, -1, 0);
            for (k = euler2[j] + 1; k <= n; ++k) {
                if (Mdeg[prev][k] > 0 && 
                        (deg[prev] == 1 || !isBridge(prev, k))) {
                    euler2[j] = k;
                    break;
                }
            }
            if (k == n + 1) goto OUTER;
            Mdeg[prev][k]--;
            Mdeg[k][prev]--;
            deg[prev]--;
            deg[k]--;
        }

        for (int i = 0; i < m + 1; ++i) {
            cout << euler2[i] << ' ';
        }
        cout << '\n';
        return 0;

        OUTER:;
    }

    cout << "No solution\n";
}