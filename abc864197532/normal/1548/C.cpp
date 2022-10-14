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
const int mod = 1e9 + 7, N = 3000005, logN = 20, M = 6e6;

long long fac[N], facp[N], inv[N];

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

void del(int &i, int j) {
    i -= j;
    if (i < 0)
        i += mod;
}

void add(int &i, int j) {
    i += j;
    if (i >= mod)
        i -= mod;
}

int main () {
    owo;
    build();
    int n, q;
    cin >> n >> q;
    vv <int> dp(3 * n + 1, 3, 0);
    // dp[i][j] -> C(j, i) + C(j + 3, i) + ...
    dp[0][0] = dp[0][1] = dp[0][2] = n;
    const int inv3 = (mod + 1) / 3;
    for (int i = 1; i <= 3 * n; ++i) {
        int sum = C(3 * n + 1, i + 1);
        // dp[i][2] = dp[i][1] + dp[i - 1][1];
        // dp[i][0] = dp[i][2] + dp[i - 1][2];
        // dp[i][0] + dp[i][1] + dp[i][2] = sum;
        dp[i][1] = sum;
        del(dp[i][1], dp[i - 1][1]);
        del(dp[i][1], dp[i - 1][1]);
        del(dp[i][1], dp[i - 1][2]);
        dp[i][1] = 1ll * dp[i][1] * inv3 % mod;
        dp[i][2] = dp[i][1], add(dp[i][2], dp[i - 1][1]);
        dp[i][0] = dp[i][2], add(dp[i][0], dp[i - 1][2]);
    }
    while (q--) {
        int x;
        cin >> x;
        cout << dp[x][0] << '\n';
    }
}