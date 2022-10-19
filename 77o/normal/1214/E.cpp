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
    // lowerBound, upperBound better be not close to min/max values, too lazy to handle
    DebugIntStream(uint_fast64_t seed, T lowerBound, T upperBound) : 
        rng(seed), lowerBound(lowerBound), upperBound(upperBound), len(upperBound - lowerBound + 1) {}

    friend DebugIntStream& operator>><T>(DebugIntStream&, T&);

private:
    mt19937_64 rng;
    const T lowerBound, upperBound;
    const uint_fast64_t len;
};

template<typename T>
DebugIntStream<T>& operator>>(DebugIntStream<T>& stream, T& num) {
    num = stream.lowerBound + stream.rng() % stream.len;
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i].first;
        d[i].second = 2 * i + 1;
    }
    sort(rall(d));
    vector<vector<int>> bulbs(n);
    for (int i = 0; i < n; i++) {
        bulbs[i].push_back(d[i].second);
    }
    for (int i = 0; i < n; i++) {
        int nxt = i + d[i].first;
        if (bulbs.size() <= nxt) {
            bulbs.push_back({});
        }
        assert(bulbs.size() > nxt);
        if (!bulbs[nxt].empty()) {
            nxt--;
        }
        bulbs[nxt].push_back(d[i].second + 1);
    }
    for (int i = 0; i < bulbs.size(); i++) {
        if (i + 1 < bulbs.size())
            cout << bulbs[i][0] << ' ' << bulbs[i + 1][0] << '\n';
        for (int j = 1; j < bulbs[i].size(); j++) {
            cout << bulbs[i][0] << ' ' << bulbs[i][j] << '\n';
        }
    }
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