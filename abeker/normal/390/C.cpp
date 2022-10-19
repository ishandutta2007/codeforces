#include <cstdio>
using namespace std;

const int MAXN = 100005;
const int MAXK = 15;

int N, K, W;
char s[MAXN];
int a[MAXN];
int cnt[MAXK][MAXN];

void load() {
    scanf("%d%d%d%s", &N, &K, &W, s);    
}

int sum(int lo, int hi) {
    return a[hi] - (lo ? a[lo - 1] : 0);
}

int get(int mod, int lo, int hi) {
    return cnt[mod][hi] - (lo ? cnt[mod][lo - 1] : 0);
}

void solve() {
    for (int i = 0; i < N; i++) {
        a[i] = cnt[i % K][i / K] = s[i] - '0';
        if (i) a[i] += a[i - 1];
        if (i / K) cnt[i % K][i / K] += cnt[i % K][i / K - 1];
    }
    while (W--) {
        int l, r;
        scanf("%d%d", &l, &r); l--; r--;
        printf("%d\n", (r - l + 1) / K + sum(l, r) - 2 * get(r % K, (l + K - 1) / K, r / K));
    }
    
}

int main() {
    load();
    solve();
    return 0;
}