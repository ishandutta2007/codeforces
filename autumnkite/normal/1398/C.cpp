#include <bits/stdc++.h>

int n;
char a[100005];
int sum[100005];

void solve() {
    scanf("%d%s", &n, a + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + (a[i] - '0') - 1;
    }
    std::map<int, int> M;
    M[sum[0]] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += M[sum[i]];
        ++M[sum[i]];
    }
    printf("%lld\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}