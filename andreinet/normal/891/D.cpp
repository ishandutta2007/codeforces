#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int NMAX = 500005;

vector<int> tree[NMAX];
int n;

int dpPaired[NMAX], dp[NMAX];
int treeSize[NMAX];
int nPerf[NMAX], nPart[NMAX];
bool fullMatch[NMAX];
bool partMatch[NMAX];

int64_t ans = 0;

void dfs(int node, int prev) {
    if (prev != -1) {
        tree[node].erase(find(tree[node].begin(), tree[node].end(), prev));
    }
    int perf = 0;
    int part = 0;
    treeSize[node] = 1;
    for (int to: tree[node]) {
        dfs(to, node);
        treeSize[node] += treeSize[to];
        part += partMatch[to];
        perf += fullMatch[to];
    }
    if (perf == SZ(tree[node]) - 1 && part == 1) {
        fullMatch[node] = true;
    }
    if (perf == SZ(tree[node])) {
        partMatch[node] = true;
    }
    if (SZ(tree[node]) == 0) {
        dpPaired[node] = 0;
        dp[node] = 1;
    } else {
        for (int to: tree[node]) {
            perf -= fullMatch[to];
            part -= partMatch[to];
            // Calc dp[node]
            if (perf == SZ(tree[node]) - 1) {
                dp[node] += dpPaired[to];
            }
            if (perf == SZ(tree[node]) - 2 && part == 1) {
                dp[node] += dp[to];
            }
            // Calc dpPaired[node]
            if (perf == SZ(tree[node]) - 1) {
                dpPaired[node] += dp[to];
            }
            perf += fullMatch[to];
            part += partMatch[to];
        }
        if (perf == SZ(tree[node])) {
            dp[node]++;
        }
    }
    nPerf[node] = perf;
    nPart[node] = part;
}

int64_t justEven = 0;

void dfs2(int node, int prev, int up, int upPaired, bool upMatching, bool upPart) {
    if (prev != -1) {
        ans += (int64_t) dp[node] * up;
        if (fullMatch[node] && upMatching) {
            ans += (int64_t) treeSize[node] * (n - treeSize[node]);
            justEven += (int64_t) treeSize[node] * (n - treeSize[node]);
        }
    }
    int perf = nPerf[node] + upMatching;
    int part = nPart[node] + upPart;
    int sdp[2][2];
    memset(sdp, 0, sizeof sdp);
    int sdpPaired[2][2];
    memset(sdpPaired, 0, sizeof sdpPaired);
    for (int to: tree[node]) {
        sdp[(int) fullMatch[to]][(int) partMatch[to]] += dp[to];
        sdpPaired[(int) fullMatch[to]][(int) partMatch[to]] += dpPaired[to];
    }
    sdp[(int) upMatching][(int) upPart] += up;
    sdpPaired[(int) upMatching][(int) upPart] += upPaired;
    for (int to: tree[node]) {
        perf -= fullMatch[to];
        part -= partMatch[to];
        sdp[(int) fullMatch[to]][(int) partMatch[to]] -= dp[to];
        sdpPaired[(int) fullMatch[to]][(int) partMatch[to]] -= dpPaired[to];

        int son = 0, sonPaired = 0;
        for (int u = 0; u < 2; ++u) {
            for (int v = 0; v < 2; ++v) {
                perf -= u;
                part -= v;
                // Calc dp[node]
                if (perf == SZ(tree[node]) - 1) {
                    son += sdpPaired[u][v];
                }
                if (perf == SZ(tree[node]) - 2 && part == 1) {
                    son += sdp[u][v];
                }
                // Calc dpPaired[node]
                if (perf == SZ(tree[node]) - 1) {
                    sonPaired += sdp[u][v];
                }
                perf += u;
                part += v;
            }
        }
        if (perf == SZ(tree[node])) {
            son++;
        }
        bool sonMatching = perf == SZ(tree[node]) - 1 && part == 1;
        bool sonPart = perf == SZ(tree[node]);
        dfs2(to, node, son, sonPaired, sonMatching, sonPart);

        sdp[(int) fullMatch[to]][(int) partMatch[to]] += dp[to];
        sdpPaired[(int) fullMatch[to]][(int) partMatch[to]] += dpPaired[to];
        perf += fullMatch[to];
        part += partMatch[to];
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

    cin >> n;
    if (n % 2 == 1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0, -1);
    dfs2(0, -1, 0, 0, true, false);
    cout << ans << '\n';
}