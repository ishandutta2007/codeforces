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
const int mod = 1e9 + 7, N = 1 << 19;

vector <int> build_fail(string &s) {  
    vector <int> f(s.length() + 1, 0);
    int k = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (k && s[k] != s[i]) 
            k = f[k];
        if (s[k] == s[i]) 
            k++;
        f[i + 1] = k;
    }
    return f;
}

void solve() {
    string s, t;
    cin >> s >> t;
    vector <int> f = build_fail(t);
    int n = s.length(), m = t.length();
    vv <int> to(m, 26, 0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i && t[i] - 'a' != j)
                to[i][j] = to[f[i]][j];
            else
                to[i][j] = i;
            if (t[to[i][j]] - 'a' == j)
                to[i][j]++;
        }
    }
    vector <bool> ok(n);
    for (int i = 0; i + m <= n; ++i) if (s.substr(i, m) == t)
        ok[i] = true;
    vv <int> pre(m + 1, n + 1, 0), oth(n + 1, n + 1, 0), dp;
    vv <bool> previs(m + 1, n + 1, false), othvis(n + 1, n + 1, false), vis;
    pre[0][0] = 1, previs[0][0] = true;
    for (int i = 0; i < n; ++i) {
        dp = vv <int>(m + 1, n + 1, 0);
        vis = vv <bool>(m + 1, n + 1, false);
        for (int j = 0; j < m; ++j) for (int k = 0; k <= i; ++k) if (previs[j][k]) {
            if (ok[i]) {
                oth[i + m][k + 1] += pre[j][k];
                othvis[i + m][k + 1] = true;
                if (oth[i + m][k + 1] >= mod)
                    oth[i + m][k + 1] -= mod;
            }
            int nxt = to[j][s[i] - 'a'];
            if (nxt < m) {
                dp[nxt][k] += pre[j][k];
                vis[nxt][k] = true;
                if (dp[nxt][k] >= mod)
                    dp[nxt][k] -= mod;
            }
        }
        for (int j = 0; j <= n; ++j) if (othvis[i + 1][j]) {
            vis[0][j] = true;
            dp[0][j] += oth[i + 1][j];
            if (dp[0][j] >= mod)
                dp[0][j] -= mod;
        }
        pre = dp, previs = vis;
    }
    int mn = 1 << 30;
    for (int j = 0; j < m; ++j) for (int k = 0; k <= n; ++k) if (previs[j][k])
        mn = min(mn, k);
    int ans = 0;
    for (int j = 0; j < m; ++j) {
        ans += pre[j][mn];
        if (ans >= mod)
            ans -= mod;
    }
    cout << mn << ' ' << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}