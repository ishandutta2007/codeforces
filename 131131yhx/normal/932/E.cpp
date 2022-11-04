#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>
#define P 1000000007

using namespace std;

typedef long long ll;

ll N, k;

ll S[5010][5010];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int main() {
    scanf("%lld%lld", &N, &k);
    S[0][0] = 1;
    for(int i = 1; i <= 5000; i++)
        for(int j = 0; j <= i; j++)
            S[i][j] = !j ? 0 : (S[i - 1][j - 1] + S[i - 1][j] * j) % P;
    ll ans = 0, s = 1, tmp = powmod(2, N), r2 = powmod(2);
    for(int i = 0; i <= k && i <= N; s = (s * (N - i)) % P, i++, tmp = (tmp * r2) % P)
        ans = (ans + s * tmp % P * S[k][i]) % P;
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}