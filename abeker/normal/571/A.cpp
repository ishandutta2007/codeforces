#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

int a, b, c, L;

void load() {
    scanf("%d%d%d%d", &a, &b, &c, &L);
}

ll gauss(int n) {
    return (ll)n * (n + 1) / 2;
}

ll f(int x, int y, int sum) {
    if (x > y) swap(x, y);
    if (sum <= x) return gauss(sum + 1);
    if (sum <= y) return gauss(x + 1) + (ll)(sum - x) * (x + 1);
    return 2 * gauss(x) + (ll)(y - x + 1) * (x + 1) - gauss(x + y - sum);
}

ll calc(int x, int y, int lo, int hi) {
    return f(x, y, hi) - f(x, y, lo - 1);
}

ll solve() {
    ll sol = (ll)max((a + b + c + L) / 3 - max(max(a, b), c) + 1, 0);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= L; j++) {
            int x = a + j - b;
            int y = a + j - c - 1;
            int lo = max(a + j - b - c + 1, 0);
            int hi = min(L - j, x + y);
            if (x >= 0 && y >= 0 && lo <= hi) 
                sol += calc(x, y, lo, hi);
        }
        swap(a, b);
        swap(b, c);
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}