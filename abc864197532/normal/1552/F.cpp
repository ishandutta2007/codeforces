/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000002, M = 150000, logN = 20, K = 1000;

void solve() {
    int n;
    cin >> n;
    vector <lli> dp(n + 1, 0);
    vector <lli> pre(n + 2, 0);
    vector <lli> cor = {0};
    lli ans = 1, x, y, s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> s;
        cor.pb(x);
        int p = upper_bound(all(cor), y) - cor.begin() - 1;
        dp[i] = ((x - cor[i]) * 2 - (y - cor[p]) + pre[i] - pre[p]) % mod;
        pre[i + 1] = (pre[i] + dp[i]) % mod;
        if (dp[i] < 0) dp[i] += mod;
        if (pre[i + 1] < 0) pre[i + 1] += mod;
        if (s) ans += dp[i];
        else ans += x - cor[i];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}