#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
const int MOD = 1000003;

int fact[MOD];
int invfact[MOD];

inline int invmod(int a) {
    int n = MOD - 2;
    int r;
    for (r = 1; n; n >>= 1) {
        if (n & 1) {
            r = 1LL * r * a % MOD;
        }
        a = 1LL * a * a % MOD;
    }
    return r;
}

inline int C(int n, int k) {
    int r = fact[n];
    r = 1LL * r * invfact[k] % MOD;
    r = 1LL * r * invfact[n - k] % MOD;
    return r;
}

int main() {
    int n, m;
    cin >> n >> m;
    fact[0] = 1; invfact[0] = 1;
    for (int i = 1; i <= n + m; i += 1) {
        fact[i] = 1LL * fact[i - 1] * i % MOD;
        invfact[i] = invmod(fact[i]);
    }
    int answer = 0;
    for (int i = 1; i <= n; ++ i) {
        answer = answer + C(i + m - 1, i);
        if (answer >= MOD) {
            answer -= MOD;
        }
    }
    cout << answer << "\n";
    return 0;
}