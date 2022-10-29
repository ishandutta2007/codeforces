#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));
pair<int, int> min(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.x <= b.x ? a : b);
}
const int N = 500'001;
int sz[N], d[N];
vector<int> g1[N], g[N], ord;
void dfs(int v, int pr = -1) {
    sz[v] = d[v] = 1;
    ord.push_back(v);
    for (auto to : g1[v])
        if (to != pr) {
            dfs(to, v);
            sz[v] += sz[to];
            uax(d[v], d[to] + 1);
            g[v].push_back(to);
        }
}
vector<pair<int, int>> dp;
int k;
inline void zhfs(int v) {
    dp[v] = {0, 0};
    if (sz[v] < k || d[v] + d[v] - 1 < k) {
        dp[v].y = d[v];
        return;
    }
    int mx1 = 0, mx2 = 0;
    for (auto to : g[v]) {
        dp[v].x += dp[to].x;
        if (dp[to].y > mx1) {
            mx2 = mx1; mx1 = dp[to].y;
        }
        else uax(mx2, dp[to].y);
    }
    if (mx1 + mx2 >= k - 1) dp[v].x++;
    else dp[v].y = mx1 + 1;
}
void solve() {
    for (auto v : ord) zhfs(v);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    forn(i, n - 1) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g1[v].push_back(u);
        g1[u].push_back(v);
    }
    dfs(0);
    reverse(all(ord));
    dp.resize(n);
    vector<int> tmp;
    for (int i = 1; i * i <= n; i++) {
        int l = 1, r = n + 1;
        while(r - l > 1) {
            int m = (l + r) >> 1;
            k = m;
            solve();
            if (dp[0].x >= i) l = m;
            else r = m;
        }
        tmp.push_back(l);
    }
    reverse(all(tmp));
    for (int i = 1; i <= n; i++) {
        if (i * 1ll * i <= n) {
            k = i;
            solve();
            cout << dp[0].x << el;
        }
        else {
            auto j = lower_bound(all(tmp), i) - tmp.begin();
            cout << (int)tmp.size() - j << el;
        }
    }
    return 0;
}