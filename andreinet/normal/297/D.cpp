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

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> A(2 * n - 1);

    int cnte = 0, cnt = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        cin >> A[i];
        cnte += count(A[i].begin(), A[i].end(), 'E');
        cnt += SZ(A[i]);
    }
    
    if (k == 1) {
        if (cnte * 4 < 3 * cnt) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << "1 ";
                }
                cout << '\n';
            }
        }
    } else if (m > n) {
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            ans[i][0] = 0;
            for (int j = 1; j < m; ++j) {
                ans[i][j] = (A[2 * i][j - 1] == 'N') ^ ans[i][j - 1];
            }
            if (i > 0) {
                int cnt = 0;
                for (int j = 0; j < m; ++j) {
                    cnt += ans[i][j] ^ ans[i - 1][j] ^ (A[2 * i - 1][j] == 'N');
                }
                if (2 * cnt > m) {
                    for (int j = 0; j < m; ++j) {
                        ans[i][j] ^= 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "YES\n";
        vector<vector<int>> ans(n, vector<int>(m));
        for (int j = 0; j < m; ++j) {
            ans[0][j] = 0;
            for (int i = 1; i < n; ++i) {
                ans[i][j] = (A[2 * i - 1][j] == 'N') ^ ans[i - 1][j];
            }
            if (j > 0) {
                int cnt = 0;
                for (int i = 0; i < n; ++i) {
                    cnt += ans[i][j] ^ ans[i][j - 1] ^ (A[2 * i][j - 1] == 'N');
                }
                if (2 * cnt > n) {
                    for (int i = 0; i < n; ++i) {
                        ans[i][j] ^= 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j] + 1 << ' ';
            }
            cout << '\n';
        }
    }
}