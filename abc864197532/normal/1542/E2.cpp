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

int dp[501][124751], mod, pre[124752];

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
    if (i < 0) i += mod;
}

int main () {
    owo;
    int n;
    cin >> n >> mod;
    int k = n * (n - 1) / 2;
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        pre[0] = 0;
        for (int j = 0; j <= k; ++j) pre[j + 1] = pre[j], add(pre[j + 1], dp[i - 1][j]);
        for (int j = 0; j <= k; ++j) {
            add(dp[i][j], pre[j + 1] - pre[max(j - i + 1, 0)]);
        }
    }
    int ans = 0;
    for (int len = 4; len <= n; ++len) {
        pre[0] = 0;
        for (int i = 0; i <= k; ++i) pre[i + 1] = pre[i], add(pre[i + 1], dp[len - 1][i]);
        int now = 0, cnt = 0, cnt2 = 0;
        for (int i = 0; i <= k; ++i) {
            add(now, 1ll * cnt * dp[len - 1][i] % mod);
            add(cnt, cnt2);
            add(cnt2, 1ll * (len - 1) * dp[len - 1][i] % mod);
            add(cnt2, -pre[i] + pre[max(i - len + 1, 0)]);
        }
        for (int i = n; i > len; --i) now = 1ll * now * i % mod;
        add(ans, now);
    }
    cout << ans << endl;
    /*
     * 1 2 3 -> 0
     * 1 3 2 -> 1
     * 2 1 3 -> 1
     * 2 3 1 -> 2
     * 3 1 2 -> 2
     * 3 2 1 -> 3
     */
    /*
    vector <int> p(n), q(n);
    iota(all(p), 0);
    iota(all(q), 0);
    int tans = 0;
    do {
        do {
            if (p < q && inv(p) > inv(q)) tans++;
        } while (next_permutation(all(q)));
    } while (next_permutation(all(p)));
    cout << tans << endl;
     */
}