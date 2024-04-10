#include <cstdio>
using namespace std;

int K;

void load() {
    scanf("%d", &K);
}

void solve() {
    if (!(K % 2)) {
        puts("NO");
        return;
    }
    puts("YES");
    int N = K * K + 2 * K - 1;
    printf("%d %d\n", N, N * K / 2);
    for (int it = 0; it < 2; it++) {
        for (int i = 0; i < K / 2; i++) {
            for (int j = 0; j < K + 1; j++)
                for (int k = 0; k < j; k++)
                    if (j + k > 1) printf("%d %d\n", it * N / 2 + i * (K + 1) + j + 1, it * N / 2 + i * (K + 1) + k + 1);
            printf("%d %d\n", it * N / 2 + i * (K + 1) + 1, it * N / 2 + K / 2 * (K + 1) + 2 * i + 1);
            printf("%d %d\n", it * N / 2 + i * (K + 1) + 2, it * N / 2 + K / 2 * (K + 1) + 2 * i + 2);
        }
        for (int i = 0; i < K; i++)
            for (int j = 0; j < i; j++)
                printf("%d %d\n", it * N / 2 + K / 2 * (K + 1) + i + 1, it * N / 2 + K / 2 * (K + 1) + j + 1);
    }
    printf("%d %d\n", N / 2, N);
}

int main() {
    load();
    solve();
    return 0;
}