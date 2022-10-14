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
const int mod = 1e9 + 7, N = 2e5 + 101, logN = 18;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vv <int> a(n, m, 0);
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j)
            cin >> a[i][j];
        vector <int> pre(1 << n, -1 << 30), dp;
        pre[0] = 0;
        int full = (1 << n) - 1;
        for (int i = 0; i < m; ++i) {
            dp = pre;
            vector <int> v(n);
            for (int j = 0; j < n; ++j)
                v[j] = a[j][i];
            for (int _ = 0; _ < n; ++_) {
                vector <int> val(1 << n, 0);
                for (int s = 1; s < 1 << n; ++s) {
                    val[s] = val[s ^ (s & (-s))] + v[__lg(s & (-s))];
                }
                for (int s = 0; s < 1 << n; ++s) {
                    for (int t = s ^ full; t > 0; t = (t - 1) & (s ^ full)) {
                        dp[s | t] = max(dp[s | t], pre[s] + val[t]);
                    }
                }
                rotate(v.begin(), v.begin() + 1, v.end());
            }
            pre = dp;
        }
        cout << dp[(1 << n) - 1] << '\n';
    }
}