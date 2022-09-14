#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>


using namespace std;

const int MAXN = 160;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, s;
    cin >> n >> m >> s;
    s = min(s, n * (n - 1) / 2);
    int a[MAXN];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dpnext[MAXN][MAXN * MAXN];
    int dpprev[MAXN][MAXN * MAXN];
    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= s; j++)
            dpprev[i][j] = 1000000000;
    for (int j = 0; j <= s; j++)
        dpprev[0][j] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int k = 0; k <= s; k++)
            dpnext[0][k] = 0;
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= s; k++)
                dpnext[j][k] = min(a[i] + dpprev[j - 1][k],
                                   (k >= j ? dpprev[j][k - j] : 1000000000));
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= s; k++)
                dpprev[j][k] = dpnext[j][k];
    }
    cout << dpprev[m][s] << endl;
    return 0;
}