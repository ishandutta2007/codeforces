#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

int n;
int len[N];
long long dp[N][3];

int main()
{
    scanf("%d", &n);
    long long va = 0, vb = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &len[i]);

        if (i & 1) {
            va += len[i] / 2;
            vb += (len[i] + 1) / 2;
        } else {
            vb += len[i] / 2;
            va += (len[i] + 1) / 2;
        }
    }

    printf("%lld\n", min(va, vb));
    return 0;
}