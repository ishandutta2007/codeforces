#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 505, Inf = 0x3f3f3f3f;

char A[Nmax];
int Cost[Nmax][Nmax];
int Dp[Nmax][Nmax], Next[Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    fgets(A + 1, Nmax, stdin);
    const int N = strlen(A + 1) - 1;

    int K;
    scanf("%d", &K);

    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; ++j) {
            int s = 0;

            for (int k = 0; k < (j - i + 1) / 2 ; ++k)
                if (A[i + k] != A[j - k])
                    ++s;

            Cost[i][j] = s;
        }
    }

    memset(Dp, Inf, sizeof(Dp));
    Dp[0][0] = 0;

    int Ans = Inf, Ansp = 0;
    for (int j = 1; j <= K; ++j) {
        for (int i = 1; i <= N; ++i) {
            for (int k = i - 1; k >= 0; --k) {
                if (Dp[j][i] > Dp[j - 1][k] + Cost[k + 1][i]) {
                    Dp[j][i] = Dp[j - 1][k] + Cost[k + 1][i];
                    Next[j][i] = k;
                }
            }

            if (Dp[j][N] < Ans) {
                Ans = Dp[j][N];
                Ansp = j;
            }
        }
    }

    printf("%d\n", Ans);
    string Sol;

    for (int j = Ansp, i = N; i > 0;) {
        int p = Next[j][i] + 1;

        if (Sol.length() > 0U)
            Sol += '+';

        for (int k = 0; k < (i - p + 1); ++k)
            Sol += min(A[p + k], A[i - k]);

        i = p - 1;
        --j;
    }

    reverse(Sol.begin(), Sol.end());
    cout << Sol << '\n';
}