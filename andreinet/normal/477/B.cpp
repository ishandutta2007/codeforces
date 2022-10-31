#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, K;
    scanf("%d%d", &N, &K);

    printf("%d\n", K * (5 + (N - 1) * 6));
    printf("%d %d %d %d\n", K * 1, K * 2, K * 3, K * 5);
    for (int i = 0; i < N - 1; ++i) {
        int begin = 5 + i * 6 + 2;
        printf("%d %d %d %d\n", K * begin, K * (begin + 1), K * (begin + 2), K * (begin + 4));
    }
}