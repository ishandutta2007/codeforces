#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 505;

int A[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1, v = n * n; i <= n; ++i) {
        for (int j = n; j >= k; --j) {
            A[i][j] = v--;
        }
    }
    int64_t ans = 0;
    for (int i = 1, v = 1; i <= n; ++i) {
       for (int j = 1; j < k; ++j) {
           A[i][j] = v++;
       }
       ans += A[i][k];
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}