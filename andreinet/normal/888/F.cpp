#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = (int) 1e9 + 7;

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

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            graph[i][j] = x;
        }
    }

    vector<vector<int>> dpUn(n, vector<int>(n, 0));
    vector<vector<int>> dpDis(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dpUn[i][i] = dpDis[i][i] = 1;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (graph[i][i + 1]) {
            dpDis[i][i + 1] = 1;
        }
        dpUn[i][i + 1] = 1;
    }
    for (int len = 3; len <= n; ++len) {
        for (int left = 0; left + len <= n; ++left) {
            int right = left + len - 1;
            for (int mid = left + 1; mid <= right; ++mid) {
                if (graph[mid][right]) {
                    dpUn[left][right] = (dpUn[left][right] +
                            dpUn[left][mid] * (int64_t) dpUn[mid][right]) % MOD;
                }
            }
            dpUn[left][right] = (dpUn[left][right] + dpDis[left][right - 1]) % MOD;
            for (int mid = left + 1; mid <= right; ++mid) {
                if (graph[left][mid]) {
                    dpDis[left][right] = (dpDis[left][right] + 
                            dpUn[left][mid] * (int64_t) dpDis[mid][right]) % MOD;
                }
            }
        }
    }
    cout << dpDis[0][n - 1] << '\n';
}