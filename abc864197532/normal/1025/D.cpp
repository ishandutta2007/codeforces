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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 19, K = 1 << 9, G = 3;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vvv <bool> dp(n + 3, n + 3, 2, false);
    vv <bool> ok(n + 3, n + 3, false);
    for (int i = 0; i < n + 2; ++i) for (int j = 0; j < n + 2; ++j)
        ok[i][j] = __gcd(a[i], a[j]) > 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][i + 1][0] = ok[i - 1][i];
        dp[i][i + 1][1] = ok[i][i + 1];
    }
    for (int i = 0; i <= n + 2; ++i)
        dp[i][i][0] = dp[i][i][1] = true;
    for (int d = 2; d <= n; ++d) {
        for (int i = 1, j = d + 1; j <= n + 1; ++i, ++j) {
            for (int k = i; k < j; ++k) {
                if (ok[i - 1][k] && dp[i][k][1] && dp[k + 1][j][0]) {
                    dp[i][j][0] = true;
                    break;
                }
            }
            for (int k = i; k < j; ++k) {
                if (ok[k][j] && dp[i][k][1] && dp[k + 1][j][0]) {
                    dp[i][j][1] = true;
                    break;
                }
            }
        }
    }
    cout << (dp[1][n + 1][0] || dp[1][n + 1][1] ? "YES\n" : "NO\n");
}