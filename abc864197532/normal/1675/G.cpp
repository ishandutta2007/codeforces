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
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 200001, logN = 20, K = 111, M = 1000006, INF = 1e9 + 87;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> a = {0};
    for (int i = 0, x; i < n; ++i)
        cin >> x, a.pb(a.back() + x);
    // dp[i][j][k] -> first i, last = j, pref = k
    vv <int> pre(m + 1, m + 1, 1 << 30), dp;
    pre[m][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp = vv <int> (m + 1, m + 1, 1 << 30);
        vector <int> now(m + 1, 1 << 30);
        for (int j = m; j >= 0; --j) {
            for (int sum = 0; sum <= m; ++sum)
                now[sum] = min(now[sum], pre[j][sum]);
            for (int sum = 0; sum <= m; ++sum) if (sum >= j)
                dp[j][sum] = min(dp[j][sum], now[sum - j] + abs(sum - a[i]));
        }
        pre = dp;
    }
    int ans = 1 << 30;
    for (int i = 0; i <= m; ++i)
        ans = min(ans, pre[i][m]);
    cout << ans << '\n';
}