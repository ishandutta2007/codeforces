#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll dx[] = {-1, -2, -1, 1, 2, 1};
const ll dy[] = {2, 0, -2, -2, 0, 2};

ll f(ll x) {
    return 3 * x * x - 3 * x + 1;
}

int main() {
    ll N;
    scanf("%I64d", &N);
    N++;
    
    ll lo = 1, hi = (ll)1e9;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid) >= N) hi = mid;
        else lo = mid + 1;
    }
    
    N -= f(--lo);
    
    ll x = 2 * lo, y = 0;
    for (int i = 0; i < 6; i++) {
        ll cnt = min(lo, max(N, 0ll));
        x += cnt * dx[i];
        y += cnt * dy[i];
        N -= lo;
    }
    
    printf("%I64d %I64d\n", x, y);
    
    return 0;
}