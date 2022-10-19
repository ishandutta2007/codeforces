#include <cstdio>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int SQRT = 4000000;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    ll N, M;
    scanf("%I64d%I64d", &N, &M);
    
    int sol = 0;
    ll bound = (N + (ll)SQRT) / (ll)(SQRT + 1);
    for (int i = 1; i < (int)bound && i <= M; i++)
        sol = add(sol, (int)(N % (ll)i));
    
    if (M > N) sol = add(sol, mul((int)(N % MOD), (int)((M - N) % MOD)));
    
    for (int i = 1; i <= SQRT; i++) {
        ll lo = N / (ll)(i + 1) + 1;
        ll hi = N / (ll)i;
        if (hi > M) hi = M;
        if (lo > hi) continue;
        int cnt = (int)((hi - lo + 1) % MOD);
        int sum = mul(mul((int)((lo + hi) % MOD), cnt), (MOD + 1) / 2); 
        sol = add(sol, add(mul((int)(N % MOD), cnt), -mul(i, sum)));
    }
    
    printf("%d\n", sol);
    
    return 0;
}