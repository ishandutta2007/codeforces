#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define P 1000000007
#define int long long
using namespace std;

typedef long long ll;

ll n, S[1000010][7], K[1000010][7], Rev[33];

ll powmod(ll x, ll y = P - 2, ll p = P) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

ll mul(ll x, ll y, ll p = P) {
    return x % p * (y % p) % p;
}

ll solve1(ll i, ll j) {
    ll r2 = Rev[2];
    if(i < 0) i = -i;
    return r2 * ((K[i][4] * S[j][0] % P + 2 * K[i][2] * S[j][2] % P + K[i][0] * S[j][4] % P - K[i][2] * S[j][0] % P - K[i][0] * S[j][2] % P) % P) % P;
}

ll solve2(ll i, ll j) {
    ll r6 = Rev[6];
    if(i < 0) i = -i;
    return r6 * ((2 * K[i][6] * S[j][0] % P + 6 * K[i][4] * S[j][2] % P + 6 * K[i][2] * S[j][4] % P + 2 * K[i][0] * S[j][6] % P - 3 * K[i][4] * S[j][0] % P - 3 * K[i][0] * S[j][4] % P - 6 * K[i][2] * S[j][2] % P + K[i][2] * S[j][0] % P + K[i][0] * S[j][2] % P)) % P;
}

#undef int
int main() {
#define int long long
    scanf("%lld", &n);
    for(int i = 1; i <= 32; i++) Rev[i] = powmod(i);
    for(int i = 0; i <= 1000000; i++) {
        ll tmp = 1;
        for(int j = 0; j <= 6; j++) {
            S[i][j] = ((!i ? 0 : S[i - 1][j]) + tmp) % P;
            K[i][j] = tmp;
            tmp = tmp * i % P;
        }
    }
    for(int i = 1; i <= 1000000; i++)
        for(int j = 0; j <= 6; j++)
            S[i][j] = (S[i][j] * 2 - !j) % P;
    ll j = 0, s = sqrt(n), tot = 0;
    tot = n % P;
    tot = Rev[6] * tot % P * (tot + 1) % P * (tot + 2) % P;
    ll ans = 0;
    for(int i = -s; i <= s; i++) {
        if(i <= 0) {
            while(i * i + (j + 1) * (j + 1) <= n) j++;
        } else {
            while(i * i + j * j > n) j--;
        }
        ans = (ans + (j * 2 + 1) * tot) % P;
        ans = (ans - mul(n + 1, solve1(i, j))) % P;
        ans = (ans + solve2(i, j)) % P;
    }
    printf("%lld\n", (ans % P + P) % P);
    return 0;
}