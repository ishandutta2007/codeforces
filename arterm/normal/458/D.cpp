#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

#define M 303

long double c[M][M], p[M * M];
int n, m, k;

void pre() {
    for (int i = 0; i < M; ++i)
        c[i][0] = 1.0;

    for (int i = 1; i < M; ++i)
    for (int j = 1; j < M; ++j)
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}

void kill() {
    cin >> n >> m >> k;

    p[0] = 1.0;
    for (int i = 1; i <= n * n && i <= k; ++i)
        p[i] = p[i - 1] * (k - i + 1) / (m - i + 1);

    long double ans = 0;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j) {
            int t = n * (i + j) - i * j;
            ans = ans + c[n][i] * c[n][j] * p[t];
            if (ans > 1e99) {
                cout << "1e99\n";
                return;
            }
        }


    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cout.precision(10);
    cout << fixed;

    pre();

    kill();

    return 0;
}