#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

const int MAXN = 1e6;

int fact[MAXN];
int invFact[MAXN];

int powmod(int a, int b) {
    int ret = 1;
    for (; b; b /= 2, a = a * a % MOD)
        if (b % 2)
            ret = ret * a % MOD;
    return ret;
}

int inv(int x) {
    return powmod(x, MOD-2);
}

void initFact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = i * fact[i-1] % MOD;
    invFact[MAXN-1] = inv(fact[MAXN-1]);
    for (int i = MAXN-1; i; --i)
        invFact[i-1] = i * invFact[i] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int &x : vec)
        cin >> x;

    int nb0 = 0;
    for (int x : vec)
        nb0 += x == 0;
    int bad = 0;
    for (int i = 0; i < nb0; ++i)
        bad += vec[i];
    int sol = 0;
    int inv2 = inv(2);
    for (int i = 1; i <= bad; ++i) {
        sol += n *(n-1) % MOD * inv2 % MOD * inv(i * i % MOD) % MOD;
        if (sol >= MOD)
            sol -= MOD;
    }
    cout << sol << '\n';
    }
}