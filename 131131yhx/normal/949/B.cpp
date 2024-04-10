#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#define int long long

using namespace std;

typedef long long ll;

ll n, q, L[200010];

ll Solve(ll n, ll x) {
    if(x % 2 == 1) {
        return x / 2 + 1;
    }
    return Solve(n - x / 2, n - x / 2) + x / 2;
}

#undef int
int main() {
#define int long long
    scanf("%lld%lld", &n, &q);
    for(int i = 1; i <= q; i++) {
        scanf("%lld", &L[i]);
        printf("%lld\n", Solve(n, L[i]));
    }
    return 0;
}