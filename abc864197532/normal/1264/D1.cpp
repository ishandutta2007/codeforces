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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1e6 + 5, logN = 20, K = 111, C = 7;

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

void sub(int &i, int j) {
    i -= j;
    if (i < 0)
        i += mod;
}

bool ok_left(char c) {
    return c == '?' || c == '(';
}

bool ok_right(char c) {
    return c == '?' || c == ')';
}

int main () {
    owo;
    string s;
    cin >> s;
    int n = s.length();
    vector <int> pre(n + 1), pw(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        pre[i] = pre[i - 1] + (s[i - 1] == '?'), pw[i] = pw[i - 1] * 2 % mod;
    vv <int> dp(n + 1, n + 1, 0);
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            if (ok_left(s[l]) && ok_right(s[r - 1]))
                add(dp[l][r], dp[l + 1][r - 1]), add(dp[l][r], pw[pre[r - 1] - pre[l + 1]]);
            if (ok_left(s[r - 1]))
                add(dp[l][r], dp[l][r - 1]);
            if (ok_right(s[l]))
                add(dp[l][r], dp[l + 1][r]);
            if (ok_right(s[l]) && ok_left(s[r - 1]))
                sub(dp[l][r], dp[l + 1][r - 1]);
        }
    }
    cout << dp[0][n] << endl;
}