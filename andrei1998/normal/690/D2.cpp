#include <iostream>

using namespace std;

const int NMAX = 500001;
const int MOD = 1000003;

int ridica(int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1LL * a * ridica(a, b - 1)) % MOD;
    else {
        int aux = ridica(a, b >> 1);
        return (1LL * aux * aux) % MOD;
    }
}

int facts[2 * NMAX + 5];
int inv_facts[2 * NMAX + 5];

void precompute() {
    facts[0] = 1;
    for (int i = 1; i < 2 * NMAX; ++ i)
        facts[i] = (1LL * i * facts[i - 1]) % MOD;

    inv_facts[2 * NMAX - 1] = ridica(facts[2 * NMAX - 1], MOD - 2);
    for (int i = 2 * NMAX - 2; i >= 0; -- i)
        inv_facts[i] = ((i + 1LL) * inv_facts[i + 1]) % MOD;
}

int comb(int n, int k) {
    if (n < k)
        return 0;
    return ((1LL * facts[n] * inv_facts[k]) % MOD * inv_facts[n - k]) % MOD;
}

int main()
{
    precompute();

    int n, c;
    cin >> n >> c;

    int ans = 0;
    for (int k = 1; k <= n; ++ k) {
        ans += comb(c + k - 1, k);
        if (ans >= MOD)
            ans -= MOD;
    }

    cout << ans << '\n';
    return 0;
}