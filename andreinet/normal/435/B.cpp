#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char B[1000];

int main()
{
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int N, K;
    scanf("%s %d", &B, &K);

    N = strlen(B);

    for (int i = 0; K && i < N; i++)
    {
        int maxs = i;
        for (int j = i + 1; j < N && j - i <= K; j++)
        {
            if (B[j] > B[maxs])
                maxs = j;
        }

        K -= maxs - i;
        for (int j = maxs; j > i; j--)
            swap(B[j], B[j - 1]);
    }

    printf("%s\n", B);
}