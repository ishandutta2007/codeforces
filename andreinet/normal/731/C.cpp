#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int NMAX = 200005;

vector<int> G[NMAX];

int values[NMAX];
bool used[NMAX];

vector<int> colors;
int countColors[NMAX];

void dfs(int node) {
    used[node] = true;
    colors.push_back(values[node]);
    countColors[values[node]]++;
    for (int to: G[node]) {
        if (!used[to]) {
            dfs(to);
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

    int n, m, k;
    cin >> n >> m >> k;


    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    while (m-- > 0) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
            int vmax = 0;
            for (int x: colors) {
                vmax = max(vmax, countColors[x]);
            }
            ans += SZ(colors) - vmax;
            for (int x: colors) {
                countColors[x] = 0;
            }
            colors.clear();
        }
    }
    cout << ans << '\n';
}