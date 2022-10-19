#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 505;
const int MOD = 1000000007;

inline void add(int &x, int y) {
    x += y; 
    if (x >= MOD) x -= MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int N;
int b[MAXN];
int dp[MAXN][MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", b + i);
}

int rec(int lo, int hi) {
    int &ref = dp[lo][hi];
    if (ref != -1) return ref;
    if (hi - lo <= 1) return ref = 1;
    ref = 0;
    for (int i = lo + 1; i < hi; i++) 
        if (i == hi - 1 || b[i + 1] > b[lo + 1]) 
            add(ref, mul(rec(lo + 1, i + 1), rec(i, hi)));
    return ref;
}

int solve() {
    memset(dp, -1, sizeof dp);
    return rec(0, N);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}