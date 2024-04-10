#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int fen[MAXN], p[MAXN], q[MAXN], inv[MAXN], dp[MAXN], fact[MAXN], num[MAXN];

void add(int x, int k) {
    for(; x < MAXN; x |= x + 1)
        fen[x] += k;
}

int get(int x) {
    int res = 0;
    for(; x >= 0; x = (x & (x + 1)) - 1)
        res += fen[x];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = n - 1; i >= 0; i--) {
        q[i] = get(p[i]);
        add(p[i], 1);
    }
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = ((long long)i * fact[i - 1]) % MOD;
    for(int i = 1; i <= n; i++)
        inv[i] = ((((long long)(i - 1) * i / 2) % MOD) * fact[i - 1] +
                  (long long)i * inv[i - 1]) % MOD;
    num[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--) {
        dp[i] = ((((long long)(q[i] - 1) * q[i] / 2) % MOD) * fact[n - i - 1] +
                 (long long)q[i] * (num[i + 1] + inv[n - i - 1]) +
                 dp[i + 1]) % MOD;
        num[i] = ((long long)q[i] * fact[n - i - 1] + num[i + 1]) % MOD;
    }
    cout << dp[0] << '\n';
    return 0;
}