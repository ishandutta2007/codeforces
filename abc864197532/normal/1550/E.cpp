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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111;

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vv <int> pre(n + 1, k, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            pre[i + 1][j] = pre[i][j];
            if (s[i] == 'a' + j || s[i] == '?') pre[i + 1][j]++;
        }
    }
    auto chk = [&](int x) {
        vv <int> pt(n + 2, k, n + 1);
        for (int i = 0; i + x <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (pre[i + x][j] - pre[i][j] == x) pt[i][j] = i + x;
            }
        }
        for (int i = 0; i < k; ++i) pt[n + 1][i] = n + 1;
        for (int i = n; i > 0; --i) {
            for (int j = 0; j < k; ++j) {
                pt[i - 1][j] = min(pt[i - 1][j], pt[i][j]);
            }
        }
        vector <int> dp(1 << k, n + 1);
        dp[0] = 0;
        for (int s = 0; s < 1 << k; ++s) {
            for (int i = 0; i < k; ++i) if (~s >> i & 1) {
                dp[s | 1 << i] = min(dp[s | 1 << i], pt[dp[s]][i]);
            }
        }
        return dp[(1 << k) - 1] <= n;
    };
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (chk(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}