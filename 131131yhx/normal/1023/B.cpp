#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <string>

using namespace std;

typedef long long ll;

ll n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    ll l = k - n, r = k - 1;
    l = max(l, 1ll);
    r = min(r, n);
    ll ans = max(r - l + 1, 0ll);
    printf("%lld\n", ans / 2);
    return 0;
}