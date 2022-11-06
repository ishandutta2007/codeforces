#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
int n;
vector<int> adj[MxN + 9];
int pred[MxN + 9];

void dfsDiam(const int u, const int parent, const int currDepth, int &maxDepth, int &deepest) {
    if (currDepth > maxDepth) {
        maxDepth = currDepth;
        deepest = u;
    }

    for (const int &v : adj[u])
        if (v != parent) {
            pred[v] = u;
            dfsDiam(v, u, currDepth + 1, maxDepth, deepest);
        }
}

// maxDepth, deepest
pair<int, int> dfsDiam(const int u) {
    int maxDepth = 0;
    int deepest = u;
    dfsDiam(u, -1, 0, maxDepth, deepest);
    return {maxDepth, deepest};
}


bool check(const int root, const int excluded) {
    static int dp[MxN + 9];
    memset(dp, 0, sizeof dp);

    function<bool(int, int, int)> dfs;

    dfs = [&](const int u, const int parent, const int depth) {
        if (dp[depth] && dp[depth] != (int) adj[u].size())
            return false;
        dp[depth] = (int) adj[u].size();
        for (int v : adj[u])
            if (v != parent && v != excluded && !dfs(v, u, depth + 1))
                return false;
        return true;
    };
    return dfs(root, excluded, 0);
}

// diameter length, center of diameter
pair<int, int> diam(int u) {
    u = dfsDiam(u).second;
    if (check(u, -1)) {
        cout << u;
        exit(0);
    }
    pair<int, int> p = dfsDiam(u);
    if (check(p.second, -1)) {
        cout << p.second;
        exit(0);
    }
    for (int rep = p.first >> 1; rep; --rep)

        p.second = pred[p.second];
    return p;
}

int dfsLine(const int prev, const int curr) {
    if (adj[curr].size() == 1)
        return 0;
    if (adj[curr].size() == 2) {
        for (int x : adj[curr])
            if (x != prev)
                return 1 + dfsLine(curr, x);
        assert(0);
        return 1;
    }
    return -MxN;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int root = diam(1).second;
    if (check(root, -1)) {
        cout << root;
        return 0;
    }

    map<int, int> mp;
    for (int x : adj[root]) {
        int len = dfsLine(root, x);
        if (len >= 0) {
            mp[len] = x;
            if (mp.size() > 2) {
                cout << -1;
                cerr << "mp sz > 2";
                return 0;
            }
        }
    }

    for (auto e : mp)
        if (check(root, e.second)) {
            int x = root, y = e.second;
            while (adj[y].size() > 1) {
                int z = adj[y][0];
                if (z == x)
                    z = adj[y][1];

                x = y;
                y = z;
            }
            cout << y;
            return 0;
        }
    cout << -1;
    cerr << "end";
    return 0;
}