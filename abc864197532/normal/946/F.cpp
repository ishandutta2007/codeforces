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
const int mod = 1e9 + 7, N = 101, logC = 30, logN = 19, K = 111, M = 4e6;

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
}

int dp[N][N][N], pw[N];

int main () {
    owo;
    pw[0] = pw[1] = 2;
    for (int i = 2; i < N; ++i) {
        pw[i] = 1ll * pw[i - 1] * pw[i - 2] % mod;
    }
    int n, m;
    string s;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        dp[s[i] - '0'][i][i + 1] = 1;
    }
    for (int i = 2; i <= m; ++i) {
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r <= n; ++r) {
                add(dp[i][l][r], 1ll * dp[i - 1][l][r] * (r == n ? pw[i - 2] : 1) % mod);
                add(dp[i][l][r], 1ll * dp[i - 2][l][r] * (l == 0 ? pw[i - 1] : 1) % mod);
                for (int k = l + 1; k < r; ++k) {
                    add(dp[i][l][r], 1ll * dp[i - 1][l][k] * dp[i - 2][k][r] % mod);
                }
            }
        }
    }
    cout << dp[m][0][n] << endl;
}