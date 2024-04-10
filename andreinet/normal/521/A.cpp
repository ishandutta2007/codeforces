#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005, Mod = 1e9 + 7;

int Fact[Nmax];

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
    return 1LL * Fact[N] * invmod(1LL * Fact[N - K] * Fact[K] % Mod) % Mod;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    vector<int> count(26, 0);
    for (char p: S) count[p - 'A']++;

    int maxs = 0, s = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] > maxs) {
            maxs = count[i];
            s = 1;
        } else if (count[i] == maxs) {
            s++;
        }
    }

    Fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        Fact[i] = 1LL * Fact[i - 1] * i % Mod;

    int ans = 1;
    ans = Pow(s, N);

    cout << ans << '\n';
}