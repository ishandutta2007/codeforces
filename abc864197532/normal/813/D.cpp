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
const int mod = 1e9 + 7, N = 5001, logN = 20, K = 111;

int dp[N][N], mx2[100001];

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector <int> mx1(7, 0);
    for (int i = 1; i <= n; ++i) {
        // same mod
        dp[0][i] = max(dp[0][i], mx1[a[i] % 7] + 1);
        // diff 1
        dp[0][i] = max(dp[0][i], mx2[a[i] - 1] + 1);
        dp[0][i] = max(dp[0][i], mx2[a[i] + 1] + 1);
        // update
        mx1[a[i] % 7] = max(mx1[a[i] % 7], dp[0][i]);
        mx2[a[i]] = max(mx2[a[i]], dp[0][i]);
        dp[i][0] = dp[0][i];
    }
    for (int i = 1; i <= n; ++i) {
        mx1.assign(7, 0);
        for (int j : a) mx2[j] = 0;
        for (int j = 1; j <= i; ++j) {
            mx1[a[j] % 7] = max(mx1[a[j] % 7], dp[i][j]);
            mx2[a[j]] = max(mx2[a[j]], dp[i][j]);
        }
        for (int j = i + 1; j <= n; ++j) {
            // same mod
            dp[i][j] = max(dp[i][j], mx1[a[j] % 7] + 1);
            // diff 1
            dp[i][j] = max(dp[i][j], mx2[a[j] - 1] + 1);
            dp[i][j] = max(dp[i][j], mx2[a[j] + 1] + 1);
            // new one
            dp[i][j] = max(dp[i][j], dp[i][0] + 1);
            // update
            mx1[a[j] % 7] = max(mx1[a[j] % 7], dp[i][j]);
            mx2[a[j]] = max(mx2[a[j]], dp[i][j]);
            dp[j][i] = dp[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n; ++j) {
        ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}