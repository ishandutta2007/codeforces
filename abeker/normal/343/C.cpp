#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, M;
ll h[MAXN], p[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%I64d", h + i);
    for (int i = 0; i < M; i++)
        scanf("%I64d", p + i);
}

bool check(ll val) {
    int pos = 0;
    for (int i = 0; i < N; i++) {
        ll diff = max(h[i] - p[pos], 0ll);
        if (diff > val) return false;
        ll dist = max(max((val - diff) / 2, val - 2 * diff), 0ll);
        pos = upper_bound(p, p + M, h[i] + dist) - p;
        if (pos == M) return true;
    }
    return false;
}

ll solve() {
    ll lo = 0, hi = (ll)2e10;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}