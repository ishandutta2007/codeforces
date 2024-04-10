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
const int mod = 998244353, N = 100002, M = 150000, logN = 20, K = 1000;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0 << endl;
        return;
    }
    // find min x s.t. n xor x > m
    /*
     * 0110
     * 1000
     *
     * 0001
     * 1001
     */
    int ans = 0, xorr = n ^ m;
    int l = 0;
    for (int i = 29; ~i; --i) {
        if (xorr >> i & 1) {
            if (n >> i & 1) {
                l = -1;
                break;
            } else {
                ans |= 1 << i;
            }
        } else {
            if (n >> i & 1 ^ 1) l = i;
        }
    }
    /*
     * 010
     * 101
     *
     * 111
     * 111
     */
    if (l != -1) {
        ans |= 1 << l;
        for (int i = l - 1; ~i; --i) if (ans >> i & 1) {
            ans ^= 1 << i;
        }
    }
    cout << ans << endl;
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}