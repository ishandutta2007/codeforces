#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 5015
#define mod 1000000007

int n, i, j;
char s[maxN];

int dp[maxN][maxN];

int how[maxN][maxN];
int sum[maxN][maxN];

void compute_dp() {
    int i, j;

    for (i = n; i > 0; i--) {
        for (j = i + 1; j <= n; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = 0;
        }
    }
}

void compute_how() {
    int i, j;

    how[0][0] = 1;
    sum[0][0] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            how[i][j] += sum[i - j][min(j - 1, i - j)] ;

            if (2 * j <= i) {
                int good = dp[i - 2 * j + 1][i - j + 1];
                if (good < j && s[ i - 2 * j + 1 + good ] < s[i - j + 1 + good])
                    how[i][j] += how[i - j][j];
            }

            while (how[i][j] >= mod)
                how[i][j] -= mod;

            sum[i][j] = how[i][j];
            if (s[i + 1] == '0')
                sum[i][j] = 0;
            sum[i][j] += sum[i][j - 1];
            while (sum[i][j] >= mod)
                sum[i][j] -= mod;
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    s[n + 1] = '!';
    compute_dp();
    compute_how();

    printf("%d", sum[n][n]);

    return 0;
}