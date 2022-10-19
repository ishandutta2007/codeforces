#include<bits/stdc++.h>

using namespace std;

const int maxN = 1000009, INF = 2 * maxN;
int N, dp[maxN][2][2];
char s[maxN];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
while (tests --)
{
    scanf ("%s\n", s + 1);
    N = strlen (s + 1);
    if (N == 1)
    {
        printf ("0\n");
        continue;
    }
    for (int i=1; i<=N; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                dp[i][j][k] = INF;
    dp[2][0][1] = dp[2][1][0] = 1;
    dp[2][1][1] = 2;
    dp[2][0][0] = (s[1] == s[2] ? INF : 0);
    for (int i=2; i<N; i++)
        for (int j=0; j<2; j++)
            for (int k=0; k<2; k++)
                if (dp[i][j][k] < INF)
                    for (int p=0; p<2; p++)
                    {
                        if (p == 0 && k == 0 && s[i] == s[i + 1]) continue;
                        if (p == 0 && j == 0 && s[i - 1] == s[i + 1]) continue;
                        dp[i + 1][k][p] = min (dp[i + 1][k][p], dp[i][j][k] + p);
                    }
    int ans = INF;
    for (int j=0; j<2; j++)
        for (int k=0; k<2; k++)
            ans = min (ans, dp[N][j][k]);
    printf ("%d\n", ans);
}

return 0;
}