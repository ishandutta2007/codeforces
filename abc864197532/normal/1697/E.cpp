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
const int mod = 998244353, N = 101, logN = 18, B = 1 << 8, M = 1 << 21;

long long C[N][N];

void build() {
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= mod)
                C[i][j] -= mod;
        }
    }
}

int main () {
    owo;
    build();
    int n;
    cin >> n;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    auto dis = [&](int i, int j) {
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    };
    vv <bool> g(n, n, false);
    for (int i = 0; i < n; ++i) {
        int mn = 1 << 30;
        for (int j = 0; j < n; ++j) if (i ^ j) {
            mn = min(mn, dis(i, j));
        }
        for (int j = 0; j < n; ++j) if (i ^ j && dis(i, j) == mn) {
            g[i][j] = true;
        }
    }
    vector <int> sz;
    vector <bool> ok(n, false);
    for (int i = 0; i < n; ++i) if (!ok[i]) {
        queue <int> q;
        vector <bool> vis(n, false);
        q.push(i), vis[i] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u = 0; u < n; ++u) if (g[v][u] && !vis[u])
                q.push(u), vis[u] = true;
        }
        set <int> S;
        for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (vis[i] && vis[j])
            S.insert(dis(i, j));
        if (S.size() == 1) {
            sz.pb(accumulate(all(vis), 0));
            for (int i = 0; i < n; ++i) if (vis[i])
                ok[i] = true;
        } else {
            sz.pb(1);
            ok[i] = true;
        }
    }
    vector <int> dp(n + 1, 0), pre;
    dp[0] = 1;
    for (int x : sz) {
        pre.assign(n + 1, 0);
        if (x > 1) {
            for (int i = 0; i < n; ++i)
                (pre[i + 1] += dp[i]) %= mod;
        }
        for (int i = 0; i + x <= n; ++i)
            (pre[i + x] += dp[i]) %= mod;
        dp = pre;
    }
    lli ans = 0, fac = 1;
    for (int i = 1; i <= n; ++i) {
        (ans += dp[i] * C[n][i] % mod * fac) %= mod;
        fac = fac * (i + 1) % mod;
    }
    cout << ans << endl;
}