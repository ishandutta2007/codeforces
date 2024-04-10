#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 500001;

vector <int> build(string s) {
    int n = s.length();
    vector <int> Z(n);
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        Z[i] = max(min(Z[i - l], r - i), 0);
        while (i + Z[i] < s.size() && s[Z[i]] == s[i + Z[i]]) {
            l = i, r = i + Z[i], Z[i]++;
        }
    }
    return Z;
}

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

void solve() {
    string s, l, r;
    cin >> s >> l >> r;
    vector <int> LZ = build(l + '$' + s);
    vector <int> RZ = build(r + '$' + s);
    int a = l.length(), b = r.length(), n = s.length();
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    vector <int> pre(n + 2, 0);
    pre[1] = 1;
    auto chk_l = [&](int sl, int sr) {
        int lcp = LZ[sl + a + 1];
        if (lcp >= sr - sl)
            return true;
        return l[lcp] < s[sl + lcp];
    };
    auto chk_r = [&](int sl, int sr) {
        int lcp = RZ[sl + b + 1];
        if (lcp >= sr - sl)
            return true;
        return r[lcp] > s[sl + lcp];
    };
    for (int i = 1; i <= n; ++i) {
        if (a == b) {
            if (i >= a && chk_l(i - a, i) && chk_r(i - a, i) && (a == 1 || s[i - a] != '0')) {
                add(dp[i], dp[i - a]);
            }
        } else {
            add(dp[i], pre[max(i - a, 0)]), add(dp[i], mod - pre[max(i - b + 1, 0)]);
            if (i >= a && chk_l(i - a, i) && (a == 1 || s[i - a] != '0')) {
                add(dp[i], dp[i - a]);
            }
            if (i >= b && chk_r(i - b, i) && s[i - b] != '0') {
                add(dp[i], dp[i - b]);
            }
        }
        pre[i + 1] = pre[i];
        if (s[i] != '0')
            add(pre[i + 1], dp[i]);
    }
    cout << dp[n] << '\n';
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}