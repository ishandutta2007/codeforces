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

const int N = 1e5 + 5;

int mu[N];

ll count(int n, int m, const vector<int>& l, const vector<int>& r) {
    vector<ll> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<ll> ndp(m + 1);
        ll sum = 0;
        for (int w = l[i]; w <= m; w++) {
            sum += dp[w - l[i]];
            if (w - r[i] - 1 >= 0) {
                sum -= dp[w - r[i] - 1];
            }
            sum = (sum + DUMB) % DUMB; 
            ndp[w] = sum;
        }
        dp = move(ndp);
    }
    ll res = 0;
    for (int w = 0; w <= m; w++) {
        res = (res + dp[w]) % DUMB;
    }
    return res;
}

void solve() {
    mu[1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = i * 2; j < N; j += i) {
            mu[j] -= mu[i];
        } 
    }

    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    ll ans = 0;
    for (int d = 1; d < N; d++) {
        vector<int> a(n), b(n);
        bool bad = false;
        for (int i = 0; i < n; i++) {
            a[i] = (l[i] + d - 1) / d;
            b[i] = r[i] / d;
            bad |= a[i] > b[i]; 
        }
        if (bad) continue;
        ans += mu[d] * count(n, m / d, a, b);
        ans = (ans % DUMB + DUMB) % DUMB;
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