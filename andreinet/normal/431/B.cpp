#include <algorithm>
#include <cstdio>

using namespace std;

int A[6], C[6][6];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    const int N = 5;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &C[i][j]);

    for (int i = 1; i <= N; i++)
        A[i] = i;

    int Sol = 0;
    do
    {
        int S = 0;
        for (int i = 1; i < N; i++)
        {
            S += C[A[i]][A[i + 1]] * ((i + 1) / 2);
            S += C[A[i + 1]][A[i]] * ((i + 1) / 2);
        }

        Sol = max(Sol, S);
    }
    while (next_permutation(A + 1, A + N + 1));

    printf("%d\n", Sol);
}