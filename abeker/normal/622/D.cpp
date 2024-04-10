#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    if (N % 2) {
        for (int i = 1; i <= N; i += 2)
            printf("%d ", i);
        for (int i = N - 2; i >= 1; i -= 2)
            printf("%d ", i);
        for (int i = 2; i < N; i += 2)
            printf("%d ", i);
        for (int i = N - 1; i >= 2; i -= 2)
            printf("%d ", i);
        printf("%d\n", N);
    }
    else {
        for (int i = 1; i < N; i += 2)
            printf("%d ", i);
        for (int i = N - 1; i >= 1; i -= 2)
            printf("%d ", i);
        for (int i = 2; i <= N; i += 2)
            printf("%d ", i);
        for (int i = N - 2; i >= 2; i -= 2)
            printf("%d ", i);
        printf("%d\n", N);
    }
    return 0;
}