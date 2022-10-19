#include <cstdio>
using namespace std;

typedef long long ll;

ll choose(int x) {
    if (x < 0) return 0;
    return (ll)x * (x - 1) / 2;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    printf("%I64d\n", choose(N) - choose(N - 2 * K));
    return 0;
}