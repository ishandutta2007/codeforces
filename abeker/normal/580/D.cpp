#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 20;

int N, M, K;
int a[MAXN];
int mat[MAXN][MAXN];
ll dp[1 << MAXN][MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    while (K--) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        mat[--x][--y] = c;
    }
}

ll rec(int mask, int idx) {
    ll &ref = dp[mask][idx];
    if (ref != -1) return ref;
    ref = 0;
    for (int i = 0; i < N; i++)
        if (i != idx && mask >> i & 1) 
            ref = max(ref, rec(mask ^ 1 << idx, i) + (ll)mat[i][idx]);
    ref += (ll)a[idx];
    return ref;
}

ll solve() {
    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;
    
    ll sol = 0;
    for (int i = 0; i < 1 << N; i++) {
        if (__builtin_popcount(i) != M) continue;
        for (int j = 0; j < N; j++)
            if (i >> j & 1) sol = max(sol, rec(i, j));
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}