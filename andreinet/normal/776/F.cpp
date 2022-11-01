#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;
const int MOD = 1e9 + 7;
const int BASE = 31;

class Tree {
public:
    Tree(int n):
        adj(n) {}

    void addEdge(int from, int to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    
    vector<int> getColoring() {
        subtree = vector<int>(SZ(adj));
        forbidden = vector<bool>(SZ(adj), false);
        vector<int> coloring(SZ(adj));
        solve(0, coloring);
        return coloring;
    }

private:
    vector<vector<int>> adj;
    vector<int> subtree;
    vector<bool> forbidden;

    int total;

    void solve(int root, vector<int>& coloring, int lvl = 1) {
        total = 0;
        dfs(root);
        root = choose(root);
        coloring[root] = lvl;
        forbidden[root] = true;
        for (int to: adj[root]) {
            if (!forbidden[to]) {
                solve(to, coloring, lvl + 1);
            }
        }
    }

    void dfs(int node, int prev = -1) {
        subtree[node] = 1;
        total++;
        for (int to: adj[node]) {
            if (to == prev || forbidden[to]) {
                continue;
            }
            dfs(to, node);
            subtree[node] += subtree[to];
        }
    }

    int choose(int node, int prev = -1) {
        bool good = true;
        for (int to: adj[node]) {
            if (to == prev || forbidden[to]) {
                continue;
            }
            good &= subtree[to] * 2 <= total;
        }
        good &= (total - subtree[node]) * 2 <= total;
        if (good) {
            return node;
        }
        for (int to: adj[node]) {
            if (to == prev || forbidden[to]) {
                continue;
            }
            int x = choose(to, node);
            if (x != -1) {
                return x;
            }
        }
        return -1;
    }
};

vector<int> G[NMAX];

vector<int> buildHashes(const vector<int>& a) {
    vector<int> ret(SZ(a));
    int h = 0;
    for (int i = 0; i < SZ(a); ++i) {
        h = ((int64_t) h * BASE + a[i]) % MOD;
        ret[i] = h;
    }
    return ret;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    map<pair<int, int>, int> indexes;
    vector<int> firstNode(m, -1), secondNode(m, -1);
    vector<pair<int, int>> dg;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
        if (x > y) {
            swap(x, y);
        }
        indexes[make_pair(x, y)] = i;
        dg.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; ++i) {
        G[i].push_back((i + 1) % n);
        sort(G[i].begin(), G[i].end());
    }
    
    vector<bool> used(n, false);
    int nodes = 0;
    vector<vector<int>> vadj;
    auto doStuff = [&](int prev, int node) -> void {
        int start = prev;
        vector<pair<int, int>> diags;
        vector<int> vertexes = {prev};
        if (node != (prev + 1) % n) {
            diags.push_back(make_pair(prev, node));
        }
        while (node != start) {
            vertexes.push_back(node);
            int pos = lower_bound(G[node].begin(), G[node].end(),
                    prev) - G[node].begin() - 1;
            if (pos == -1) pos += SZ(G[node]);
            int next = G[node][pos];
            if (next != (node + 1) % n) {
                diags.push_back(make_pair(node, next));
            } else {
                used[node] = true;
            }
            prev = node;
            node = next;
        }
        for (pair<int, int> p: diags) {
            if (p.first > p.second) {
                swap(p.first, p.second);
                int ind = indexes[p];
                secondNode[ind] = nodes;
            } else {
                int ind = indexes[p];
                firstNode[ind] = nodes;
            }
        }
        nodes++;
        sort(vertexes.begin(), vertexes.end());
        reverse(vertexes.begin(), vertexes.end());
        vadj.push_back(vertexes);
    };
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            int start = i;
            int node = (i + 1) % n;
            int prev = i;
            doStuff(prev, node);
        }
    }
    for (int i = 0; i < m; ++i) {
        if (firstNode[i] == -1) {
            doStuff(dg[i].first, dg[i].second);
        }
        if (secondNode[i] == -1) {
            doStuff(dg[i].second, dg[i].first);
        }
    }
    vector<int> nind(nodes);
    vector<vector<int>> hashes(nodes);
    for (int i = 0; i < nodes; ++i) {
        hashes[i] = buildHashes(vadj[i]);
    }
    for (int i = 0; i < nodes; ++i) {
        nind[i] = i;
    }
    sort(nind.begin(), nind.end(), [&](int a, int b) -> bool {
        return vadj[a] > vadj[b];
    });
    vector<int> xpos(nodes);
    for (int i = 0; i < nodes; ++i) {
        xpos[nind[i]] = nodes - i - 1;
    }
    Tree t(nodes);
    for (int i = 0; i < m; ++i) {
        assert(firstNode[i] != -1);
        assert(secondNode[i] != -1);
        t.addEdge(xpos[firstNode[i]], xpos[secondNode[i]]);
    }
    vector<int> colors = t.getColoring();
    for (int v: colors) {
        cout << v << ' ';
    }
    cout << endl;
}