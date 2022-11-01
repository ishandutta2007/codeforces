#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005;

int A[Nmax], GoodL[Nmax], GoodR[Nmax], Left[Nmax];

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

    GoodL[0] = GoodR[N + 1] = 1;
    GoodL[1] = GoodR[N] = 1;
    Left[1] = 1;

    A[N + 1] = 0x3f3f3f3f;

    for (int i = 2; i <= N; i++)
    {
        if (A[i] >= A[i - 1])
        {
            GoodL[i] = GoodL[i - 1];
            Left[i] = i;
        }
        else
            Left[i] = Left[i - 1];
    }

    for (int i = N - 1; i; i--)
    {
        if (A[i] <= A[i + 1])
            GoodR[i] = GoodR[i + 1];
    }

    for (int i = 1; i <= N; i++)
    {
        if (GoodL[Left[i] - 1] && GoodR[i + 1] && A[i] >= A[Left[i] - 1] && A[Left[i]] <= A[i + 1])
        {
            printf("yes\n%d %d\n", Left[i], i);
            return 0;
        }
    }

    printf("no\n");
}