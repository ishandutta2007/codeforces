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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1001, logN = 20, K = 1500;

lli inv[N];

lli C(int n, int m) {
    if (m == 0)
        return 1;
    lli ans = 1;
    for (int i = 1; i <= m; ++i) {
        ans = ans * (n - i + 1) % mod * inv[i] % mod;
    }
    return ans;
}

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

int main () {
    owo;
    for (int i = 1; i < N; ++i) {
        inv[i] = modpow(i, mod - 2);
    }
    int n;
    cin >> n;
    vector <pii> a(n + 1);
    vector <int> v = {mod};
    for (int i = 1; i <= n; ++i) {
        cin >> a[i], a[i].Y++;
        v.pb(a[i].X), v.pb(a[i].Y);
    }
    sort(all(v)), v.resize(unique(all(v)) - v.begin());
    vv <bool> is(n + 1, v.size(), false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + 1 < v.size(); ++j) {
            if (a[i].X <= v[j] && v[j + 1] <= a[i].Y) {
                is[i][j] = true;
            }
        }
    }
    vv <lli> dp(n + 1, v.size(), 0);
    dp[0][v.size() - 1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j + 1 < v.size(); ++j) if (is[i][j]) {
            for (int k = i - 1; ~k; --k) {
                for (int l = j + 1; l < v.size(); ++l) {
                    (dp[i][j] += dp[k][l] * C(v[j + 1] - v[j] + i - k - 1, i - k)) %= mod;
                }
                if (!is[k][j])
                    break;
            }
        }
    }
    lli ans = 0;
    for (int j = 0; j + 1 < v.size(); ++j) {
        (ans += dp[n][j]) %= mod;
    }
    for (int i = 1; i <= n; ++i) {
        ans = ans * modpow(a[i].Y - a[i].X, mod - 2) % mod;
    }
    cout << ans << endl;
}