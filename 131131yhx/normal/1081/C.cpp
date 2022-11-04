#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#define M 200010
#define int long long
#define P 998244353

using namespace std;

typedef long long ll;

ll Fac[2222];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

signed main() {
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k >= n) {
        puts("0");
        return 0;
    }
    for(int i = 0; i <= 2000; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P;
    ll ans = m * powmod(m - 1, k) % P;
    ans = ans * Fac[n - 1] % P * powmod(Fac[k]) % P * powmod(Fac[n - 1 - k]) % P;
    printf("%lld\n", ans);
    return 0;
}