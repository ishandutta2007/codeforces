#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Nmax = 405;

char A[Nmax][Nmax], B[Nmax][Nmax], C[Nmax][Nmax], D[Nmax][Nmax];

int S1[Nmax][Nmax], S2[Nmax][Nmax];

int Solve(char A[][Nmax], const int N, const int M)
{
    memset(S1, 0, sizeof(S1));
    memset(S2, 0, sizeof(S2));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i][j] == '0')
            {
                S1[i][j] = S1[i - 1][j + 1] + 1;
                S2[i][j] = S2[i - 1][j] + 1;
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i][j] == '1') continue;

            for (int k = 1; i - k > 0 && j - k > 0; k++)
            {
                if (A[i - k][j] == '1' || A[i][j - k] == '1')
                    break;

                if (S1[i][j - k] > k)
                    ret++;
            }

            for (int k = 1; i - k > 0 && i + k <= N && j - k > 0; k++)
            {
                if (A[i - k][j - k] == '1' || A[i + k][j - k] == '1')
                    break;

                if (i + k - S2[i + k][j - k] < i - k)
                    ret++;
            }
        }
    }

    return ret;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    cin.get();

    for (int i = 1; i <= N; i++)
    {
        cin.getline(A[i] + 1, Nmax);
        for (int j = 1; j <= M; j++)
        {
            B[j][N - i + 1] = A[i][j];
            C[N - i + 1][M - j + 1] = A[i][j];
            D[M - j + 1][i] = A[i][j];
        }
    }

    int Sol = 0;
    Sol += Solve(A, N, M);
    Sol += Solve(B, M, N);
    Sol += Solve(C, N, M);
    Sol += Solve(D, M, N);

    cout << Sol << "\n";
}