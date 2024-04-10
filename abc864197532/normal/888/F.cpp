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
const int mod = 1e9 + 7, N = 100005, logN = 18, G = 3;

int main () {
    owo;
    int n;
    cin >> n;
    vv <int> is(n, n);
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j)
        cin >> is[i][j];
    vvv <lli> dp(n + 1, n + 1, 2, 0);
    for (int i = 0; i < n; ++i)
        dp[i][i + 1][0] = 1;
    for (int d = 2; d <= n; ++d) for (int i = 0; i + d <= n; ++i) {
        int j = i + d;
        if (is[i][j - 1]) {
            // 1
            for (int m = i + 1; m < j; ++m)
                (dp[i][j][1] += 1ll * (dp[i][m][0] + dp[i][m][1]) * (dp[m][j][0] + dp[m][j][1])) %= mod;
        }
        // 0
        for (int m = i + 1; m + 1 < j; ++m) if (is[i][m]) {
            (dp[i][j][0] += 1ll * dp[i][m + 1][1] * (dp[m][j][0] + dp[m][j][1])) %= mod;
        }
    }
    cout << (dp[0][n][0] + dp[0][n][1]) % mod << '\n';
}