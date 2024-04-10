#include <algorithm>
#include <cstdio>

using namespace std;

const int Nmax = 2005;

int A[Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, K;
    scanf("%d%d", &N, &K);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);

    sort(A + 1, A + N + 1);

    int ans = 0;
    for (int i = N; i > 0; i -= K) {
        ans += A[i] - 1;
    }

    printf("%d\n", ans * 2);
}