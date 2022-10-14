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
const int mod = 998244353, N = 2001, logC = 30, logN = 19, K = 111, M = 4e6;

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
}

int main () {
    owo;
    string s, t;
    cin >> s >> t;
    s = "$" + s, t = "#" + t;
    int n = s.length(), m = t.length();
    vvv <int> dp(n + 1, m + 1, 2, 0);
    int ans = 0;
    for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) {
        if (s[i - 1] == s[i]) dp[i][j][1] = 1;
        else dp[i][j][1] = dp[i - 1][j][1] + 1;
        if (t[j - 1] == t[j]) dp[i][j][0] = 1;
        else dp[i][j][0] = dp[i][j - 1][0] + 1;
    }
    for (int i = 1; i < n; ++i) for (int j = 1; j < m; ++j) {
        if (s[i] == t[j]) dp[i][j][0] = dp[i][j][1] = 0;
        if (s[i] != s[i - 1]) {
            add(dp[i][j][0], dp[i - 1][j][0]);
        }
        if (s[i] != t[j]) {
            add(dp[i][j][0], dp[i - 1][j][1]);
        }
        if (t[j] != s[i]) {
            add(dp[i][j][1], dp[i][j - 1][0]);
        }
        if (t[j] != t[j - 1]) {
            add(dp[i][j][1], dp[i][j - 1][1]);
        }
        add(ans, dp[i][j][0]);
        add(ans, dp[i][j][1]);
    }
    cout << ans << endl;
}