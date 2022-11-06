#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 5011;
const int inf = 1000000000;

int n, i, j, ss, dd, here;
int a[maxN];

int dp[2][maxN][3];
int best[maxN];

void clr(int tp) {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            dp[tp][i][j] = inf;
}

void upd(int& a, int b) {
    if (a > b) a = b;
}

int dif(int low, int high) {
    if (low < high) return 0;
    return low - high + 1;
}

void solve() {
    int i, j, k;

    ss = 0; dd = 1;
    clr(ss);
    dp[ss][0][0] = 0;

    for (i = 1; i <= n; i++) {
        clr(dd);
        here = i / 2;

        for (j = 0; j <= here; j++) {
            upd(dp[dd][j + 1][1], dp[ss][j][0] + dif(a[i - 1], a[i]) );
            upd(dp[dd][j][0], dp[ss][j][0]);

            upd(dp[dd][j][2], dp[ss][j][1]);

            if (i > 1) {
                upd(dp[dd][j][0], dp[ss][j][2] + dif(a[i - 1], a[i - 2]));
                upd(dp[dd][j + 1][1], dp[ss][j][2] + dif(a[i - 1], min(a[i - 2], a[i])));
            }
        }

        swap(ss, dd);
    }

    here = (n + 1) / 2;
    for (i = 1; i <= here; i++)
        best[i] = min(dp[ss][i][0], min(dp[ss][i][1], dp[ss][i][2] + dif(a[n], a[n - 1])));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    a[0] = a[n + 1] = -1;
    solve();

    for (i = 1; i <= here; i++)
        printf("%d ", best[i]);


    return 0;
}