#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

map <ll, int> hsh;

int tim;

const int P[3] = {998244353, 1000000007, 1000000009};

int m, d, k;

ll X[7][7], Y[7][7];

ll powmod(ll x, ll y, ll p) {
    ll ans = 1;
    while(y) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d%d", &m, &d);
    for(int i = 1; i <= m; i++) {
        int k;
        scanf("%d", &k);
        memset(X, 0, sizeof X), memset(Y, 0, sizeof Y);
        for(int i = 1; i <= k; i++)
            for(int j = 1; j <= d; j++) scanf("%lld", &X[i][j]), Y[i][j] = X[i][j];
        ll f = 0;
        k = d;
        for(int T = 0; T < 3; T++) {
            int t = 1;
            memcpy(X, Y, sizeof X);
        for(int i = 1; i <= d; i++) {
            for(int s = t; s <= k; s++)
                if(X[s][i]) {
                    swap(X[s], X[t]);
                    break;
                }
            if(!X[t][i]) continue;
            ll tmp = powmod(X[t][i], P[T] - 2, P[T]);
            for(int j = d; j >= i; j--)
                X[t][j] = X[t][j] * tmp % P[T];
            for(int j = t + 1; j <= k; j++) {
                for(int s = k; s >= i; s--)
                    X[j][s] = ((X[j][s] - X[j][i] * X[t][s]) % P[T] + P[T]) % P[T];
            }
            t++;
        }
            t--;
            for(int i = t; i >= 1; i--) {
                int o;
                for(int j = 1; j <= d; j++) if(X[i][j]) {
                    o = j;
                    break;
                }
                for(int j = i - 1; j >= 1; j--) {
                    for(int s = d; s >= o; s--)
                        X[j][s] = ((X[j][s] - X[j][o] * X[i][s]) % P[T] + P[T]) % P[T];
                }
            }
            for(int i = 1; i <= t; i++)
                for(int j = 1; j <= d; j++)
                    f = f * 0x23333333 + X[i][j];
        }
        if(!hsh.count(f)) hsh[f] = ++tim;
        printf("%d ", hsh[f]);
    }
    return 0;
}