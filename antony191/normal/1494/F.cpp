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
const int inf = 1000'000'000, mod = 1000'000'007, mod2 = 998'244'353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

//#define forn(i, n) for (int i = 0; i < (int)n; ++i)
//#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
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

const int N = 3001;
vector<pair<int, int>> g[N];
vector<pair<int, int>> r;
vector<int> st;
vector<int> p, sz;
void init(int n) {
    sz.assign(n, 1);
    p.resize(n);
    forn(i, n)
        p[i] = i;
}
int getp(int a) {
    return a == p[a] ? a : p[a] = getp(p[a]);
}
void unite(int a, int b) {
    a = getp(a); b = getp(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}
vector<int> ans;
bool solve(int v, int n) {
    init(n);
    st.assign(n, 0);
    for (auto i : r) {
        if (i.x != v && i.y != v)
            unite(i.x, i.y), st[i.x]++, st[i.y]++;
    }
    int bad = 0;
    forn(i, n)
        bad += st[i] & 1;
    for (auto to : g[v])
        bad -= st[to.x] & 1;
    if (bad >= 2)
        return false;
    vector<int> used(n, 0);
    int cnt = 0;
    forn(i, n)
        if (i == p[i] && sz[i] != 1)
            used[i] = 1, cnt++;
    for (auto to : g[v]) {
        if (!(st[to.x] & 1))
            continue;
        if (used[getp(to.x)])
            cnt--;
        used[getp(to.x)] = 0;
    }
    if (cnt + bad >= 2)
        return false;
    vector<int> gone(r.size(), 0);
    for (auto to : g[v]) {
        if (!(st[to.x] & 1))
            gone[to.y] = 1;
    }
    if (cnt) {
        for (auto to : g[v]) {
            if (used[getp(to.x)]) {
                gone[to.y] = 0;
                cnt--;
                break;
            }
        }
        if (cnt)
            return false;
    }
    vector<int> it(n, 0), stack;
    stack.push_back(v);
    while(!stack.empty()) {
        int u = stack.back();
        while(it[u] < (int)g[u].size() && gone[g[u][it[u]].y])
            it[u]++;
        if (it[u] == (int)g[u].size()) {
            ans.push_back(u);
            stack.pop_back();
            continue;
        }
        stack.push_back(g[u][it[u]].x);
        gone[g[u][it[u]].y] = 1;
        it[u]++;
    }
    ans.push_back(-2);
    for (auto to : g[v]) {
        if (st[to.x] & 1) continue;
        if (used[getp(to.x)]) {
            used[getp(to.x)] = 0;
            continue;
        }
        ans.push_back(to.x);
        ans.push_back(v);
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v].emplace_back(u, (int)r.size());
        g[u].emplace_back(v, (int)r.size());
        r.emplace_back(v, u);
    }
    forn(i, n) {
        if (solve(i, n)) {
            cout << (int)ans.size() << el;
            for (auto t : ans)
                cout << t + 1 << ' ';
            cout << el;
            break;
        }
    }
    if (ans.empty())
        cout << 0 << el;
    return 0;
}