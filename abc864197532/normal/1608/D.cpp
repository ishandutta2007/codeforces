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
const int mod = 998244353, N = 100005, logC = 30, K = 450;

lli fac[N], facp[N];

lli C(int n, int m) {
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    map <string, int> m1;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        m1[s]++;
    }
    lli ans = 0;
    if (m1["WB"] + m1["W?"] + m1["?B"] + m1["??"] == n) {
        ans++;
    }
    if (m1["BW"] + m1["?W"] + m1["B?"] + m1["??"] == n) {
        ans++;
    }
    // +1 -> BB, -1 -> WW
    vector <int> cnt(3, 0); // 0 -> +1 or -1 or 0(2), 1 -> +1 or 0, 2 -> -1 or 0
    cnt[0] = m1["??"];
    cnt[1] = m1["B?"] + m1["?B"];
    cnt[2] = m1["?W"] + m1["W?"];
    int res = m1["BB"] - m1["WW"];
    int a = cnt[0] + cnt[1], b = cnt[0] + cnt[2];
    for (int i = 0; i <= a; ++i) {
        if (0 <= res + i && res + i <= b)
            (ans += C(a, i) * C(b, res + i)) %= mod;
    }
    if (!m1["BB"] && !m1["WW"])
        (ans += mod - modpow(2, cnt[0])) %= mod;
    cout << ans << endl;
}

int main () {
    owo;
    fac[0] = facp[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = facp[i - 1] * modpow(i, mod - 2) % mod;
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}