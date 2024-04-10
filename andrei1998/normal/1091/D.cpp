#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int MOD = 998244353;
const int NMAX = 1000000 + 5;

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
    return ((1LL * facts[n] * inv_facts[k]) % MOD * inv_facts[n - k]) % MOD;
}

int main() {
    precompute();
    int N = 10;
    cin >> N;
    int ans = facts[N];
    for (int k = 1; k < N; ++k) {
        const int val = ((1LL * comb(N, k) * facts[k]) % MOD * (facts[N - k] - 1)) % MOD;
        ans += val;
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}