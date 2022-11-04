#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll t, n, a, b, k;

int main() {
    scanf("%lld%lld%lld%lld%lld", &t, &n, &a, &b, &k);
    ll X = n / 2 + n % 2, Y = n / 2;
    if(k == 1) return printf("%lld\n", min(t, X * a + Y * b)), 0;
    if(k > n) return puts("0"), 0;
    if(a < b) swap(X, Y), swap(a, b);
    ll S1 = min(k - 1, X), S2 = k - S1;
    if(a * X / S1 >= b * Y / S2) {
        printf("%lld\n", min(t, b * Y / S2));
    } else printf("%lld\n", min(t, (a * X + b * Y) / k));
    return 0;
}