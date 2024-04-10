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
const int mod = 998244353, N = 200087, logN = 19, K = 111, M = 1000006, C = 500;

int main () {
    owo;
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector <map <int, int>> pre(n + 5 >> 1);
    // odd length
    for (int c = 0; c < n; ++c) {
        int msk = 0, cnt = 0;
        int i = c - 1, j = c + 1;
        while (i >= 0 && j < n) {
            if (s[i] == '?' && s[j] == '?') {
                cnt++;
            } else if (s[i] == '?') {
                msk |= 1 << s[j] - 'a', cnt++;
            } else if (s[j] == '?') {
                msk |= 1 << s[i] - 'a', cnt++;
            } else if (s[i] != s[j]) {
                // fail
                break;
            }
            pre[cnt][msk]++;
            i--, j++;
        }
    }
    // even length
    for (int c = 0; c + 1 < n; ++c) {
        int msk = 0, cnt = 0;
        int i = c, j = c + 1;
        while (i >= 0 && j < n) {
            if (s[i] == '?' && s[j] == '?') {
                cnt++;                
            } else if (s[i] == '?') {
                msk |= 1 << s[j] - 'a', cnt++;
            } else if (s[j] == '?') {
                msk |= 1 << s[i] - 'a', cnt++;
            } else if (s[i] != s[j]) {
                // fail
                break;
            }
            pre[cnt][msk]++;
            i--, j++;
        }
    }
    vector <int> ans(1 << 17, 0), bit(1 << 17, 0);
    vv <int> pw(18, n + 5, 1);
    for (int i = 1; i < 18; ++i) for (int j = 1; j <= n; ++j)
        pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
    int qc = count(all(s), '?');
    for (int s = 1; s < 1 << 17; ++s)
        bit[s] = bit[s ^ (s & (-s))] + 1, ans[s] = 1ll * pw[bit[s]][qc] * n % mod;
    for (int len = 1; len <= 17; ++len) {
        vector <int> dp(1 << 17, 0);
        for (int d = 0; d < (n + 5 >> 1); ++d) {
            for (auto [x, y] : pre[d]) {
                dp[x] += 1ll * pw[len][qc - d] * y % mod;
                if (dp[x] >= mod)
                    dp[x] -= mod;
            }
        }
        for (int i = 0; i < 17; ++i) {
            for (int s = 0; s < 1 << 17; ++s) if (s >> i & 1) {
                dp[s] += dp[s ^ (1 << i)];
                if (dp[s] >= mod)
                    dp[s] -= mod;
            }
        }
        for (int s = 0; s < 1 << 17; ++s) if (__builtin_popcount(s) == len) {
            ans[s] += dp[s];
            if (ans[s] >= mod)
                ans[s] -= mod;
        }
    }
    while (q--) {
        string s;
        cin >> s;
        int now = 0;
        for (char c : s)
            now |= 1 << c - 'a';
        cout << ans[now] << '\n';
    }
}