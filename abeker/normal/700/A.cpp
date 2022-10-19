#include <cstdio>
#include <algorithm>
using namespace std;

typedef long double ld;

const ld eps = 1e-8;

int N, L, v1, v2, K;

void load() {
    scanf("%d%d%d%d%d", &N, &L, &v1, &v2, &K);
}

bool check(ld t) {
    ld curr = 0, pos = 0;
    for (int i = 0; i < N; i++) {
        ld tmp = max((L - pos - v1 * (t - curr)) / (v2 - v1), (ld)0);
        curr += tmp;
        pos += tmp * v2;
        if (i == N - 1) break;
        tmp = max(2 * (pos - curr * v1) / (v1 + v2), (ld)0);
        curr += tmp;
    }
    return curr < t + eps;
}

ld solve() {
    N = (N - 1) / K + 1;
    ld lo = 0, hi = L;
    for (int i = 0; i < 1000; i++) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }
    return lo;
}

int main() {
    load();
    printf("%.15lf\n", (double)solve());
    return 0;
}