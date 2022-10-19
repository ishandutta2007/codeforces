#include <cstdio>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

int pow(int x, ll y) {
    int res = 1;
    for (; y; y >>= 1ll) {
        if (y & 1ll) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int main() {
    ll N;
    scanf("%I64d", &N);
    if (!N) {
        puts("1");
        return 0;
    }
    printf("%d\n", mul(pow(2, N - 1), add(pow(2, N), 1)));
    return 0;
}