/*
Make a new graph, which is our old graph (N^2 edges) + a node 0
We make an edge between node 0 and all other nodes, the cost being the cost to build a power station at that node

We then run MST on this new graph, and we get the answer
We will use kruskals, which uses UF and sorts the edges
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define int long long
#define MAXN 2010
using namespace std;
struct UF {
    int comp[MAXN];
    vector<int> incomp[MAXN];
    UF() {
        for (int i = 0; i < MAXN; i++) {
            comp[i] = i;
            incomp[i].push_back(i);
        }
    }
    bool connected(int a, int b) {
        return comp[a] == comp[b];
    }
    void merge(int a, int b) {
        a = comp[a], b = comp[b];
        // we want a to be the smaller component
        if (incomp[a].size() > incomp[b].size()) {
            swap(a, b);
        }
        // merge A into B
        for (int i : incomp[a]) {
            comp[i] = b;
            incomp[b].push_back(i);
        }
        incomp[a].clear();
    }
};
UF uf;
int x[MAXN], y[MAXN], c[MAXN], k[MAXN];
int edgecost(int a, int b) {
    return (abs(x[a]-x[b]) + abs(y[a]-y[b]))*(k[a]+k[b]);
}
int adj[MAXN][MAXN]; // adj[i][j] is the cost of the edge from i to j
int ans, n;
#undef int
int main() {
    #define int long long
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &x[i], &y[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &k[i]);
    // construct graph
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            // for each i < j
            adj[i][j] = adj[j][i] = edgecost(i, j);
        }
    }
    for (int i = 1; i <= n; i++) {
        adj[0][i] = adj[i][0] = c[i];
    }
    // Find MST
    vector<pair<int, int> > v;
    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            v.push_back(make_pair(i, j));
        }
    }
    // sort edges by weight (increasing)
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        return adj[a.first][a.second] < adj[b.first][b.second];
    });
    vector<int> powerStationsBuilt;
    vector<pair<int, int> > edgesUsed;
    for (pair<int, int> e : v) {
        int a = e.first;
        int b = e.second;
        if (!uf.connected(a, b)) {
            uf.merge(a, b);
            ans += adj[a][b];
            // a < b
            if (!a) {
                // power station
                powerStationsBuilt.push_back(b);
            } else {
                edgesUsed.push_back(make_pair(a, b));
            }
        }
    }
    printf("%lld\n", ans);
    printf("%lld\n", (int)powerStationsBuilt.size());
    for (int a : powerStationsBuilt) printf("%lld ", a);
    printf("\n");
    printf("%lld\n", (int)edgesUsed.size());
    for (pair<int, int> e : edgesUsed) printf("%lld %lld\n", e.first, e.second);
}