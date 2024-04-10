#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXM = 200005;
const int MAXN = 2005;
const int MOD = 1000000007;

int H, W, N;
int r[MAXN], c[MAXN];
int fact[MAXM];
int inv[MAXM];
int dp[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x < 0) x += MOD;
    else if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    if (!y) return 1;
    if (y & 1) return mul(pow(x, y - 1), x);
    int res = pow(x, y >> 1);
    return mul(res, res);
}

int ways(int x, int y) {
    return mul(fact[x + y], mul(inv[x], inv[y]));
}

void load() {
    scanf("%d%d%d", &W, &H, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", r + i, c + i);
        r[i]--; 
        c[i]--;
    }   
}

int rec(int x) {
    int &ref = dp[x];
    if (ref != -1) return ref;
    ref = 0;
    for (int i = 0; i < N; i++) 
        if (r[i] <= r[x] && c[i] <= c[x] && i != x) 
            ref = add(ref, mul(rec(i), ways(r[x] - r[i], c[x] - c[i])));
    ref = add(ways(r[x], c[x]), -ref);
    return ref;
}

int solve() {
    fact[0] = 1;
    inv[0] = 1;
    int maks = 2 * max(W, H);
    for (int i = 1; i <= maks; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pow(fact[i], MOD - 2);
    }  
    r[N] = --W;
    c[N++] = --H;
    memset(dp, -1, sizeof dp);
    return rec(N - 1); 
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}