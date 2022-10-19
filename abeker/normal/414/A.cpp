#include <cstdio>
#include <cstdlib>
using namespace std;

int N, K;

void load() {
    scanf("%d%d", &N, &K);
}

void fail() {
    puts("-1");
    exit(0);
}

int get(int a, int b) {
    return a + b - a % b;
}

void solve() {
    if (N == 1) {
        if (K) fail();
        puts("1");
        return;
    }
    if (K < N / 2) fail();
    for (int i = 0; i < N - N % 2 - 2; i++)
        printf("%d ", i + 1);
    K -= N / 2 - 1;
    int tmp = get(N - N % 2 - 2, K);
    printf("%d %d", tmp, tmp + K);
    if (N % 2) printf(" %d", tmp + K + 1);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}