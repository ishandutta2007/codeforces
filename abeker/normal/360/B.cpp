#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 2005;

int N, K;
int a[MAXN];
int dp[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

bool check(int val) {
    int sol = 0;
    for (int i = N - 1; i >= 0; i--) {
        dp[i] = 0;
        for (int j = i + 1; j < N; j++)
            if ((ll)abs(a[j] - a[i]) <= (ll)(j - i) * val)
                dp[i] = max(dp[i], dp[j]);
        sol = max(sol, ++dp[i]);
    }    
    return sol >= N - K;
}

int solve() {
    int lo = 0, hi = (int)2e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}