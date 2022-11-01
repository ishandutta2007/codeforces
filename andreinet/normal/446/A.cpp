#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 100005, INF = 0x3f3f3f3f;

int A[Nmax];
int St[Nmax], Dr[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif

    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    if (N == 1)
    {
        printf("1\n");
        return 0;
    }

    A[0] = A[1];

    int Sol = 0;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] > A[i - 1])
            St[i] = St[i - 1];
        else
            St[i] = i;

        Sol = max(Sol, i - St[i] + 1);
    }

    A[N + 1] = A[N];
    for (int i = N; i; i--)
    {
        if (A[i] < A[i + 1])
            Dr[i] = Dr[i + 1];
        else
            Dr[i] = i;
    }

    for (int i = 2; i < N; i++)
    {
        if (A[i + 1] - A[i - 1] >= 2)
        {
            Sol = max(Sol, Dr[i + 1] - St[i - 1] + 1);
        }
    }

    for (int i = 1; i < N; i++)
        Sol = max(Sol, Dr[i + 1] - i + 1);
    for (int i = 2; i <= N; i++)
        Sol = max(Sol, i - St[i - 1] + 1);

    printf("%d\n", Sol);
}