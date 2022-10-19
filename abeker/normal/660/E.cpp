#include <cstdio>
using namespace std;

const int MOD = 1000000007;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int sol = pow(M, N);
    for (int i = 1; i <= N; i++)
        sol = add(sol, mul(pow(2 * M - 1, i - 1), pow(M, N - i + 1)));
    printf("%d\n", sol);
    return 0;
}