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

ll go(int l, int r, const vector<int>& a) {
    if (l == r) {
        return a[l] == 1;
    }
    int mid = (l + r) / 2;
    ll res = go(l, mid, a) + go(mid + 1, r, a);
    vector<int> used(r - l + 2);
    int cnt = 0;
    int mx = 0;
    int j = mid + 1;
    for (int i = mid + 1; i <= r && a[i] <= r - l + 1; i++) {
        mx = max(mx, a[i]);
        cnt += ++used[a[i]] == 1;
        while (j <= mid && used[a[i]] > 1) {
            cnt -= --used[a[j]] == 0;
            j++;
        }
        if (used[a[i]] > 1) break;
        while (j > l && a[j - 1] < mx && !used[a[j - 1]]) {
            j--;
            cnt += ++used[a[j]] == 1;
        }
        if (mx > 1 && mx == cnt && j <= mid) {
            res++;
        }
    }
    used.assign(r - l + 2, 0);
    j = mid;
    mx = cnt = 0;
    for (int i = mid; i >= l && a[i] <= r - l + 1; i--) {
        mx = max(mx, a[i]);
        cnt += ++used[a[i]] == 1;
        while (j > mid && used[a[i]] > 1) {
            cnt -= --used[a[j]] == 0;
            j--;
        }
        if (used[a[i]] > 1) break;
        while (j < r && a[j + 1] < mx && !used[a[j + 1]]) {
            j++;
            cnt += ++used[a[j]] == 1;
        }
        if (mx > 1 && mx == cnt && j > mid) {
            res++;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    cout << go(0, n - 1, a) << endl;
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