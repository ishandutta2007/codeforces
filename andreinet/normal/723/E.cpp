#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 205;
const int MMAX = 42005;

vector<pair<int, int>> G[NMAX];
bool usedEdge[MMAX];
bool usedNode[NMAX];
int deg[NMAX];

int euler[MMAX];
int eind = 0;

void dfs(int node) {
    vector<int> stk;
    stk.push_back(node);
    while (!stk.empty()) {
        int node = stk.back();
        usedNode[node] = true;
        if (SZ(G[node])) {
            int y = G[node].back().first;
            int edge = G[node].back().second;
            G[node].pop_back();
            if (usedEdge[edge]) {
                continue;
            }
            stk.push_back(y);
            usedEdge[edge] = true;
        } else {
            stk.pop_back();
            euler[eind++] = node;
        }
    }
}

void printEdges() {
    for (int i = 0; i < eind - 1; ++i) {
        if (euler[i] != 0 && euler[i + 1] != 0) {
            cout << euler[i] << ' ' << euler[i + 1] << '\n';
        }
    }
    eind = 0;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        memset(usedEdge, 0, sizeof usedEdge);
        memset(usedNode, 0, sizeof usedNode);
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            G[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(make_pair(y, i));
            G[y].push_back(make_pair(x, i));
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (SZ(G[i]) % 2 == 1) {
                G[0].push_back(make_pair(i, m));
                G[i].push_back(make_pair(0, m));
                m++;
            } else {
                ans++;
            }
        }
        cout << ans << '\n';
        
        dfs(0);
        printEdges();
        for (int i = 1; i <= n; ++i) {
            if (!usedNode[i]) {
                dfs(i);
                printEdges();
            }
        }
    }
}