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
const int mod = 998244353, N = 300001, C = 550;

ll solve(vv <ll> val) {
    int m = val.size();
    vv <ll> dp(m, 2, 0);
    dp[0][0] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int b : {0, 1}) {
                (dp[i][b] += dp[j][b ^ 1] * val[j][i]) %= mod;
            }
        }
    }
    return (dp[m - 1][1] + mod - dp[m - 1][0]) % mod;
}

void solve() {
    int d, n, m;
    cin >> d >> n >> m;
    vector <int> in(n), spec(m + 2);
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    for (int i = 0; i < m; ++i)
        cin >> spec[i];
    spec[m] = -d, spec[m + 1] = d + d;
    sort(all(spec));
    vv <ll> val(m + 2, m + 2, 1);
    for (int i = 0; i < m + 2; ++i) for (int j = i + 1; j < m + 2; ++j) {
        for (int x : in) if (spec[i] < x && x < spec[j]) {
            int len = min({x - spec[i], spec[j] - x, d + 1});
            val[i][j] = val[i][j] * len % mod;
        }
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        vv <ll> now = val;
        for (int i = 0; i < m + 2; ++i) for (int j = i + 1; j < m + 2; ++j) if (spec[i] < x && x < spec[j]) {
            int len = min({x - spec[i], spec[j] - x, d + 1});
            now[i][j] = now[i][j] * len % mod;
        }
        cout << solve(now) << '\n';
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}