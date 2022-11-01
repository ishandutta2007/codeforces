#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;
const int64_t LINF = 1LL << 62;

vector<int> G[NMAX];
vector<int> girls[NMAX];

int treeSize[NMAX];

void setSize(int node, int prev) {
    treeSize[node] = 1;
    for (int to: G[node]) {
        if (to == prev) continue;
        setSize(to, node);
        treeSize[node] += treeSize[to];
    }
}

struct Node {
    int64_t weight;
    int nodeInd, ind = -1;
    int64_t lazy = 0;

    bool operator<(const Node& o) const {
        return make_pair(weight, nodeInd) < make_pair(o.weight, o.nodeInd);
    }
};
Node aint[4 * NMAX];

int leaf[NMAX];
int nodePos[NMAX];
int xbegin[NMAX], xend[NMAX];
int xpos = 0;
int nodes[NMAX];
int cntPaths;
int pathId[NMAX];
int pathBegin[NMAX], pathEnd[NMAX];
int pathFather[NMAX];

void dfs(int node, int prev) {
    int cleaf = -1;
    for (int to: G[node]) {
        if (to == prev) {
            continue;
        }
        if (cleaf == -1 || treeSize[to] > treeSize[cleaf]) {
            cleaf = to;
        }
    }

    if (cleaf == -1) {
        nodePos[node] = xbegin[node] = xend[node] = ++xpos;
        pathId[node] = cntPaths++;
        pathBegin[pathId[node]] = xpos;
        pathEnd[pathId[node]] = xpos;
    } else {
        leaf[node] = leaf[cleaf];
        xbegin[node] = -1;
        xend[node] = -1;
        for (int to: G[node]) {
            if (to == prev || to == cleaf) {
                continue;
            }
            dfs(to, node);
            pathFather[pathId[to]] = node;
            if (xbegin[node] == -1) {
                xbegin[node] = xbegin[to];
            }
        }
        dfs(cleaf, node);
        if (xbegin[node] == -1) {
            xbegin[node] = xbegin[cleaf];
        }
        xend[node] = xend[cleaf] + 1;
        nodePos[node] = ++xpos;
        pathId[node] = pathId[cleaf];
        pathEnd[pathId[node]] = xpos;
    }
    nodes[xpos] = node;
}

void build(int node, int left, int right) {
    Node &n = aint[node];
    if (left == right) {
        int rnode = nodes[left];
        if (!girls[rnode].empty()) {
            n.weight = girls[rnode].back();
            n.nodeInd = rnode;
            n.ind = girls[rnode].back();
        } else {
            n.weight = LINF;
        }
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        n = min(aint[2 * node + 1], aint[2 * node + 2]);
    }
}

int64_t nodeAdd[NMAX];

void split(int node, int left, int right) {
    if (aint[node].lazy != 0) {
        aint[node].weight += aint[node].lazy;
        if (left < right) {
            aint[2 * node + 1].lazy += aint[node].lazy;
            aint[2 * node + 2].lazy += aint[node].lazy;
        } else {
            nodeAdd[left] += aint[node].lazy;
        }
        aint[node].lazy = 0;
    }
}

void update(int node, int left, int right, int lq, int rq, int value) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        aint[node].lazy += value;
    } else {
        int mid = (left + right) / 2;
        if (lq <= mid) {
            update(2 * node + 1, left, mid, lq, rq, value);
        }
        if (rq > mid) {
            update(2 * node + 2, mid + 1, right, lq, rq, value);
        }
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        aint[node] = min(aint[2 * node + 1], aint[2 * node + 2]);
    }
}

void updatePos(int node, int left, int right, int pos) {
    split(node, left, right);
    Node &n = aint[node];
    if (left == right) {
        int rnode = nodes[left];
        girls[rnode].pop_back();
        if (!girls[rnode].empty()) {
            n.weight = girls[rnode].back() + nodeAdd[left];
            n.nodeInd = rnode;
            n.ind = girls[rnode].back();
        } else {
            n.weight = LINF;
        }
    } else {
        int mid = (left + right) / 2;
        if (pos <= mid) {
            updatePos(2 * node + 1, left, mid, pos);
        } else {
            updatePos(2 * node + 2, mid + 1, right, pos);
        }
        split(2 * node + 1, left, mid);
        split(2 * node + 2, mid + 1, right);
        n = min(aint[2 * node + 1], aint[2 * node + 2]);
    }
}

Node query(int node, int left, int right, int lq, int rq) {
    split(node, left, right);
    if (lq <= left && right <= rq) {
        return aint[node];
    } else {
        int mid = (left + right) / 2;
        Node ret;
        ret.weight = LINF;

        if (lq <= mid) {
            ret = query(2 * node + 1, left, mid, lq, rq);
        }
        if (rq > mid) {
            ret = min(ret, query(2 * node + 2, mid + 1, right, lq, rq));
        }
        return ret;
    }
}

Node getMin(int n, int x, int y) {
    Node ret;
    ret.weight = LINF;

    while (pathId[x] != pathId[y]) {
        if (nodePos[x] > nodePos[y]) {
            swap(x, y);
        }
        ret = min(ret, query(0, 1, n, nodePos[x], pathEnd[pathId[x]]));
        x = pathFather[pathId[x]];
    }
    if (nodePos[x] > nodePos[y]) {
        swap(x, y);
    }
    ret = min(ret, query(0, 1, n, nodePos[x], nodePos[y]));
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

    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        girls[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        sort(girls[i].begin(), girls[i].end());
        reverse(girls[i].begin(), girls[i].end());
    }
    setSize(1, -1);
    dfs(1, -1);
    build(0, 1, n);

    while (q-- > 0) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            vector<int> ans;
            while (k-- > 0) {
                Node cmin = getMin(n, x, y);
                if (cmin.weight == LINF) {
                    break;
                }
                ans.push_back(cmin.ind);
                updatePos(0, 1, n, nodePos[cmin.nodeInd]);
            }
            cout << ans.size() << ' ';
            for (int p: ans) {
                cout << p << ' ';
            }
            cout << '\n';
        } else {
            int node, add;
            cin >> node >> add;

            update(0, 1, n, xbegin[node], xend[node], add);
        }
    }
}