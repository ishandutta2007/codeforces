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

const int N = 4e6 + 5;

int lp[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        if (lp[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!lp[j]) lp[j] = i;
        }
    }

    vector<int> dp(n + 1);
    dp[1] = 1;
    int sum = 1;
    int kekw = 0;
    vector<pair<int, int>> hui;
    vector<int> num;
    for (int i = 2; i <= n; i++) {
        hui.clear();
        int x = i;
        while (lp[x]) {
            int cnt = 1;
            int div = lp[x];
            while (x % div == 0) {
                x /= div;
                cnt++;
            }
            hui.emplace_back(div, cnt);
        }
        num.assign(hui.size(), 0);
        while (true) {
            int r = 1;
            for (int j = sz(num) - 1; j >= 0; j--) {
                num[j] += r;
                r = num[j] / hui[j].second;
                num[j] %= hui[j].second;
            }
            if (r) break;
            int d = 1;
            for (int j = 0; j < sz(num); j++) {
                for (int k = 0; k < num[j]; k++) {
                    d *= hui[j].first;
                }
            }
            kekw -= dp[(i - 1) / d];
            if (kekw < 0) kekw += m;
            kekw += dp[i / d];
            if (kekw >= m) kekw -= m;
        }
        // for (int d : divs[i]) {
        //     kekw -= dp[(i - 1) / d];
        //     if (kekw < 0) kekw += m;
        //     kekw += dp[i / d];
        //     if (kekw >= m) kekw -= m;
        // }

        dp[i] = (sum + kekw) % m;
        sum = (sum + dp[i]) % m;
    }

    // write(dp);
    cout << dp[n] << endl;
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