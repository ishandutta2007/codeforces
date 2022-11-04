#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#define P 1000000007
#define int long long

using namespace std;

typedef long long ll;

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

ll n, K;

ll F[10111][77], Rev[111];

ll Do(ll a, ll b) {
    memset(F, 0, sizeof F);
    F[0][a] = 1;
    for(int i = 0; i < K; i++)
        for(int j = 0; j <= a; j++) {
            ll tmp = F[i][j] * Rev[j + 1] % P;
            for(int k = 0; k <= j; k++)
                F[i + 1][k] = (F[i + 1][k] + tmp) % P;
        }
    ll ans = 0;
    for(int i = 0; i <= a; i++) ans = (ans + powmod(b, i) * F[K][i]) % P;
    return ans;
}

signed main() {
    for(int i = 1; i <= 110; i++) Rev[i] = powmod(i);
    scanf("%lld%lld", &n, &K);
    ll ans = 1;
    for(ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
        if(cnt) ans = (ans * Do(cnt, i)) % P;
    }
    if(n != 1) ans = (ans * Do(1, n)) % P;
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}