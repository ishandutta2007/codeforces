#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 998244353;
template <typename Int, Int MOD, int N> struct comb_util {
    std::array<Int, N + 1> fc, ifc;

    comb_util() {
        fc[0] = 1;
        for (int i = 1; i <= N; i++)
            fc[i] = fc[i - 1] * i % MOD;
        ifc[N] = inv(fc[N]);
        for (int i = N - 1; i >= 0; i--)
            ifc[i] = ifc[i + 1] * (i + 1) % MOD;
    }

    Int fact(Int n) { return fc[n]; }

    Int inv_fact(Int n) { return ifc[n]; }

    Int inv(Int n) { return pow(n, MOD - 2); }

    Int pow(Int n, Int a) {
        Int res = 1, exp = n;
        for (; a; a /= 2) {
            if (a & 1)
                res = res * exp % MOD;
            exp = exp * exp % MOD;
        }
        return res;
    }

    Int perm(Int n, Int r) {
        if (r < 0 || n < r)
            return 0;
        else
            return fc[n] * ifc[n - r] % MOD;
    }

    Int binom(Int n, Int r) {
        if (n < 0 || r < 0 || n < r)
            return 0;
        return fc[n] * ifc[r] % MOD * ifc[n - r] % MOD;
    }

    Int homo(Int n, Int r) {
        if (n < 0 || r < 0)
            return 0;
        return r == 0 ? 1 : binom(n + r - 1, r);
    }
};

using comb = comb_util<long long, 998244353, 500000>;
comb cb;
void add(int &a, const int &b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
void sub(int &a, const int &b) {
    a -= b;
    if (a < 0)
        a += MOD;
}
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    int all = 1;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        all = (all * K) % MOD;
    }
    if(K == 1){
        cout << 0 <<endl;
        return 0;
    }
    int same = 0;
    int diff = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == A[(i + 1) % N]) {
            same++;
        } else {
            diff++;
        }
    }
    int S = 0;
    for (int i = 0; i <= diff; i += 2) {
        int tmp = cb.binom(diff, i) * cb.binom(i, i / 2) % MOD;
        tmp = (tmp * cb.pow(K - 2, diff - i)) % MOD;
        add(S, tmp);
    }
    S = (S * cb.pow(K, same)) % MOD;
    //cerr << all << " " << S << endl;
    int res = all;
    sub(res, S);
    res = (res * ((MOD + 1) / 2)) % MOD;
    cout << res << endl;
}