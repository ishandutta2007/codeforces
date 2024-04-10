#include <bits/stdc++.h>

using namespace std;

// debugger, source: tourist
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define int long long

const int N = 50005;
const int INF = 1e18 + 7;

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
   public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int it[4 * N];

void update(int k, int l, int r, int id, int val) {
    if (l > id || r < id) {
        return;
    }
    if (l == id && r == id) {
        it[k] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * k, l, mid, id, val);
    update(2 * k + 1, mid + 1, r, id, val);
    it[k] = max(it[2 * k], it[2 * k + 1]);
}

int get(int k, int l, int r, int u, int v) {
    if (l > v || r < u) return -INF;
    if (l >= u && r <= v) return it[k];
    int mid = (l + r) / 2;
    return max(get(2 * k, l, mid, u, v), get(2 * k + 1, mid + 1, r, u, v));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x;
        cin >> n;
        for (int i = 0; i <= 4 * (n + 1); i++) it[i] = -INF;
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> pref[i];
            pref[i] += pref[i - 1];
        }
        cin >> x;
        for (int i = 1; i <= n; i++) {
            pref[i] -= x * i;
        }
        SparseTable<int> sp(pref, [&](int i, int j) { return max(i, j); });
        vector<vector<int>> res(n + 1, vector<int>(2, -INF));
        res[0][0] = res[0][1] = 0;
        update(1, 0, n, 0, 0);
        vector<int> maxL(n + 1);
        for (int i = 1; i <= n; i++) {
            res[i][0] = res[i - 1][1];
            res[i][1] = max(res[i - 1][0] + 1, res[i - 1][1]);
            int prev = -1;
            int l = maxL[i - 1], r = i - 2;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (sp.get(mid, i - 2) <= pref[i] && (mid > i - 3 || sp.get(mid, i - 3) <= pref[i - 1])) {
                    prev = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            if (prev == -1) {
                maxL[i] = i - 1;
                update(1, 0, n, i, res[i][0] - i);
                continue;
            }
            maxL[i] = prev;
            res[i][1] = max(res[i][1], i + get(1, 0, n, prev, i - 2));
            update(1, 0, n, i, res[i][0] - i);
        }
        cout << max(res[n][0], res[n][1]) << '\n';
    }
    return 0;
}