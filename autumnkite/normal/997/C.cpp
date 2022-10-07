#include <cstdio>
#define N 1000005
#define P 998244353
int n, fac[N], inv[N], ans;
int qpow(int a, long long b){
    int s = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
    return s;
}
int C(int n, int m){
    return 1ll * fac[n] * inv[n - m] % P * inv[m] % P;
}
int add(int x, int y){
    return (x += y) >= P ? x -= P : x;
}
int sub(int x, int y){
    return (x -= y) < 0 ? x += P : x;
}
int main(){
    scanf("%d", &n), fac[0] = 1;
    for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
    inv[n] = qpow(fac[n], P - 2);
    for (register int i = n; i; --i) inv[i - 1] = 1ll * inv[i] * i % P;
    ans = sub(qpow(3, 1ll * n * n), qpow(sub(qpow(3, n), 3), n));
    for (register int i = 1; i <= n; ++i){
        int s = 1ll * C(n, i) * add(3ll * qpow(qpow(3, n - i) - 1, n) % P, 1ll * sub(qpow(3, i), 3) * qpow(3, 1ll * n * (n - i)) % P) % P;
        if (i & 1) ans = add(ans, s); else ans = sub(ans, s);
    }
    printf("%d\n", ans);
}