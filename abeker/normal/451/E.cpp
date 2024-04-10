#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 21;
const int MOD = 1000000007;

int N, inv;
ll S, a[MAXN];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    if (!y) return 1;
    if (y & 1) return mul(x, pow(x, y - 1));
    int res = pow(x, y >> 1);
    return mul(res, res);
}

void load() {
    scanf("%d%I64d", &N, &S);
    for (int i = 0; i < N; i++)
        scanf("%I64d", a + i);
}

int choose(ll num) {
    if (num < 0) return 0;
    int res = inv, rem = (int)(num % MOD);
    for (int i = 1; i < N; i++) {
        add(rem, 1);
        res = mul(res, rem);
    }
    return res;
}

int solve() {
    inv = 1;
    for (int i = 1; i < N; i++)
        inv = mul(inv, i);
    inv = pow(inv, MOD - 2);
    int sol = 0;
    for (int i = 0; i < 1 << N; i++) {
        ll sum = 0;
        for (int j = 0; j < N; j++)
            if (i >> j & 1) sum += a[j] + 1;
        int tmp = choose(S - sum);
        add(sol, __builtin_popcount(i) & 1 ? -tmp : tmp);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}