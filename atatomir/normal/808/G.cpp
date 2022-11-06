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

#define maxN 100011
#define sigma 26
#define inf 1000000000

int n, m, i, j, u;
char s[maxN], t[maxN];
int pr[maxN], go[maxN][sigma];

int ss, dd;
int dp[2][maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s\n%s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);

    pr[1] = u = 0;
    for (i = 2; i <= m; i++) {
        while (u != 0 && t[u + 1] != t[i]) u = pr[u];
        if (t[u + 1] == t[i]) u++;
        pr[i] = u;
    }

    go[0][t[1] - 'a'] = 1;
    for (i = 1; i <= m; i++) {
        for (j = 0; j < sigma; j++)
            go[i][j] = go[pr[i]][j];
        if (i != m)
            go[i][t[i + 1] - 'a'] = i + 1;
    }

    ss = 0; dd = 1;
    dp[ss][0] = 0;
    for (i = 1; i <= m; i++) dp[ss][i] = -inf;

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m; j++)
            dp[dd][j] = -inf;

        for (j = 0; j <= m; j++) {
            if (dp[ss][j] < 0) continue;

            if (s[i] != '?') {
                dp[dd][ go[j][s[i] - 'a'] ] = max(dp[dd][ go[j][s[i] - 'a'] ], dp[ss][j] + (go[j][s[i] - 'a'] == m));
            } else {
                for (int ch = 0; ch < sigma; ch++)
                    dp[dd][go[j][ch]] = max(dp[dd][go[j][ch]], dp[ss][j] + (go[j][ch] == m));
            }
        }

        swap(ss, dd);
    }

    int ans = 0;
    for (i = 0; i <= m; i++)
        ans = max(ans, dp[ss][i]);

    cout << ans;

    return 0;
}