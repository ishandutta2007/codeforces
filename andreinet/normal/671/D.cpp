#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int64_t LINF = 1LL << 61;

class SegmentTree {
public:
    SegmentTree(int _n):
        aint(vector<int64_t>(4 * _n, 0)),
        lazy(vector<int64_t>(4 * _n, 0)),
        n(_n) {}

    void update(int left, int right, int64_t value) {
        if (left > right) {
            return;
        }
        update(0, 0, n - 1, left, right, value);
    }
    void update(int pos, int64_t value) {
        update(0, 0, n - 1, pos, pos, value);
    }
    int64_t query(int left, int right) {
        if (left > right) {
            return LINF;
        }
        return query(0, 0, n - 1, left, right);
    }
private:
    vector<int64_t> aint;
    vector<int64_t> lazy;
    int n;

    void split(int node, int left, int right) {
        if (lazy[node] != 0) {
            aint[node] += lazy[node];
            aint[node] = min(aint[node], LINF);
            if (left < right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 1] = min(lazy[2 * node + 1], LINF);
                lazy[2 * node + 2] += lazy[node];
                lazy[2 * node + 2] = min(lazy[2 * node + 2], LINF);
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int left, int right, int lq, int rq, int64_t value) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            lazy[node] = value;
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

    int64_t query(int node, int left, int right, int lq, int rq) {
        split(node, left, right);
        if (lq <= left && right <= rq) {
            return aint[node];
        } else {
            int mid = (left + right) / 2;
            int64_t ret = LINF;
            if (lq <= mid) {
                ret = query(2 * node + 1, left, mid, lq, rq);
            }
            if (rq > mid) {
                ret = min(ret, query(2 * node + 2, mid + 1, right, lq, rq));
            }
            return ret;
        }
    }
};

vector<vector<int>> graph;
vector<vector<int>> qadd, qerase;
vector<int> efirst, elast;
vector<int> qpos, qcost;
int epos = 0;

void dfs1(int node, int prev) {
    efirst[node] = epos++;
    for (int q: qadd[node]) {
        qpos[q] = epos++;
    }
    for (int to: graph[node]) {
        if (to != prev) {
            dfs1(to, node);
        }
    }
    elast[node] = epos;
}

vector<int64_t> dp;

void dfs2(SegmentTree& t, int node, int prev) {
    dp[node] = LINF;
    int64_t sum = 0;
    for (int to: graph[node]) {
        if (to != prev) {
            dfs2(t, to, node);
            sum += dp[to];
            sum = min(sum, LINF);
        }
    }
    if (prev == -1) {
        dp[node] = sum;
        return;
    }
    for (int q: qadd[node]) {
        t.update(qpos[q], min(LINF, qcost[q] + sum));
    }
    for (int q: qerase[node]) {
        t.update(qpos[q], LINF);
    }
    for (int to: graph[node]) {
        if (to != prev) {
            int64_t v = sum == LINF ? LINF: sum - dp[to];
            t.update(efirst[to], elast[to], sum - dp[to]);
        }
    }
    dp[node] = t.query(efirst[node], elast[node]);
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

    graph = vector<vector<int>>(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    qadd = vector<vector<int>>(n);
    qerase = vector<vector<int>>(n);
    qpos = vector<int>(m);
    qcost = vector<int>(m);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; 
        y--;
        qadd[x].push_back(i);
        qerase[y].push_back(i);
        qcost[i] = c;
    }
    efirst = vector<int>(n, 0);
    elast = vector<int>(n, 0);
    dfs1(0, -1);
    SegmentTree t(epos);
    for (int i = 0; i < n; ++i) {
        t.update(efirst[i], LINF);
    }
    dp = vector<int64_t>(n, 0);
    dfs2(t, 0, -1);
    if (dp[0] == LINF) {
        dp[0] = -1;
    }
    cout << dp[0] << '\n';
}