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
const int mod = 998244353, N = 200001, logN = 20, K = 111, M = 4e7;

lli fac[N], facp[N], inv[N];

lli C(int n, int m) {
    if (n < 0 || m < 0 || n < m)
        return 0;
    return fac[n] * facp[m] % mod * facp[n - m] % mod;
}

int main () {
    owo;
    fac[0] = facp[0] = inv[1] = fac[1] = facp[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        facp[i] = facp[i - 1] * inv[i] % mod;
    }
    int n;
    cin >> n;
    vector <lli> dp(n, 0);
    for (int i = 1; i <= n - 1 >> 1; ++i) {
        dp[i] = C(n - 1 >> 1, i) * fac[n - i - 1] % mod * fac[i] % mod;
    }
    dp[0] = fac[n - 1];
    lli suf = 0;
    for (int i = n - 1; ~i; --i) {
        dp[i] -= suf * inv[i + 1] % mod;
        if (dp[i] < 0)
            dp[i] += mod;
        suf += dp[i];
        if (suf >= mod)
            suf -= mod;
    }
    printv(all(dp));
}