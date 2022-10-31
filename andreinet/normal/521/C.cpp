#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Mod = 1e9 + 7;

int Pow2[Nmax], Sum[Nmax], Fact[Nmax];
int Dp[Nmax];

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) ret = 1LL * ret * x % Mod;
        x = 1LL * x * x % Mod;
    }
    return ret;
}

int invmod(int x) {
    return Pow(x, Mod - 2);
}

int comb(int N, int K) {
    if (K > N) return 0;
    return 1LL * Fact[N] * invmod(1LL * Fact[K] * Fact[N - K] % Mod) % Mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, K;
    string S;
    cin >> N >> K >> S;

    Pow2[0] = 1;
    for (int i = 1; i <= N; ++i)
        Pow2[i] = 2 * Pow2[i - 1] % Mod;
    Sum[0] = 1;
    for (int i = 1; i <= N; ++i)
        Sum[i] = (Sum[i - 1] + Pow2[i]) % Mod;

    Fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        Fact[i] = 1LL * Fact[i - 1] * i % Mod;

    for (int i = 1, pw10 = 1; i <= N; ++i) {
        int s = comb(N - i - 1, K - 1);
        Dp[i] = (Dp[i - 1] + 1LL * pw10 * s) % Mod;
        pw10 = 10LL * pw10 % Mod;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int add = 1LL * Dp[N - i - 1] * (S[i] - '0') % Mod;
        int pw10 = Pow(10, N - i - 1);
        add = (add + 1LL * pw10 * comb(i, K) % Mod * (S[i] - '0')) % Mod;
        ans = (ans + add) % Mod;
    }

    cout << ans << '\n';
}