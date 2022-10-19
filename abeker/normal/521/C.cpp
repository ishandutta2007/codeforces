#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

inline int add(int x, int y) {
    return (x + y) % MOD;
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

inline int inv(int x) {
    return pow(x, MOD - 2);
}

int N, K;
char s[MAXN];
int pref[MAXN];
int fact[MAXN];

void load() {
    scanf("%d%d%s", &N, &K, s);
}

inline int choose(int n, int k) {
    if (n < k) return 0;
    return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}

void init() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) 
        fact[i] = mul(fact[i - 1], i);
    if (!K) return;
    for (int i = 0; i < N; i++) {
        pref[i] = mul(pow(10, i), choose(N - i - 2, K - 1));
        if (i) pref[i] = add(pref[i], pref[i - 1]);
    }
}

int solve() {
    int sol = 0;
    for (int i = 0; i < N; i++) {
        if (i < N - 1) sol = add(sol, mul(s[i] - '0', pref[N - i - 2]));
        sol = add(sol, mul(s[i] - '0', mul(pow(10, N - i - 1), choose(i, K))));
    }
    return sol;
}

int main() {
    load();
    init();
    printf("%d\n", solve());
    return 0;
}