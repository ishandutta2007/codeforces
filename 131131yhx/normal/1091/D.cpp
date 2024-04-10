#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <bitset>
#define P 998244353
#define PI pair <int, int>
#define f first
#define s second
#define int long long
#define M 2000010

using namespace std;

typedef long long ll;

int n;

vector <ll> V(0);

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

ll Fac[M], Rev[M];

ll C(ll x, ll y) {
    if(x < y || x < 0 || y < 0) return 0;
    return Fac[x] * Rev[y] % P * Rev[x - y] % P;
}

signed main() {
    scanf("%lld", &n);
    if(n <= 3) {
        if(n == 1) puts("1");
        else if(n == 2) puts("2");
        else if(n == 3) puts("9");
        return 0;
    }
    for(int i = 0; i <= n; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P, Rev[i] = powmod(Fac[i]);
    ll ans = Fac[n];
    for(int x = 2; x <= n - 1; x++)
        ans = (ans + (Fac[x] - 1) * Fac[n - x] % P * C(n, x)) % P;
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}