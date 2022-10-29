#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000000001, mod = 1000000007, mod2 = 998244353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

const int N = 300'001;
int n, a[N], pos[N], timer = 0, tin[N], tout[N], st[N], used[N], p[N], h[N];
vector<int> g[N];
void dfs(int v = 0) {
    tin[v] = timer++;
    for (auto to : g[v]) {
        p[to] = v;
        h[to] = h[v] + 1;
        dfs(to);
    }
    tout[v] = timer;
}
bool anc(int v, int u) {
    return tin[v] <= tin[u] && tout[v] >= tout[u];
}
vector<int> ord;
int k = -1;
bool everything_else(int v, int cur) {
    k = cur;
    while(cur < n) {
        if (!used[v]) {
            if (a[v] != cur) return false;
            ord.push_back(v);
            used[v] = 1;
            cur++;
        }
        if (!st[v]) {
            v = p[v];
            st[v]--;
            continue;
        }
        if (p[pos[cur]] != v || used[pos[cur]]) return false;
        v = pos[cur];
    }
    return cur == n;
}
int i = 0;
bool solve() {
    int v = 0;
    while(i < n) {
        if (!used[v]) {
            ord.push_back(v);
            used[v] = 1;
        }
        if (!anc(v, pos[i]) && !anc(pos[i], v))
            return false;
        if (anc(pos[i], v) && (pos[i] != v || st[v]))
            return everything_else(v, (int)ord.size());
        if (!st[v]) {
            assert(anc(pos[i], v));
            v = p[v];
            st[v]--;
            i++;
            continue;
        }
        int l = 0, r = (int)g[v].size();
        while(r - l > 1) {
            int m = (l + r) >> 1;
            if (tin[g[v][m]] > tin[pos[i]])
                r = m;
            else l = m;
        }
        v = g[v][l];
    }
    return i == n;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    forn(i, n) {
        cin >> a[i];
        pos[--a[i]] = i;
    }
    forn(i, n - 1) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        st[v]++;
        g[v].push_back(u);
    }
    dfs();
    if (!solve()) {
        cout << "NO" << el;
        return 0;
    }
    bool ok = true;
    vector<int> num(n);
    forn(i, n) num[ord[i]] = i;
    for (int j = i + 1; j < k; j++) {
        if (!anc(pos[j], ord[j])) {
            ok = false;
            break;
        }
        if (num[p[ord[j]]] > num[ord[j]]) {
            ok = false;
            break;
        }
    }
    if (!ok) cout << "NO" << el;
    else {
        cout << "YES" << el;
        ll ans = 0;
        for (int j = 0; j <= i; j++)
            ans += h[pos[j]];
        cout << ans << el;
        forn(i, n) cout << num[i] + 1 << ' ';
        cout << el;
    }
    return 0;
}