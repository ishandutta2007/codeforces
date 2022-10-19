#include <cstdio>
using namespace std;

typedef long long ll;

inline int bc(ll x) {
    int res = 0;
    for (; x; x /= 2) 
        res += x % 2;
    return res;
}

ll solve(ll lo, ll hi) {
    if (lo == hi) return lo;
    ll curr = solve(lo / 2, (hi - 1) / 2);
    if (bc(hi) > bc(curr) + 1) return hi;
    return 2 * curr + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        ll l, r;
        scanf("%I64d%I64d", &l, &r);
        printf("%I64d\n", solve(l, r));
    }
    return 0;
}