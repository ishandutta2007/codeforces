#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 505;

char A[NMAX][NMAX];
int sum[NMAX][NMAX];
int cright[NMAX][NMAX], cdown[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> (A[i] + 1);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c = 0;
            if (A[i][j] == '.' && A[i - 1][j] == '.') c++;
            if (A[i][j] == '.' && A[i][j - 1] == '.') c++;
            sum[i][j] = c + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

            c = 0;
            if (A[i][j] == '.' && A[i][j + 1] == '.') c++;
            cright[i][j] = cright[i - 1][j] + c;

            c = 0;
            if (A[i][j] == '.' && A[i + 1][j] == '.') c++;
            cdown[i][j] = cdown[i][j - 1] + c;
        }
    }

    int q;
    cin >> q;

    while (q-- > 0) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int ans = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] +
            sum[r1 - 1][c1 - 1];
        ans -= cright[r2][c1 - 1] - cright[r1 - 1][c1 - 1];
        ans -= cdown[r1 - 1][c2] - cdown[r1 - 1][c1 - 1];

        cout << ans << '\n';
    }
}