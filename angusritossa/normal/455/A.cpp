/*
dp[i] = maximum answer if we take value i (and nothing smaller)
then dp[i] = sum[i] + max(dp[i+2], dp[i+3]), where sum[i] is sum of all values equal to i 
answer = max(dp[1], dp[2])
*/
#include <cstdio> // scanf/printf
#include <algorithm> // max
using namespace std;
#define MAXN 100010
typedef long long ll;
ll sum[MAXN], dp[MAXN], n;
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sum[a] += a;
    }
    for (int i = MAXN-4; i >= 0; i--) {
        dp[i] = sum[i] + max(dp[i+2], dp[i+3]);
    }
    ll ans = max(dp[1], dp[2]);
    printf("%lld\n", ans);
}