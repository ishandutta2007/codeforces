#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')'; 
}

template<typename A> ostream& operator<<(ostream &os, const vector<A> &vt) {
    os << '[';
    for (size_t i = 0; i + 1 < vt.size(); i++) os << vt[i] << ", ";
    if (!vt.empty()) os << vt.back();
    return os << ']';
}

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef GAREN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct SuffixArray {
    static const int N = 100010;

    int n;
    const char *s;
    int sa[N], tmp[N], pos[N];
    int len, cnt[N], lcp[N];

    void init(const char *t) {
        s = t;
        n = strlen(s + 1);
        buildSA();
    }

    bool cmp(int u, int v) {
        if (pos[u] != pos[v]) {
            return pos[u] < pos[v];
        }
        return (u + len <= n && v + len <= n) ? pos[u + len] < pos[v + len] : u > v;
    }

    void radix(int delta) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) {
            cnt[i + delta <= n ? pos[i + delta] : 0]++;
        }
        for (int i = 1; i < N; i++) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n; i > 0; i--) {
            int id = sa[i];
            tmp[cnt[id + delta <= n ? pos[id + delta] : 0]--] = id;
        }
        for (int i = 1; i <= n; i++) {
            sa[i] = tmp[i];
        }
    }

    void buildSA() {
        for (int i = 1; i <= n; i++) {
            sa[i] = i;
            pos[i] = s[i];
        }
        len = 1;
        while (1) {
            radix(len);
            radix(0);
            tmp[1] = 1;
            for (int i = 2; i <= n; i++) {
                tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
            }
            for (int i = 1; i <= n; i++) {
                pos[sa[i]] = tmp[i];
            }
            if (tmp[n] == n) {
                break;
            }
            len <<= 1;
        }

        len = 0;
        for (int i = 1; i <= n; i++) {
            if (pos[i] == n) {
                continue;
            }
            int j = sa[pos[i] + 1];
            while (s[i + len] == s[j + len]) {
                len++;
            }
            lcp[pos[i]] = len;
            if (len) {
                len--;
            }
        }
    }
} sa;

// usage:
//   auto fun = [&](int i, int j) { return min(i, j); };
//   SparseTable<int, decltype(fun)> st(a, fun);
// or:
//   SparseTable<int> st(a, [&](int i, int j) { return min(i, j); });
template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable {
   public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T> &a, const F &f) : func(f) {
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

void run_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    sa.init(s.c_str());
    sa.buildSA();
    vector<int> lcp(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        lcp[i] = sa.lcp[i];
        pos[sa.sa[i]] = i; 
    }
    auto fun = [&](int i, int j) { return min(i, j); };
    SparseTable<int, decltype(fun)> st(lcp, fun);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> comp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int u = pos[i];
            int v = pos[j];
            if (u > v) swap(u, v);
            comp[i][j] = st.get(u, v - 1);
        }
    }
    for (int i = 1; i <= n; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        vector<vector<int>> to_cmp(n - i + 2);
        for (int j = 1; j < i; j++) {
            to_cmp[comp[j][i]].push_back(j);
        }
        for (int j = i; j <= n; j++) {
            for (int e : to_cmp[j - i]) {
                if (e + j - i > n || s[e + j - i] < s[j]) dp[i][j] = max(dp[i][j], dp[e][n] + 1);
            }
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) res = max(res, dp[i][j]);    
    cout << res << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
#ifdef GAREN
    cin.tie(nullptr);
#endif
    int tests = 1;
    cin >> tests;
    while (tests--) run_case();
    return 0;
}