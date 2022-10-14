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
const int mod = 998244353, N = 14, logN = 18, G = 3;

bool E[N][N];

struct HamPath {
    bool dp[N][N][1 << N];
    int rt[N][N][1 << N];
    int n;
    HamPath (int _n) : n(_n) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (E[i][j]) {
            dp[i][j][0] = true, rt[i][j][0] = -1;
        }
        for (int s = 0; s < 1 << n; ++s) {
            for (int i = 0; i < n; ++i) if (~s >> i & 1) {
                for (int j = 0; j < n; ++j) if (~s >> j & 1) {
                    if (i == j || !dp[i][j][s])
                        continue;
                    for (int k = 0; k < n; ++k) if (~s >> k & 1 && k != i && k != j && E[j][k]) {
                        dp[i][k][s | (1 << j)] = true, rt[i][k][s | (1 << j)] = j;
                    }
                }
            }
        }
    }
    vector <pii> gen_path(int u, int v, int s) {
        assert(dp[u][v][s]);
        vector <pii> ans;
        while (s) {
            int k = rt[u][v][s];
            ans.eb(k, v);
            v = k, s ^= 1 << k;
        }
        ans.eb(u, v);
        return ans;
    }
};

int dp[1 << N];
array <int, 4> rt[1 << N];

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        E[u][v] = E[v][u] = true;
    }
    HamPath HP(n);
    for (int s = 0; s < 1 << n; ++s) 
        dp[s] = 1e9;
    for (int s = 1; s < 1 << n; ++s) {
        if (__builtin_popcount(s) <= 2)
            continue;
        bool ok = false;
        for (int i = 0; i < n; ++i) if (s >> i & 1) {
            for (int j = 0; j < n; ++j) if (s > j & 1) {
                if (i == j)
                    continue;
                if (HP.dp[i][j][s ^ (1 << i) ^ (1 << j)] && E[i][j])
                    dp[s] = 0, rt[s] = {-1, i, j, 0};
            }
        }
    }
    int full = (1 << n) - 1;
    for (int s = 1; s < 1 << n; ++s) if (dp[s] <= n) {
        for (int t = full ^ s; t; t = (t - 1) & (full ^ s)) {
            for (int i = 0; i < n; ++i) if (s >> i & 1) {
                for (int j = 0; j < n; ++j) if (s >> j & 1) {
                    if (i != j && HP.dp[i][j][t]) {
                        if (dp[s ^ t] > dp[s] + 1) {
                            dp[s ^ t] = dp[s] + 1;
                            rt[s ^ t] = {t, i, j, 1};
                        }
                    }
                }
                for (int j = 0; j < n; ++j) if (t >> j & 1 && t != (1 << j)) {
                    if (HP.dp[i][j][t ^ (1 << j)] && E[i][j]) {
                        if (dp[s ^ t] > dp[s] + 1) {
                            dp[s ^ t] = dp[s] + 1;
                            rt[s ^ t] = {t, i, j, -1};
                        }
                    }
                }
            }
        }
    }
    cout << n + dp[full] << '\n';
    vector <pii> ans;
    int now = full;
    while (true) {
        int t = rt[now][0], i = rt[now][1], j = rt[now][2], type = rt[now][3];
        int nxt = t;
        if (t == -1)
            nxt = now ^ (1 << i) ^ (1 << j);
        if (type == -1)
            nxt ^= 1 << j;
        vector <pii> res = HP.gen_path(i, j, nxt);
        for (auto [u, v] : res)
            ans.eb(u, v);
        if (t == -1) {
            ans.eb(i, j);
            break;
        }
        if (type == -1) {
            ans.eb(i, j);
        }
        now ^= t;
    }
    for (auto [u, v] : ans) {
        cout << ++u << ' ' << ++v << '\n';
    }
}