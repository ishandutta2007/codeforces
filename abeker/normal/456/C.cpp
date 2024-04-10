#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N;
int a[MAXN];
ll dp[MAXN][2];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x; scanf("%d", &x);
        a[x]++;
    }
}

ll solve() {
    for (int i = 1; i < MAXN; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + (ll)i * (ll)a[i];
    }
    return max(dp[MAXN - 1][0], dp[MAXN - 1][1]);
}

int main() {
    load();
    cout << solve() << endl;
    return 0;
}