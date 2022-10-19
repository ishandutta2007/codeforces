#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define long long long
#define mod 1000000007ll
#define M 23

long r[M];

long bin(long x, long a) {
    long y = 1;
    while (a) {
        if (a & 1) {
            y *= x, y %= mod;
        }
        x *= x, x %= mod;
        a >>= 1;
    }
    return y;
}

void pre() {
    for (int i = 1; i < M; ++i)
        r[i] = bin(i, mod - 2);
}


long cnk(long n, long k) {
    if (n < k)
        return 0;
    n %= mod;
    long ans = 1;
    for (int i = 0; i < k; ++i)
        ans = (ans * (n - i)) % mod;
    for (int i = 1; i <= k; ++i)
        ans = (ans * r[i]) % mod;
    return ans;
}

long n, f[M], s;

void read() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        ++f[i];
    }
}

void kill() {
    long ans = 0;
    for (int m = 0; m < (1 << n); ++m) {
        long sign = 1, pw = 0;
        for (int i = 0; i < n; ++i)
            if (m & (1 << i)) {
                pw += f[i];
                sign *= -1;
            }
        if (pw <= s)
            ans = (ans + sign * cnk(s - pw + n - 1, n - 1)) % mod;
    }
    if (ans < 0)
        ans += mod;
    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    pre();
    read();
    kill();

    return 0;
}