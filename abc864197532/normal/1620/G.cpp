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
    if (a.empty())
        return o << "{}";
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
const int mod = 998244353, N = 500005, logN = 17, K = 350;

int main () {
    owo;
    int n;
    cin >> n;
    vv <int> cnt(n, 26, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s)
            cnt[i][c - 'a']++;
    }
    vector <int> dp(1 << n, 1);
    dp[0] = 0;
    for (int s = 1; s < 1 << n; ++s) {
        for (int j = 0; j < 26; ++j) {
            int res = 1 << 30;
            for (int i = 0; i < n; ++i) if (s >> i & 1)
                res = min(res, cnt[i][j]);
            dp[s] = 1ll * dp[s] * (res + 1) % mod;
        }
        if (__builtin_popcount(s) & 1 ^ 1) {
            dp[s] = mod - dp[s];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int s = 1; s < 1 << n; ++s) if (s >> i & 1) {
            dp[s] += dp[s ^ (1 << i)];
            if (dp[s] >= mod)
                dp[s] -= mod;
        } 
    }
    lli ans = 0;
    for (int s = 1; s < 1 << n; ++s) {
        int now = 0, cnt = 0;
        for (int i = 0; i < n; ++i) if (s >> i & 1)
            now += i + 1, cnt++;
        ans ^= (1ll * dp[s] * now * cnt);
    }
    cout << ans << endl;
}