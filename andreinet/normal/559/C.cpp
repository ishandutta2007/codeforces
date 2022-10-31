#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 2010, Hmax = 100005; const int Mod = 1e9 + 7;
pair<int, int> A[Nmax];

int Fact[3 * Hmax];

int Pow(int x, int y) {
    int ret = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) ret = (i64) ret * x % Mod;
        x = (i64) x * x % Mod;
    }
    return ret;
}

int invmod(int x) {
    return Pow(x, Mod - 2);
}

int Comb(int n, int k) {
    if (n < 0 || k < 0) return 0;
    if (k > n) return 0;
    return (i64) Fact[n] * invmod((i64) Fact[n - k] * Fact[k] % Mod) % Mod;
}

int Paths(int n, int m) {
    if (n <= 0 || m <= 0) return 0;
    return Comb(n + m - 2, n - 1);
}

int dp1[Nmax];

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    Fact[0] = 1;
    for (int i = 1; i <= H + W + 5; ++i)
        Fact[i] = (i64) Fact[i - 1] * i % Mod;
    
    N += 2;
    for (int i = 2; i < N; ++i)
        cin >> A[i].first >> A[i].second;

    A[1] = {1, 1};
    A[N] = {H, W};

    sort(A + 1, A + N + 1);

    dp1[1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < i; ++j) {
            int h = A[i].first - A[j].first + 1;
            int w = A[i].second - A[j].second + 1;
            dp1[i] = (dp1[i] - (i64) dp1[j] * Paths(h, w)) % Mod;
        }
    }

    int ans = (Mod - dp1[N]) % Mod;
    if (ans < 0) ans += Mod;
    cout << ans << '\n';
}