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
const int mod = 998244353, N = 505, logN = 20, K = 111, M = 4e7;

int main () {
    owo;
    int n;
    string s;
    cin >> n >> s;
    n = s.length();
    vector <lli> dp(n + 1, 0);
    vector <string> val(n + 1);
    function <void(int)> dfs = [&](int v) {
        if ((v << 1) > n) {
            dp[v] = 1;
            val[v] = s[v - 1];
            return;
        }
        dfs(v << 1), dfs(v << 1 | 1);
        dp[v] = dp[v << 1] * dp[v << 1 | 1] % mod;
        string l = val[v << 1], r = val[v << 1 | 1];
        if (l > r)
            swap(l, r);
        val[v] = s[v - 1] + l + r;
        if (l != r) 
            dp[v] = dp[v] * 2 % mod;
    };
    dfs(1);
    cout << dp[1] << '\n';
}