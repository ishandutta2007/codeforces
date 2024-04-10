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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) {
        cin >> e;
    }

    SparseTable<int> stMx(a, [&](int i, int j) { return max(i, j); });
    SparseTable<int> stMn(a, [&](int i, int j) { return min(i, j); });
    
    vector<pair<int, int>> range(n);
    int i = 0;
    int cur = 0;
    while (i != n - 1) {
        int firstLower = n, firstUpper = n;
        {
            int l = i + 1, r = n - 1;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (stMx.get(i + 1, mid) > a[i]) {
                    firstUpper = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
        }
        {
            int l = i + 1, r = n - 1;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (stMn.get(i + 1, mid) < a[i]) {
                    firstLower = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
        }
        if (a[i + 1] > a[i]) {
            int foo = stMx.get(i, firstLower - 1);
            int id = -1;
            int l = i + 1, r = firstLower - 1;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (stMx.get(i + 1, mid) == foo) {
                    id = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            cur++;
            i = id;
        } else {
            int foo = stMn.get(i, firstUpper - 1);
            int id = -1;
            int l = i + 1, r = firstUpper - 1;
            while (r >= l) {
                int mid = (l + r) / 2;
                if (stMn.get(i + 1, mid) == foo) {
                    id = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            cur++;
            i = id;
        }
    }
    cout << cur << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}