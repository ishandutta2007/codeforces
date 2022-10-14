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
const int mod = 998244353, N = 500001, logN = 18, K = 1000;

vector <pii> rest[N];

int solve(int n, int bit) {
    vector <int> exist(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (pii A : rest[i]) if (A.Y >> bit & 1) {
            exist[A.X]++, exist[i]--;
        }
    }
    for (int i = 1; i <= n; ++i) exist[i] += exist[i - 1];
    vector <int> dp(n + 1, 0);
    vector <int> pre(n + 2, 0);
    dp[0] = 1, pre[1] = 1;
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (!exist[i - 1]) {
            dp[i] = pre[i] - pre[mx];
            if (dp[i] < 0) dp[i] += mod;
        }
        pre[i + 1] = pre[i] + dp[i];
        if (pre[i + 1] >= mod) pre[i + 1] -= mod;
        for (pii A : rest[i]) if (~A.Y >> bit & 1) {
            mx = max(mx, A.X + 1);
        }
    }
    test(dp, pre);
    pre[n + 1] -= pre[mx];
    if (pre[n + 1] < 0) pre[n + 1] += mod;
    return pre[n + 1];
}


int main () {
    owo;
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0, l, r, x; i < m; ++i) {
        cin >> l >> r >> x;
        rest[r].eb(--l, x);
    }
    lli ans = 1;
    for (int i = 0; i < k; ++i) ans = ans * solve(n, i) % mod;
    cout << ans << endl;
}