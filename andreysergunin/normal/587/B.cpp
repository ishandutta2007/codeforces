#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

const int P = 1e9 + 7;


long long power(long long x, long long d) {
    if (d == 0)
        return 1;
    long long u = power(x, d / 2);
    u = (u * u) % P;
    if (d % 2 == 1)
        u = (u * x) % P;
    return u;
}

int main() {
    long long l;
    long long n, k;
    scanf("%I64d %I64d %I64d", &n, &l, &k);
    long long a[n + 1], b[n + 1];
    for (long long i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);
    long long dp[n + 1][k + 1];
    for (long long i = 0; i <= n; i++)
        for (long long j = 0; j <= k; j++)
            dp[i][j] = 0;
    for (long long i = 0; i <= n; i++)
        dp[i][0] = 1;
    long long t = 0;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= k; j++)
            dp[i][j] = ((i - t) * dp[i][j - 1] % P + dp[t][j]) % P;
        if (a[i - 1] != a[i])
            t = i;
    }
    
    long long ans = 0;
    for (long long i = 1; i <= k && l / n >= i; i++)
        ans = (ans + dp[n][i] * ((l / n - i + 1) % P) % P) % P;
    
    sort(b, b + l % n);
    
    long long x = 0;
    for (long long j = 0; j < l % n; j++) {
        while (a[x] <= b[j] && x < n)
            x++;
        for (long long i = 1; i <= k - 1 && l / n >= i; i++)
            ans = (ans + dp[x][i]) % P;
    }
    cout << (ans + l % n) % P;
    return 0;
}