#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int N;
int a[5][MAXN];
int dp[MAXN][5][5];
 
void load() {
    scanf("%d", &N);
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", a[i] + j);
}

int rec(int pos, int curr, int prev) {
    int &ref = dp[pos][curr][prev];
    if (ref != -1) return ref;
    if (pos == 1 && curr == 2) return ref = -INF;
    if (pos == 1 && curr == 1 && prev == 0) return ref = -INF;
    if (curr == 1) return ref = max(rec(pos - 1, 1, prev), rec(pos - 1, prev, 2 - prev)) + a[curr][pos];
    if (curr == 0) return ref = max(rec(pos - 1, 1, 2), rec(pos - 1, 2, 0)) + a[curr][pos];
    if (curr == 2) return ref = max(rec(pos - 1, 1, 0), rec(pos - 1, 0, 2)) + a[curr][pos];
    assert(0);
}

int solve() {
    if (N == 1) return a[0][1];
    if (N == 2) return max(a[0][1] + a[1][2], a[1][1] + a[0][2]);
    memset(dp, -1, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    return max(rec(N, 0, 2), rec(N, 1, 0)); 
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;    
}