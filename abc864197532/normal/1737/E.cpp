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
const int mod = 1e9 + 7, N = 1 << 20, K = 250;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    vector <ll> pwinv(n + 1);
    pwinv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int inv = (mod + 1) >> 1;
        pwinv[i] = pwinv[i - 1] * inv % mod;
    }
    vector <int> pt(n + 1);
    vector <vector <int>> range(n + 1);
    for (int i = 2; i <= n; ++i)
        pt[i] = i / 2 + 1, range[pt[i]].eb(i);
    vv <ll> dp(n + 2, 2, 0);
    dp[n + 1][0] = 1, dp[n + 1][1] = 0;
    for (int i = n; i; --i) {
        (dp[i][0] += dp[i + 1][0]) %= mod;
        (dp[i][1] += dp[i + 1][1]) %= mod;
        for (int r : range[i]) {
            (dp[i][0] += dp[r + 1][1] * pwinv[r - i + (r != n)]) %= mod;
            (dp[i][1] += dp[r + 1][0] * pwinv[r - i + (r != n)]) %= mod;
        }
    }
    cout << "0\n";
    for (int i = 2; i < n; ++i) {
        ll ans = (dp[i + 1][0] - dp[i + 1][1] + mod) % mod;
        int x = i - pt[i] + 1;
        ans = ans * pwinv[x] % mod;
        cout << ans << '\n';
    }
    cout << pwinv[n - pt[n]] << '\n';
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}