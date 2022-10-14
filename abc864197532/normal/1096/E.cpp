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
const int mod = 998244353, N = 500001;

long long fac[N], facp[N], inv[N];

ll modpow(ll a, int b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

void build() {
    for (int i : {0, 1})
        fac[i] = facp[i] = inv[i] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fac[i] = fac[i - 1] * i % mod;
        facp[i] = facp[i - 1] * inv[i] % mod;
    }
}

long long C(int n, int m) {
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

ll way(int sum, int n) {
    return C(sum + n - 1, n - 1);
}

ll f(int n, int s, int k) {
    if (!n)
        return s == 0;
    // n people, sum = s, 0 <= a_i < k
    ll ans = 0;
    for (int i = 0; i * k <= s && i <= n; ++i) {
        ll val = way(s - i * k, n) * C(n, i) % mod;
        if (i & 1) {
            ans -= val;
            if (ans < 0)
                ans += mod;
        } else {
            ans += val;
            if (ans >= mod)
                ans -= mod;
        }
    }
    return ans;
}

void solve() {
    int n, s, r;
    cin >> n >> s >> r;
    if (!s) {
        cout << inv[n] << '\n';
        return;
    }
    ll ans = 0;
    for (int i = max(r, 1); i <= s; ++i) for (int j = 1; j * i <= s; ++j) {
        ans += f(n - j, s - i * j, i) * inv[j] % mod * C(n - 1, j - 1) % mod;
        if (ans >= mod)
            ans -= mod;
    }
    ans = ans * modpow(way(s - r, n), mod - 2) % mod;
    cout << ans << '\n';
}

int main () {
    owo;
    build();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}