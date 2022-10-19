#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    int N, W, V, U;
    scanf("%d%d%d%d", &N, &W, &V, &U);
    bool ok = true;
    ld ans = (ld)W / U;
    while (N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ok &= (ll)y * V <= (ll)x * U;
        ans = max(ans, (ld)x / V + (ld)(W - y) / U);
    }
    if (ok) ans = (ld)W / U;
    printf("%.10lf\n", (double)ans);
    return 0;
}