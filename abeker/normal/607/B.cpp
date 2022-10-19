#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 505;
const int INF = 0x3f3f3f3f;

int N;
int a[MAXN];
int dp[MAXN][MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int rec(int lo, int hi) {
    int &ref = dp[lo][hi];
    if (ref != INF) return ref;
    if (lo + 1 >= hi) return ref = 1;
    if (a[lo] == a[hi - 1]) ref = rec(lo + 1, hi - 1);
    for (int i = lo + 1; i < hi; i++)
        ref = min(ref, rec(lo, i) + rec(i, hi));
    return ref;
}

int solve() {
    memset(dp, INF, sizeof dp);
    return rec(0, N);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}