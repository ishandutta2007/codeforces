#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <deque>

using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<long long> v(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &v[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        --c[i];
    }
    for (int i = 0; i < q; i++) {
        long long a, b;
        cin >> a >> b;
        vector<long long> dp(n);
        for (int i = 0; i < n; i++)
            dp[i] = -1e17;
        int maxn1 = -1, maxn2 = -1;
        long long ans = 0;
        for (int i = 0 ; i < n; i++) {
            long long k = b * v[i];
            if (dp[c[i]] != -1e17)
                k = max(k, dp[c[i]] + a * v[i]);
            if (maxn1 != -1 && maxn1 != c[i])
                k = max(k, dp[maxn1] + b * v[i]);
            else {
                if (maxn2 != -1)
                    k = max(k, dp[maxn2] + b * v[i]);
            }
            dp[c[i]] = max(dp[c[i]], k);
            if (maxn1 == -1 || dp[c[i]] > dp[maxn1]) {
                maxn2 = maxn1;
                maxn1 = c[i];
            }
            else {
                if ((maxn2 == -1 || dp[c[i]] > dp[maxn2]) && maxn1 != c[i])
                    maxn2 = c[i];
            }
            ans = max(ans, k);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}