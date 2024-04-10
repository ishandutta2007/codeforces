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
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 500005, logC = 30, K = 450;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> a(n + 1);
    stack <int> stk;
    vector <lli> dp(n + 1, 0), pre(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0] = pre[1] = 1;
    stk.push(0);
    lli cur = 0;
    for (int i = 1; i <= n; ++i) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            int x = stk.top();
            stk.pop();
            (cur -= (pre[x] - pre[stk.top()] + mod) * a[x]) %= mod;
        }
        (cur += (pre[i] - pre[stk.top()] + mod) * a[i]) %= mod;
        stk.push(i);
        dp[i] = (mod - cur) % mod;
        pre[i + 1] = (pre[i] + dp[i]) % mod;
    }
    if (n & 1)
        dp[n] = (mod - dp[n]) % mod;
    cout << dp[n] << endl;
}