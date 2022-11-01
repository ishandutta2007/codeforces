#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef long double ldouble;
const int NMAX = 2005;

int A[NMAX];
int leftMost[NMAX], rightMost[NMAX];
double dp[NMAX][NMAX][2][2];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, h;
    cin >> n >> h;

    ldouble fall;
    cin >> fall;

    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    sort(A + 1, A + n + 1);

    leftMost[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (A[i] - h < A[i - 1]) leftMost[i] = leftMost[i - 1];
        else leftMost[i] = i;
    }
    rightMost[n] = n;
    for (int i = n - 1; i > 0; --i) {
        if (A[i] + h > A[i + 1]) rightMost[i] = rightMost[i + 1];
        else rightMost[i] = i;
    }

    /*for (int i = 0; i <= n; ++i)
        for (int ki = 0; ki < 2; ++ki)
            for (int kj = 0; kj < 2; ++kj)
                dp[i + 1][i][ki][kj] = 1;*/

    A[0] = -400000000;
    A[n + 1] = 400000000;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 0; --j) {
            int left = j, right = i;
            for (int ki = 0; ki < 2; ++ki) {
                for (int kj = 0; kj < 2; ++kj) {
                    {
                        // Left falls left
                        double add = dp[left + 1][right][0][kj];
                        double p = fall * 0.5;
                        dp[left][right][ki][kj] += add * p;
                        if (ki) add = min(h, A[left] - (A[left - 1] + h));
                        else add = min(h, A[left] - A[left - 1]);
                        dp[left][right][ki][kj] += add * p;
                    }
                    {
                        // Right falls right
                        double add = dp[left][right - 1][ki][0];
                        double p = (1 - fall) * 0.5;
                        dp[left][right][ki][kj] += add * p;
                        if (kj) add = min(h, A[right + 1] - (A[right] + h));
                        else add = min(h, A[right + 1] - A[right]);
                        dp[left][right][ki][kj] += add * p;
                    }
                    {
                        // Left falls right
                        int to = min(rightMost[left], right);
                        double add = dp[to + 1][right][1][kj];
                        double p = (1 - fall) * 0.5;
                        dp[left][right][ki][kj] += add * p;
                        add = A[to] - A[left];
                        if (to < right
                                || !kj) add += min(h, A[to + 1] - A[to]);
                        else add += min(h, A[to + 1] - (A[to] + h));
                        dp[left][right][ki][kj] += add * p;
                    }
                    {
                        // Right falls left
                        int to = max(leftMost[right], left);
                        double add = dp[left][to - 1][ki][1];
                        double p = fall * 0.5;
                        dp[left][right][ki][kj] += add * p;
                        add = A[right] - A[to];
                        if (to > left
                                || !ki) add += min(h, A[to] - A[to - 1]);
                        else add += min(h, A[to] - (A[to - 1] + h));
                        dp[left][right][ki][kj] += add * p;
                    }
                }
            }
        }
    }
    double ans = dp[1][n][0][0];

    cout << setprecision(14) << fixed;
    cout << ans << '\n';
}