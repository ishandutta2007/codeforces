#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

vector<int> G[NMAX];

int from[NMAX], to[NMAX], weight[NMAX], strength[NMAX];
int edges = 0;

int64_t minWeight[NMAX];
int father[NMAX];

int64_t subtree[NMAX];
int nodew[NMAX], nodes[NMAX];

void addEdge(int from, int to, int weight, int strength) {
    ::from[edges] = from;
    ::to[edges] = to;
    ::weight[edges] = weight;
    ::strength[edges] = strength;
    G[from].push_back(edges);
    G[to].push_back(edges);
    edges++;
}

void noSol() {
    cout << "-1\n";
    exit(0);
}

int64_t mustHave[NMAX];
int64_t rem[NMAX];

void dfs(int node, int prev) {
    father[node] = prev;
    subtree[node] = 0;
    minWeight[node] = 0;
    mustHave[node] = 0;
    for (int p: G[node]) {
        int to = ::to[p] ^ ::from[p] ^ node;
        if (to == prev) continue;
        nodew[to] = weight[p];
        nodes[to] = strength[p];
        dfs(to, node);
        subtree[node] += subtree[to] + weight[p];
        int64_t maxSub = min(strength[p] - minWeight[to], (int64_t) weight[p] - 1);
        if (maxSub < 0) {
            noSol();
        }
        minWeight[node] += minWeight[to];
        minWeight[node] += weight[p] - maxSub;
        if (strength[p] < mustHave[to]) {
            mustHave[to] = strength[p];
        }
        mustHave[node] += weight[p];
        mustHave[node] += mustHave[to];
    }
}

void dfs2(int node, int prev) {
    int64_t needRem = subtree[node] - mustHave[node];
    for (int p: G[node]) {
        int to = ::to[p] ^ ::from[p] ^ node;
        if (to == prev) continue;
        needRem -= subtree[to] - mustHave[to];
    }
    for (int p: G[node]) {
        int to = ::to[p] ^ ::from[p] ^ node;
        if (to == prev) continue;
        int64_t canRem = mustHave[to] - minWeight[to];
        canRem = min(canRem, needRem);
        mustHave[to] = mustHave[to] - canRem;
        dfs2(to, node);
        needRem -= canRem;
    }
    for (int p: G[node]) {
        int to = ::to[p] ^ ::from[p] ^ node;
        if (to == prev) continue;
        int64_t canRem = min((int64_t) weight[p] - 1, strength[p] - minWeight[to]);
        canRem = min(needRem, canRem);
        needRem -= canRem;
        rem[p] += canRem;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int from, to, weight, strength;
        cin >> from >> to >> weight >> strength;
        addEdge(from, to, weight, strength);
    }
    
    dfs(1, -1);
    dfs2(1, -1);
    
    cout << n << '\n';
    for (int i = 0; i < edges; ++i) {
        cout << from[i] << ' ' << to[i] << ' '
             << weight[i] - rem[i] << ' ' << strength[i] - rem[i] << '\n';
    }
}