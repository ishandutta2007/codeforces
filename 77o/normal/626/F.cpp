// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

using ll = long long;

template <typename T>
class DebugIntStream;

template <typename T>
DebugIntStream<T>& operator>>(DebugIntStream<T>&, T&);

template <typename T>
class DebugIntStream {
public:
    DebugIntStream(uint_fast64_t seed, T lowerBound, T upperBound) : 
        rng(seed), distrib(lowerBound, upperBound) {}

    friend DebugIntStream& operator>><T>(DebugIntStream&, T&);

private:
    mt19937_64 rng;
    uniform_int_distribution<T> distrib;
};

template<typename T>
DebugIntStream<T>& operator>>(DebugIntStream<T>& stream, T& num) {
    num = stream.distrib(stream.rng);
    return stream;
}

template <typename T, typename S = istream>
void read(vector<T>& vec, S& in = cin) {
    for (auto& elem : vec) {
        in >> elem;
    }
}

template <typename T, typename S = ostream>
void write(const vector<T>& vec, char delim = ' ', char last = '\n', S& out = cout) {
    bool first = true;
    for (auto& elem : vec) {
        if (!first) {
            out << delim;
        }
        out << elem;
        first = false;
    }
    out << last;
}

const int MOD = 1e9 + 7;
const int NUMB = 998'244'853;
const int DUMB = 998'244'353;

ll binpow(ll a, ll p, ll mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    read(a);
    sort(all(a));
    vector<vector<ll>> dp(k + 1, vector<ll>(n / 2 + 1));
    auto init = dp;
    dp[0][0] = dp[0][1] = 1;
    for (int it = 1; it < n; it++) {
        auto ndp = init;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= n / 2; j++) {
                int cost = i + j * (a[it] - a[it - 1]);
                if (cost > k) break;
                if (j + 1 <= n / 2) (ndp[cost][j + 1] += dp[i][j]) %= MOD;
                (ndp[cost][j] += dp[i][j] * (j + 1)) %= MOD;
                if (j) (ndp[cost][j - 1] += dp[i][j] * j) %= MOD;
            }
        }
        dp = move(ndp);
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        (ans += dp[i][0]) %= MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}