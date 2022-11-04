#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, m;

int main() {
    scanf("%lld%lld", &n, &m);
    ll ans = 0;
    for(ll i = 0; i < m; i++)
        for(ll j = 0; j < m; j++)
            if((i * i + j * j) % m == 0) {
                ll tmp1 = n / m + (n % m >= i) - (i == 0);
                ll tmp2 = n / m + (n % m >= j) - (j == 0);
                ans += tmp1 * tmp2;
            }
    printf("%lld\n", ans);
    return 0;
}