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
    ll n, k;
    cin >> n >> k;
    ll best = LLONG_MAX;
    vector<int> digits;
    ll m = n;
    set<int> setik;
    while (m) {
        setik.insert(m % 10);
        digits.push_back(m % 10);
        m /= 10;
    }
    if (setik.size() <= k) {
        cout << n << '\n';
        return;
    }
    reverse(digits.begin(), digits.end());
    m = digits.size();
    ll cur = 0;
    array<int, 10> used;
    used.fill(0);
    for (int pref = 0; pref < m; pref++) {
        for (int d = digits[pref] + 1; d < 10; d++) {
            auto tmp = used;
            tmp[d] = 1;
            tmp[0] = 1;
            ll x = cur * 10 + d;
            for (int i = pref + 1; i < m; i++) {
                x = x * 10;
            }
            if (accumulate(tmp.begin(), tmp.end(), 0) <= k) {
                best = min(best, x);
            }
            tmp = used;
            tmp[d] = 1;
            int low = -1;
            for (int i = 0; i < 10; i++) {
                if (tmp[i]) {
                    low = i;
                    break;
                }
            }
            x = cur * 10 + d;
            for (int i = pref + 1; i < m; i++) {
                x = x * 10 + low;
            }
            if (accumulate(tmp.begin(), tmp.end(), 0) <= k) {
                best = min(best, x);
            }
        }

        cur = cur * 10 + digits[pref];
        used[digits[pref]] = 1;
    }

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}