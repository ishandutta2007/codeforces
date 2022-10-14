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
const int mod = 1e9 + 7, N = 400001, logN = 18, K = 1000;

int pw[N];

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    int pre00, pre10, pre11;
    // even 1 and at least one 0
    pre00 = pw[n - 1] - (n & 1 ? 0 : 1);
    pre11 = (n & 1 ? 1 : 0);
    pre10 = (n & 1 ? 0 : 1);
    vv <lli> dp(k + 1, 2, 0); // 0 -> = 1 -> >
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        dp[i][0] = dp[i - 1][0] * (pre00 + pre11) % mod;
        dp[i][1] = (dp[i - 1][0] * pre10 + dp[i - 1][1] * pw[n]) % mod;
    }
    cout << (dp[k][0] + dp[k][1]) % mod << endl;
}

int main () {
    owo;
    pw[0] = 1;
    for (int i = 1; i < N; ++i) pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}