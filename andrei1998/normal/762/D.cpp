#include <iostream>

#define lint long long int
using namespace std;

const int NMAX = 100000 + 5;
const lint INF = 2E18 + 15;

int N;
int a[3][NMAX];
lint dp[NMAX][3];

void upd(lint &where, lint val) {
    if (val > where)
        where = val;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 3; ++ i)
        for (int j = 1; j <= N; ++ j)
            cin >> a[i][j];

    for (int i = 0; i < 3; ++ i)
        for (int j = 1; j <= N + 1; ++ j)
            dp[j][i] = -INF;
    dp[1][0] = a[0][1];

    for (int i = 1; i <= N; ++ i) {
        upd(dp[i + 1][0], dp[i][0] + a[0][i + 1]);
        upd(dp[i + 1][0], dp[i][1] + a[0][i] + a[0][i + 1]);
        upd(dp[i + 1][0], dp[i][2] + a[1][i] + a[0][i] + a[0][i + 1]);

        upd(dp[i + 1][1], dp[i][0] + a[1][i] + a[1][i + 1]);
        upd(dp[i + 1][1], dp[i][1] + a[1][i + 1]);
        upd(dp[i + 1][1], dp[i][2] + a[1][i] + a[1][i + 1]);

        upd(dp[i + 1][2], dp[i][0] + a[1][i] + a[2][i] + a[2][i + 1]);
        upd(dp[i + 1][2], dp[i][1] + a[2][i] + a[2][i + 1]);
        upd(dp[i + 1][2], dp[i][2] + a[2][i + 1]);

        upd(dp[i + 2][0], dp[i][2] + a[2][i + 1] + a[1][i] + a[1][i + 1] + a[0][i] + a[0][i + 1] + a[0][i + 2]);
        upd(dp[i + 2][2], dp[i][0] + a[2][i + 1] + a[1][i] + a[1][i + 1] + a[2][i] + a[0][i + 1] + a[2][i + 2]);
    }

    lint ans = max(max(dp[N][2], max(dp[N][1] + a[2][N], dp[N][0] + a[1][N] + a[2][N])), dp[N + 1][2]);
    cout << ans << '\n';
    return 0;
}