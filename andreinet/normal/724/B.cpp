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

    for (int c1 = 0; c1 < m; ++c1) {
        for (int c2 = c1; c2 < m; ++c2) {
            vector<vector<int>> B = A;
            for (int i = 0; i < n; ++i) {
                swap(B[i][c1], B[i][c2]);
            }
            int can = 0;
            for (const vector<int>& a: B) {
                int cnt = 0;
                for (int i = 0; i < m; ++i) {
                    if (a[i] != i + 1) {
                        cnt++;
                    }
                }
                can += (cnt <= 2);
            }
            if (can == n) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}