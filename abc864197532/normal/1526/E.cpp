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
const int mod = 998244353, N = 200001, logC = 30, logN = 19, K = 111, M = 4e6;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

lli fac[N], facp[N];

lli C(int n, int m) {
    if (n < m || m < 0 || n < 0) return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod, facp[i] = facp[i - 1] * modpow(i, mod - 2) % mod;
    int n, k;
    cin >> n >> k;
    vector <int> sa(n), rk(n);
    for (int i = 0; i < n; ++i) cin >> sa[i], rk[sa[i]] = i;
    int cnt = 0;
    rk.pb(-1);
    for (int i = 0; i + 1 < n; ++i) {
        if (rk[sa[i] + 1] <= rk[sa[i + 1] + 1]) cnt++;
    }
    lli ans = 0;
    // C(k, n - i) * C(cnt, i) // k + cnt item, sum n
    for (int i = 0; i <= cnt; ++i) {
        ans += C(k, n - i) * C(cnt, i) % mod;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
}