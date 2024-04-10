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
const int mod = 1e9 + 7, N = 2520, logN = 20, K = 350;

int dp[31][31][51];

int solve(int n, int m, int k) {
    if (~dp[n][m][k]) return dp[n][m][k];
    if (n * m < k) return dp[n][m][k] = 1 << 20;
    if (n * m == k || k == 0) return dp[n][m][k] = 0;
    dp[n][m][k] = 1 << 20;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[n][m][k] = min(dp[n][m][k], solve(i, m, j) + solve(n - i, m, k - j) + m * m);
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[n][m][k] = min(dp[n][m][k], solve(n, i, j) + solve(n, m - i, k - j) + n * n);
        }
    }
    return dp[n][m][k];
}

int main () {
    owo;
    for (int i = 0; i < 31; ++i) for (int j = 0; j < 31; ++j) {
        for (int k = 0; k < 51; ++k) dp[i][j][k] = -1;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << endl;
    }
}