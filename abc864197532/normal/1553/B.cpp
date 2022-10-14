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

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vvv <bool> vis(m, n, 2, false);
    for (int i = 0; i < n; ++i) if (s[i] == t[0]) vis[0][i][0] = true;
    for (int i = 0; i + 1 < m; ++i) for (int j = 0; j < n; ++j) {
        if (vis[i][j][0]) vis[i][j][1] = true;
        if (vis[i][j][0]) {
            if (j + 1 < n && t[i + 1] == s[j + 1]) vis[i + 1][j + 1][0] = true;
        }
        if (vis[i][j][1]) {
            if (j && t[i + 1] == s[j - 1]) vis[i + 1][j - 1][1] = true;
        }
    }
    bool is = false;
    for (int i = 0; i < n; ++i) is |= vis[m - 1][i][0] | vis[m - 1][i][1];
    cout << (is ? "YES\n" : "NO\n");
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}