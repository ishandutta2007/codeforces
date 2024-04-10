#include <iostream>

using namespace std;

const int D = 5000 * 1000, MOD = 1000 * 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    int ans = 0;
    for(long long d = 0; d < D; d++) {
        long long l = n / (d + 1) + 1;
        if(l > m)
            continue;
        long long r = min(m + 1, (d? n / d + 1 : m + 1));
        ans = (ans + ((r - l) % MOD) * (n % MOD)) % MOD;
        ans = (ans - ((d * ((l + r - 1) % MOD)) % MOD *
                      ((r - l) % MOD)) % MOD * ((MOD + 1) / 2)) % MOD;
        if(ans < 0)
            ans += MOD;
    }
    for(long long k = 1; k < m && n / k >= D; k++)
        ans = (ans + n % k) % MOD;
    cout << ans << '\n';
    return 0;
}