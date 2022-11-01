#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;
const int NMAX = 105;

char A[NMAX][NMAX];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> A[i] + 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
            cnt += A[i][j] == 'C';
        ans += cnt * (cnt - 1) / 2;
    }

    for (int j = 1; j <= n; ++j) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += A[i][j] == 'C';
        }
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}