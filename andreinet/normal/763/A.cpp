#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 100005;

vector<int> G[NMAX];
int values[NMAX];
bool oneColor[NMAX];

void dfs(int node, int prev) {
    oneColor[node] = true;
    for (int to: G[node]) {
        if (to != prev) {
            dfs(to, node);
            if (!oneColor[to] || values[node] != values[to]) {
                oneColor[node] = false;
            }
        }
    }
}

int sol = -1;

void dfs2(int node, int prev, bool upColor = true) {
    bool good = upColor;
    int cntBad = 1 - upColor;
    int cntBadCol = 0;
    if (prev != -1) {
        cntBadCol += values[node] != values[prev];
    }
    for (int to: G[node]) {
        if (to != prev) {
            good &= oneColor[to];
            cntBad += 1 - oneColor[to];
            cntBadCol += values[node] != values[to];
        }
    }
    if (good) {
        sol = node;
        return;
    }
    for (int to: G[node]) {
        if (to != prev) {
            bool ngood = !(cntBad - (1 - oneColor[to]));
            int ncntBadCol = cntBadCol - (values[node] != values[to]);
            if (ncntBadCol) {
                ngood = false;
            }
            if (ngood) {
                dfs2(to, node, ngood);
            }
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

    int n;
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }
    dfs(1, -1);
    dfs2(1, -1);
    if (sol == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n" << sol << '\n';
    }
}