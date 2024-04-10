#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    return !y ? x : gcd(y, x % y);
}

signed main() {
    int n, m, k, N, M;
    scanf("%lld%lld%lld", &n, &m, &k), N = n, M = m;
    int g = gcd(n, k);
    n /= g, k /= g;
    g = gcd(m, k);
    m /= g, k /= g;
    if(k == 1) {
        if(n * 2 <= N) n *= 2; else m = m * 2;
        k *= 2;
    }
    if(k != 2) {
        puts("NO");
        return 0;
    }
    printf("YES\n0 0\n0 %lld\n%lld 0\n", m, n);
    return 0;
}