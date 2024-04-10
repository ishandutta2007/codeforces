#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 998244353, N = 58 << 20;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vv <int> dp(n + 1, n + 1); // 1 -> Alice, 0 -> Draw, -1 -> Bob
    for (int i = 0; i + 2 <= n; ++i) {
        if (s[i] == s[i + 1])
            dp[i][i + 2] = 0;
        else
            dp[i][i + 2] = 1;
    }
    auto get = [&](char a, char b) {
        if (a < b)
            return -1;
        if (a == b)
            return 0;
        return 1;
    };
    for (int len = 4; len <= n; len += 2) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len, mx = -1;
            // Alice first
            int val = min(dp[i + 1][j - 1] == 0 ? get(s[i], s[j - 1]) : dp[i + 1][j - 1], dp[i + 2][j] == 0 ? get(s[i], s[i + 1]) : dp[i + 2][j]);
            mx = max(mx, val);
            // Alice last
            val = min(dp[i][j - 2] == 0 ? get(s[j - 1], s[j - 2]) : dp[i][j - 2], dp[i + 1][j - 1] == 0 ? get(s[j - 1], s[i]) : dp[i + 1][j - 1]);
            mx = max(mx, val);
            dp[i][j] = mx;
        }
    }
    if (dp[0][n] == 1)
        cout << "Alice\n";
    else if (dp[0][n] == 0)
        cout << "Draw\n";
    else
        cout << "Bob\n";
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}