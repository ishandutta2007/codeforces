#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;

int N;
int a[MAXN];
int dp[MAXN];

void load() {
    scanf("%d", &N);
    while (N--) {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
}

int solve() {
    int sol = 0;
    for (int i = 1; i < MAXN; i++) {
        if (!a[i]) continue;
        dp[i]++;
        for (int j = 2 * i; j < MAXN; j += i)
            dp[j] = max(dp[j], dp[i]);
        sol = max(sol, dp[i]);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}