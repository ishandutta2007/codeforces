#include <cstdio>
using namespace std;

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int sum = 0;
    for (int i = 0; i < K; i++) {
        int m; scanf("%d", &m);
        for (int j = 1; j <= m; j++) {
            int x; scanf("%d", &x);
            sum += x == j;
        }
    }
    printf("%d\n", 2 * (N - sum) - K + 1);
    return 0;
}