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

const int N = 1005;

int p[N], q[N];

int get(int p[], int v) {
    return p[v] == v ? v : p[v] = get(p, p[v]);
}

bool check(int v, int u) {
    int v1 = get(p, v);
    int u1 = get(p, u);
    int v2 = get(q, v);
    int u2 = get(q, u);
    if (v1 == u1 || v2 == u2) {
        return false;
    }
    return true;
}

void unite(int p[], int v, int u) {
    v = get(p, v);
    u = get(p, u);
    p[u] = v;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    iota(p, p + n, 0);
    iota(q, q + n, 0);
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(p, a, b);
    }
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(q, a, b);
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                edges.emplace_back(i + 1, j + 1);
                unite(p, i, j);
                unite(q, i, j);
            }
        }
    }
    cout << edges.size() << '\n';
    for (auto [v, u] : edges) {
        cout << v << ' ' << u << '\n';
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