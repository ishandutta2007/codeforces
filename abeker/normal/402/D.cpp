#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define add(z) bad[z] ? -1 : 1

const int MAXN = 5005;
const int INF = 0x3f3f3f3f;

int N, M;
int a[MAXN];
map <int, bool> bad;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
    for (int i = 0; i < M; i++) {
        int b; scanf("%d", &b);
        bad[b] = true;
    }
}

int dp[MAXN];

int f(int x) {
    if (x == 1) return 0;
    int res = 0;
    for (int i = 2; i * i <= x; i++) 
        for (; !(x % i); x /= i) 
            res += add(i);
    if (x > 1) res += add(x);
    return res;
}

int solve() {
    int sum = 0;
    for (int i = 0; i < N; i++) 
        sum += f(a[i]);
    for (int i = 1; i < N; i++) 
        a[i] = __gcd(a[i], a[i - 1]);
    for (int i = 0; i < N; i++)
        a[i] = f(a[i]);
    memset(dp, INF, sizeof dp);
    dp[N] = 0;
    for (int i = N - 1; i >= 0; i--) 
        for (int j = N; j > i; j--) 
            dp[i] = min(dp[i], dp[j] + (i + 1) * (a[i] - a[j]));
    return sum - *min_element(dp, dp + N + 1);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}