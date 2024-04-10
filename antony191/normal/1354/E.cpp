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
const int inf = 2000'000'000;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 5001;
vector<int> g[N], ord[2][N];
vector<char> used, cl;
int cnt = 0;
bool dfs(int v, int c = 0) {
    used[v] = 1;
    cl[v] = c;
    ord[c][cnt].push_back(v);
    for (auto to : g[v]) {
        if (used[to]) {
            if (cl[to] == cl[v]) return false;
            continue;
        }
        if (!dfs(to, 1 - c)) return false;
    }
    return true;
}
bool d[N][N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int n1, k, n3;
    cin >> n1 >> k >> n3;
    forn(i, m) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    used.assign(n, 0);
    cl.assign(n, 0);
    bool ok = true;
    forn(i, n) {
        if (used[i]) continue;
        if (!dfs(i)) {
            ok = false;
            break;
        }
        cnt++;
    }
    if (!ok) return cout << "NO" << el, 0;
    d[0][0] = true;
    forn(i, cnt) {
        for (int j = (int)ord[0][i].size(); j <= n; j++) d[i + 1][j] |= d[i][j - (int)ord[0][i].size()];
        for (int j = (int)ord[1][i].size(); j <= n; j++) d[i + 1][j] |= d[i][j - (int)ord[1][i].size()];
    }
    if (!d[cnt][k]) cout << "NO" << el;
    else {
        cout << "YES" << el;
        vector<int> c(n), q;
        for (int i = cnt - 1, j = k; i >= 0; i--) {
            if (j >= (int)ord[1][i].size() && d[i][j - (int)ord[1][i].size()]) swap(ord[0][i], ord[1][i]);
            j -= (int)ord[0][i].size();
        }
        forn(i, cnt) {
            for (auto j : ord[0][i]) c[j] = 2;
            for (auto j : ord[1][i]) q.push_back(j);
        }
        forn(i, q.size()) {
            if (i < n1) c[q[i]] = 1;
            else c[q[i]] = 3;
        }
        forn(i, n) cout << c[i];
        cout << el;
    }
    return 0;
}