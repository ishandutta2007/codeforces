#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k, now, cap[N];
long long c[N], sum = 0, res = 0;

int mod (int x) {
    return ((x % n) + n) % n;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%I64d", c + i), sum += c[i];
    for (int i = 0; i < n; ++i) res += (c[i] * c[(i + 1) % n]);

    int prev = -10;
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &now);
        now--; cap[i] = now;
        if (now != prev + 1) res += c[now] * (sum - c[mod(now - 1)] - c[mod(now + 1)] - c[now]);
        else res += c[now] * (sum - c[mod(now + 1)] - c[now]);
        sum -= c[now]; prev = now;
    }

    if (k > 1 and cap[1] == 0 and cap[k] == n - 1) {
        res += c[0] * c[n - 1];
    }

    printf("%I64d\n", res);
    return 0;
}