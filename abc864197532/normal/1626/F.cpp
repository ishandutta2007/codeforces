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
const int mod = 998244353, N = 18, logN = 20;
const int LCM = 2 * 2 * 2 * 2 * 3 * 3 * 5 * 7 * 11 * 13 * 17;

lli C[N][N], dp[LCM];

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

int modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1)
            ans = ans * a % mod;
    }
    return ans;
}

int main () {
    owo;
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    int n, a0, x, y, k, M;
    cin >> n >> a0 >> x >> y >> k >> M;
    const int mod2 = M;
    vector <lli> a(n);
    lli ans = 0;
    for (int i = 0; i < n; ++i) {
        int res = 0;
        dp[a0 % LCM]++;
        ans += a0 / LCM;
        a0 = (1ll * a0 * x + y) % mod2;
    }
    int inv = modpow(n, mod - 2);
    ans = ans * LCM % mod * inv % mod * k % mod;
    for (int r = 1; r <= k; ++r) {
        for (int i = 0; i < LCM; ++i)
            dp[i] = dp[i] * inv % mod;
        for (int i = 0; i < LCM; ++i) {
            (ans += dp[i] * i) %= mod;
            if (i % r == 0) {
                dp[i] = dp[i] * n % mod;
                for (int k = i + 1; k % r != 0; ++k) {
                    dp[i] += dp[k];
                    if (dp[i] >= mod)
                        dp[i] -= mod;
                }
            } else {
                dp[i] = dp[i] * (n - 1) % mod;
            }
        }
    }
    for (int i = 0; i < k; ++i)
        ans = ans * n % mod;
    cout << ans << endl;
}