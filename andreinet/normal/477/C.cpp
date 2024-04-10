#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 2005, Inf = 0x3f3f3f3f;

char A[Nmax], B[Nmax];
int Ans[Nmax], Pos[Nmax];
int Dp[Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    fgets(A + 1, Nmax, stdin);
    fgets(B + 1, Nmax, stdin);

    int N = strlen(A + 1) - 1, M = strlen(B + 1) - 1;

    for (int i = 1; i <= N; ++i) {
        int pos = i;
        for (int j = M; j; --j) {
            while (A[pos] != B[j] && pos)
                pos--;
            --pos;

            if (pos < 0)
                break;
        }

        Pos[i] = pos;
    }

    for (int i = 1; i <= N; ++i)
        Dp[0][i] = -Inf;

    for (int i = 1; i <= N; ++i) {
        int pos = Pos[i], cost = i - pos - M;
        for (int j = 0; j <= i; ++j) {
            Dp[i][j] = max(Dp[i][j], Dp[i - 1][j]);
            if (pos >= 0 && j - cost >= 0)
                Dp[i][j] = max(Dp[i][j], Dp[pos][j - cost] + 1);
        }

        for (int j = i + 1; j <= N; ++j)
            Dp[i][j] = -Inf;
    }

    for (int i = 0; i <= N; ++i)
        printf("%d ", Dp[N][i]);

    printf("\n");
}