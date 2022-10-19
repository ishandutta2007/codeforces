#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N;
pii p[MAXN];
int dp[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].first, &p[i].second);
}

int solve() {
    sort(p, p + N);
    int sol = N;
    for (int i = 0; i < N; i++) {
        int pos = lower_bound(p, p + N, pii(p[i].first - p[i].second, 0)) - p;
        dp[i] = i - pos;
        if (pos) dp[i] += dp[pos - 1];
        sol = min(sol, dp[i] + N - i - 1);
    }
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}