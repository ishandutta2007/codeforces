#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

vector<int> G[NMAX];
int treeSize[NMAX];
bool special[NMAX];

int total;

int centroid = -1;

void dfs(int node, int prev) {
    for (int to: G[node]) {
        if (to != prev) {
            dfs(to, node);
            treeSize[node] += treeSize[to];
        }
    }
    if ((total - treeSize[node]) * 2 > total) {
        return;
    }
    for (int to: G[node]) {
        if (to != prev) {
            if (treeSize[to] * 2 > total) {
                return;
            }
        }
    }
    centroid = node;
}

void dfsGet(int node, int prev, vector<int>& nodes) {
    if (special[node]) {
        nodes.push_back(node);
    }
    for (int to: G[node]) {
        if (to != prev) {
            dfsGet(to, node, nodes);
        }
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

    cout << "1\n";

    int n;
    cin >> n >> total;
    total *= 2;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 0; i < total; ++i) {
        int x;
        cin >> x;
        treeSize[x]++;
        special[x] = true;
    }
    dfs(1, -1);
    assert(centroid != -1);
    vector<vector<int>> nodes;
    for (int to: G[centroid]) {
        vector<int> cnodes;
        dfsGet(to, centroid, cnodes);
        nodes.push_back(cnodes);
    }
    if (special[centroid]) {
        nodes.push_back({centroid});
    }
    cout << centroid << '\n';

    priority_queue<pair<int, int>> q;
    for (int i = 0; i < SZ(nodes); ++i) {
        if (!nodes[i].empty()) {
            q.push(make_pair(SZ(nodes[i]), i));
        }
    }
    while (!q.empty()) {
        int pile1 = q.top().second;
        q.pop();
        int pile2 = q.top().second;
        q.pop();
        
        cout << nodes[pile1].back() << ' ' << nodes[pile2].back() << ' '
             << centroid << '\n';
        nodes[pile1].pop_back();
        nodes[pile2].pop_back();

        if (SZ(nodes[pile1]) > 0) {
            q.push(make_pair(SZ(nodes[pile1]), pile1));
        }
        if (SZ(nodes[pile2]) > 0) {
            q.push(make_pair(SZ(nodes[pile2]), pile2));
        }
    }
}