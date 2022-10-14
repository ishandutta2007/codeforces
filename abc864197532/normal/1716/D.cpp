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
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1 << 18, logN = 18, G = 3;

int dp[N][2], pre[N], ans[N];

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    dp[0][(k & 1) ^ 1] = 1;
    int t = 0, now = 0;
    while (t < n) {
        t += k + now;
        now++;
    }
    for (int i = k; i <= k + now + 4; ++i) {
        for (int j = 0; j <= n; ++j)
            dp[j][i & 1] = 0;
        fill(pre, pre + N, 0);
        for (int j = 0; j <= n; ++j) {
            dp[j][i & 1] = pre[j % i];
            if (dp[j][i & 1] >= mod)
                dp[j][i & 1] -= mod;
            pre[j % i] += dp[j][i & 1 ^ 1];
            if (pre[j % i] >= mod)
                pre[j % i] -= mod;
        }
        for (int j = 0; j <= n; ++j) {
            ans[j] += dp[j][i & 1];
            if (ans[j] >= mod)
                ans[j] -= mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}