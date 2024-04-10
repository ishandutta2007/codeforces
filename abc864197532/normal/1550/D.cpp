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

lli fac[N], facp[N];

int C(int n, int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int calc(int a, int b, int c, int n) {
    if (a + b + c < n) return 0;
    if (n & 1) {
        int tmp = C(c, n / 2 - a) + C(c, n / 2 + 1 - a);
        if (tmp >= mod) tmp -= mod;
        return tmp;
    } else {
        return C(c, n / 2 - a);
    }
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    map <int, int> m1;
    for (int i = 1; i <= n; ++i) {
        if (i != 1) m1[l - i] = n - i + 1;
        if (i != n) m1[r - i] = i;
    }
    auto get = [&](int v) {
        if (m1.count(v)) return m1[v];
        else if (l - 1 <= v && v <= r - n) return n;
        else return 0;
    };
    int ans = 0;
    for (pii A : m1) if (A.X < 0 || !m1.count(-A.X)) {
        int now, num1;
        tie(now, num1) = A;
        int num2 = get(-now);
        int both = 0;
        if (num1 + num2 > n) both = num1 + num2 - n;
        num1 -= both;
        num2 -= both;
        ans += calc(num1, num2, both, n);
        if (ans >= mod) ans -= mod;
    }
    // l - 1 <= v && v <= r - n, both n
    int mn = min(1 - l, r - n);
    // mn times;
    ans += 1ll * calc(0, 0, n, n) * mn % mod;
    if (ans >= mod) ans -= mod;
    cout << ans << endl;
    /*
     *       -1 0 1 2
     *    -2 -1 0 1
     * -3 -2 -1 0
     *
     *       0 1 2
     *    -1 0 1
     * -2 -1 0
     */
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod, facp[i] = modpow(fac[i], mod - 2);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}