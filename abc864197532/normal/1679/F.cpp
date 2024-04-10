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
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    vector <int> g(10), g2(10);
    for (int i = 0; i < 10; ++i)
        g2[i] |= 1 << i;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[v] |= 1 << u, g2[v] |= 1 << u, g2[u] |= 1 << v;
    }
    vv <int> dp(n, 1 << 10, 0);
    for (int i = 0; i < 10; ++i)
        dp[0][g[i]]++;
    for (int i = 0; i + 1 < n; ++i) {
        for (int s = 0; s < 1 << 10; ++s) if (dp[i][s]) {
            for (int x = 0; x < 10; ++x) if (~s >> x & 1) {
                int nxt = g[x] | (s & g2[x]);
                dp[i + 1][nxt] += dp[i][s];
                if (dp[i + 1][nxt] >= mod)
                    dp[i + 1][nxt] -= mod;
            }
        }
    }
    cout << accumulate(all(dp[n - 1]), 0ll) % mod << '\n';
}