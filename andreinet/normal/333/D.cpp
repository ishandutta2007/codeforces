#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

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

    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<bool>> pairs(m, vector<bool>(m));

    int ans = 0;
    for (int step = 1 << 30; step > 0; step /= 2) {
        int minVal = ans + step;
        for (vector<bool>& p: pairs) {
            fill(p.begin(), p.end(), false);
        }
        bool can = false;
        for (int i = 0; i < n; ++i) {
            vector<int> cols;
            for (int j = 0; j < m; ++j) {
                if (A[i][j] >= minVal) {
                    cols.push_back(j);
                }
            }
            for (int j = 0; j < SZ(cols); ++j) {
                for (int k = 0; k < j; ++k) {
                    if (pairs[cols[j]][cols[k]]) {
                        can = true;
                        goto OUT;
                    }
                    pairs[cols[j]][cols[k]] = true;
                }
            }
        }
        OUT:;
        if (can) {
            ans = minVal;
        }
    }

    cout << ans << '\n';
}