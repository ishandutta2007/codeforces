/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 41, logN = 20, K = 350;

lli g[N];
int gl[N], gr[N];
int between[N];
int vis[N];
bool odd_cycle = false;

void dfs(int v) {
    for (int i = 0; i < N; ++i) if (g[v] >> i & 1) {
        if (!vis[i]) vis[i] = 3 - vis[v], dfs(i);
        else odd_cycle |= vis[i] == vis[v];
    }
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    int half = n / 2;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        g[u] |= 1ll << v;
        g[v] |= 1ll << u;
        if (u < half && v < half) gl[u] |= 1 << v, gl[v] |= 1 << u;
        else if (u >= half && v >= half) gr[u - half] |= 1 << v - half, gr[v - half] |= 1 << u - half;
        else {
            if (u > v) swap(u, v);
            between[v - half] |= 1 << u;
        }
    }
    int cc = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) cc++, vis[i] = 1, dfs(i);
    lli ans = 1;
    // all
    for (int i = 0; i < n; ++i) ans += ans;
    // no 0
    {
        vector <int> dp(1 << half, 0);
        for (int s = 0; s < 1 << half; ++s) {
            bool is = true;
            for (int i = 0; i < half; ++i) if (s >> i & 1 ^ 1) {
                is &= (~s & gl[i]) == 0;
                // avoid 0 1
            }
            if (is) dp[s]++;
        }
        for (int i = 0; i < half; ++i) for (int s = 0; s < 1 << half; ++s) if (s >> i & 1 ^ 1) {
            dp[s] += dp[s ^ (1 << i)];
        }
        for (int s = 0; s < 1 << n - half; ++s) {
            bool is = true;
            for (int i = 0; i < n - half; ++i) if (s >> i & 1 ^ 1) {
                is &= (~s & gr[i]) == 0;
                // avoid 0 1
            }
            if (is) {
                int need = 0;
                for (int i = 0; i < n - half; ++i) if (s >> i & 1 ^ 1) {
                    need |= between[i];
                }
                ans -= dp[need];
            }
        }
    }
    // no 1
    {
        lli res = 1;
        for (int i = 0; i < cc; ++i) res += res;
        ans -= res;
    }
    // no 2
    {
        vector <int> dp(1 << half, 0);
        for (int s = 0; s < 1 << half; ++s) {
            bool is = true;
            for (int i = 0; i < half; ++i) if (s >> i & 1) {
                is &= (s & gl[i]) == 0;
                // avoid 1 1
            }
            if (is) dp[s]++;
        }
        for (int i = 0; i < half; ++i) for (int s = 0; s < 1 << half; ++s) if (s >> i & 1) {
            dp[s] += dp[s ^ (1 << i)];
        }
        for (int s = 0; s < 1 << n - half; ++s) {
            bool is = true;
            for (int i = 0; i < n - half; ++i) if (s >> i & 1) {
                is &= (s & gr[i]) == 0;
                // avoid 1 1
            }
            if (is) {
                int need = 0;
                for (int i = 0; i < n - half; ++i) if (s >> i & 1) {
                    need |= between[i];
                }
                ans -= dp[need ^ ((1 << half) - 1)];
            }
        }
    }
    // no 0 1 || no 1 2
    {
        lli res = 1;
        for (int i = 0; i < n; ++i) if (g[i] == 0) res += res;
        ans += res * 2;
    }
    // no 0 2
    {
        if (!odd_cycle) {
            lli res = 1;
            for (int i = 0; i < cc; ++i) res += res;
            ans += res;
        }
    }
    // no 0 1 2
    if (m == 0) {
        lli res = 1;
        for (int i = 0; i < n; ++i) res += res;
        ans -= res;
    }
    cout << ans << endl;
}