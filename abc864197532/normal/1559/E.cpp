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
const int mod = 998244353, N = 100087, logN = 18, K = 1000;

int lp[N], mu[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    mu[1] = 1;
    for (int i = 2; i < N; ++i) {
        if (lp[i] == lp[i / lp[i]]) mu[i] = 0;
        else mu[i] = mu[i / lp[i]] * -1;
    }
}

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
    if (i < 0) i += mod;
}

lli solve(vector <int> l, vector <int> r, int bound) {
    int n = l.size();
    vv <int> dp(n + 1, bound + 2, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= bound; ++j) {
            // j -> [j + l, j + r]
            add(dp[i + 1][min(j + l[i], bound + 1)], dp[i][j]);
            add(dp[i + 1][min(j + r[i], bound + 1)], -dp[i][j]);
        }
        for (int j = 1; j <= bound + 1; ++j) {
            add(dp[i + 1][j], dp[i + 1][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= bound; ++i) add(ans, dp[n][i]);
    return ans;
}

int main () {
    owo;
    build();
    int n, m;
    cin >> n >> m;
    vector <pii> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], a[i].Y++;
    lli ans = 0;
    for (int g = 1; g <= m; ++g) {
        int bound = m / g;
        vector <int> l(n), r(n);
        for (int i = 0; i < n; ++i) l[i] = (a[i].X + g - 1) / g, r[i] = (a[i].Y + g - 1) / g;
        (ans += solve(l, r, bound) * mu[g]) %= mod;
    }
    if (ans < 0) ans += mod;
    cout << ans << endl;
}