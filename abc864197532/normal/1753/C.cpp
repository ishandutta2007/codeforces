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
const int mod = 998244353, N = 1 << 20, K = 250;

long long modpow(long long a, int b) {
    long long ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

map <vector <int>, double> m1;

double solve(vector <int> a) {
    if (is_sorted(all(a)))
        return 0;
    if (m1.count(a))
        return m1[a];
    int n = a.size();
    double tot = 1;
    int cnt = 0, all = n * (n - 1) / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) if (a[i] > a[j]) {
            vector <int> b = a;
            swap(b[i], b[j]);
            cnt++, tot += solve(b) / all;
        }
    }
    return m1[a] = (tot) * all / cnt;
}

int inv(vector <int> a) {
    int ans = 0;
    vector <int> b = a;
    sort(all(b));
    for (int i = 0; i < a.size(); ++i)
        ans += a[i] != b[i];
    return ans;
}

void solve() {
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector <int> b = a;
    sort(all(b));
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (a[i] ^ b[i])
        cnt++;
    ll now = (1ll * n * (n - 1) / 2) % mod, ans = 0;
    for (int i = 1; i <= cnt / 2; ++i) {
        ans += now * modpow(1ll * i * i % mod, mod - 2) % mod;
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}