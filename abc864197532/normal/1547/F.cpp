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
const int mod = 998244353, N = 1000001, logC = 30, logN = 19, K = 111, M = 4e6;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, g = 0;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i], g = __gcd(g, a[i]);
        for (int i = 0; i < n; ++i) a[i] /= g;
        vv <int> val(n * 2, 19, 0);
        for (int i = 0; i < n; ++i) val[i][0] = val[i + n][0] = a[i];
        for (int j = 1; j < 19; ++j) for (int i = 0; i + (1 << j) <= n * 2; ++i) {
            val[i][j] = __gcd(val[i][j - 1], val[i + (1 << j - 1)][j - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n * 2; ++i) {
            int g = 0, tmp = 0;
            for (int j = 18; ~j; --j) if (i + tmp + (1 << j) <= n * 2) {
                if (__gcd(g, val[i + tmp][j]) > 1) {
                    g = __gcd(g, val[i + tmp][j]);
                    tmp |= 1 << j;
                }
            }
            ans = max(ans, tmp + 1);
        }
        cout << ans - 1 << endl;
    }
}