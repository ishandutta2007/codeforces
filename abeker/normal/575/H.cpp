#include <cstdio>
using namespace std;

const int MOD = 1000000007;

int N;

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

inline int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

void load() {
    scanf("%d", &N);
}

int solve() {
    int fact = 1, val;
    for (int i = 1; i <= 2 * N + 2; i++) {
        fact = mul(fact, i);
        if (i == N + 1) val = fact;
    }
    return mul(fact, pow(mul(val, val), MOD - 2)) - 1;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}