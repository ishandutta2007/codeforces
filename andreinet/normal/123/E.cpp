#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;

vector<int> G[NMAX];
int valueA[NMAX], valueB[NMAX];
int subtreeB[NMAX], subtree[NMAX];
double expLenDown[NMAX];

double ans = 0;
int sumA = 0;

void dfs1(int node, int prev) {
    subtreeB[node] = valueB[node];
    subtree[node] = 1;
    for (int to: G[node]) {
        if (to != prev) {
            dfs1(to, node);
            subtreeB[node] += subtreeB[to];
            subtree[node] += subtree[to];
        }
    }
    if (subtreeB[node] == 0) {
        expLenDown[node] = 0;
        return;
    }
    for (int to: G[node]) {
        if (to != prev) {
            expLenDown[node] += (1 + expLenDown[to] + (subtree[node] - 1 - subtree[to]))
                * subtreeB[to];
        }
    }
    expLenDown[node] /= subtreeB[node];
}

int n;

void dfs2(int node, int prev, double dpUp = 0) {
    double cdp = 0;
    for (int to: G[node]) {
        if (to != prev) {
            cdp += subtreeB[to] * (1 + expLenDown[to] + n - 1 - subtree[to]);
        }
    }
    if (prev != -1) {
        cdp += (subtreeB[1] - subtreeB[node]) * 
                (dpUp + 1 + subtree[node] - 1);
    }
    ans += cdp / subtreeB[1] * ((double) valueA[node] / sumA);

    for (int to: G[node]) {
        if (to != prev) {
            double dpd = cdp - subtreeB[to] *
                (1 + expLenDown[to] + n - 1 - subtree[to]);
            dpd -= (int64_t) (subtreeB[1] - valueB[node] - subtreeB[to]) * subtree[to];
            dpd /= subtreeB[1] - subtreeB[to];
            if (subtreeB[1] - subtreeB[to] == 0) {
                dpd = 0;
            }
            dfs2(to, node, dpd);
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

    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> valueA[i] >> valueB[i];
        sumA += valueA[i];
    }

    dfs1(1, -1);
    dfs2(1, -1);

    cout << setprecision(12) << fixed;
    cout << ans << '\n';
}