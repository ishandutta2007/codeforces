#include <iostream>

using namespace std;

const int MAXN = 1000 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int f[MAXN];

int powMod(int x, int p) {
    int res = 1;
    while(p) {
        if(p & 1)
            res = (long long)res * x % MOD;
        x = (long long)x * x % MOD;
        p >>= 1;
    }
    return res;
}

pair<int, int> gcd(int a, int b) {
    if(!b)
        return make_pair(1, 0);
    pair<int, int> p = gcd(b, a % b);
    return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
    int res = gcd(x, MOD).first;
    if(res < 0)
        res += MOD;
    return res;
}

int a(int n, int k) {
    return (long long)f[n] * inv(f[n - k]) % MOD;
}

int solve(int w, int k) {
    int res = 0;
    for(int i = 0; i < k; i++)
        if(2 * (i + 1) > w + i)
            res = (res + (long long)a(k, 2 * (i + 1) - w - i) *
                          a(k - (2 * (i + 1) - w - i), w - 1) % MOD *
                   a(k - (2 * (i + 1) - w - i), w - 1) % MOD) % MOD;
        else
            res = (res + (long long)a(k, i + 1) * a(k, i + 1) % MOD *
                   powMod(k, w + i - 2 * (i + 1)) % MOD) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int k, w;
    cin >> k >> w;
    f[0] = 1;
    for(int i = 1; i <= k; i++)
        f[i] = (long long)f[i - 1] * i % MOD;
    int ans = solve(w + 1, k) - solve(w, k);
    if(ans < 0)
        ans += MOD;
    ans += powMod(k, w);
    if(ans >= MOD)
        ans -= MOD;
    cout << ans << '\n';
    return 0;
}