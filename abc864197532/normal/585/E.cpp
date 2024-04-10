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
const int mod = 1e9 + 7, N = 1 << 19, C = 1e7 + 5;

int dp1[C], dp2[C], cnt[C], pw[N];

void solve() {
    pw[0] = 1;
    for (int i = 1; i < N; ++i)
        pw[i] = pw[i - 1] * 2 % mod;
    int n; cin >> n;
    for (int i = 0, x; i < n; ++i)
        cin >> x, cnt[x]++;
    for (int i = 1; i < C; ++i) for (int j = i + i; j < C; j += i) {
        cnt[i] += cnt[j];
    }
    for (int i = 1; i < C; ++i) if (cnt[i]) {
        dp1[i] = (pw[cnt[i]] - 1 - cnt[i] + mod) % mod;
        dp2[i] = (1ll * cnt[i] * pw[cnt[i] - 1] - cnt[i]) % mod;
    }
    // 1. subset > 1
    // all(x, subset gcd > 1) - all(subset + x gcd > 1)
    // 2. subset = 1
    for (int i = C - 1; i; --i) for (int j = i + i; j < C; j += i) {
        dp1[i] -= dp1[j];
        if (dp1[i] < 0) dp1[i] += mod;
        dp2[i] -= dp2[j];
        if (dp2[i] < 0) dp2[i] += mod;
    }
    ll ans = 0;
    for (int i = 2; i < C; ++i) {
        (ans += 1ll * dp1[i] * n - 2ll * dp2[i]) %= mod;
    }
    ans += 1ll * n * (n - 1);
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}