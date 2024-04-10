#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 998'244'353;
const ll llinf = 1e18;
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

#define int ll

const int N = 400'003;
vector<pair<int, int>> g[N];
const int H = 21;
struct vert {
    int st, cnt;
};
bool operator < (const vert &a, const vert &b) {
    return a.st < b.st || (a.st == b.st && a.cnt < b.cnt);
}
vector<int> d[H];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int v, u;
        cin >> v >> u;
        v--; u--;
        g[v + v].emplace_back(u + u, 0);
        g[v + v + 1].emplace_back(u + u, 1);
        g[u + u].emplace_back(v + v + 1, 1);
        g[u + u + 1].emplace_back(v + v + 1, 0);
    }
    set<pair<vert, int>> q;
    vector<pair<int, int>> d1(n + n, {inf, inf});
    forn(i, H) {
        d[i].assign(n + n, inf);
    }
    d[0][0] = 0;
    q.emplace(vert{0, 0}, 0);
    while(!q.empty()) {
        auto p = *q.begin();
        q.erase(q.begin());
        int v = p.y, t = p.x.st, cnt = p.x.cnt;
        for (auto to : g[v]) {
            if (t + to.y < H) {
                if (cnt + 1 < d[t + to.y][to.x]) {
                    q.erase(pair<vert, int>{vert{t + to.y, d[t + to.y][to.x]}, to.x});
                    d[t + to.y][to.x] = cnt + 1;
                    q.emplace(vert{t + to.y, cnt + 1}, to.x);
                }
            }
            else {
                if (t + to.y < d1[to.x].x || (t + to.y == d1[to.x].x && cnt + 1 < d1[to.x].y)) {
                    q.erase(pair<vert, int>{vert{d1[to.x].x, d1[to.x].y}, to.x});
                    d1[to.x] = {t + to.y, cnt + 1};
                    q.emplace(vert{d1[to.x].x, d1[to.x].y}, to.x);
                }
            }
        }
    }
    int ans = inf;
    forn(i, H) {
        if (d[i][n + n - 1] < inf) uin(ans, (1 << i) + d[i][n + n - 1]);
        if (d[i][n + n - 2] < inf) uin(ans, (1 << i) + d[i][n + n - 2]);
    }
    if (ans < inf) cout << ans - 1 << el;
    else {
        int tmp = min(d1[n + n - 1].x, d1[n + n - 2].x);
        if (d1[n + n - 1].x == d1[n + n - 2].x) ans = min(d1[n + n - 1].y, d1[n + n - 2].y);
        else ans = (d1[n + n - 1].x < d1[n + n - 2].x ? d1[n + n - 1].y : d1[n + n - 2].y);
        ans--;
        int cur = 1;
        forn(j, tmp) cur = cur * 2ll % mod;
        ans = (ans + cur) % mod;
        if (ans < 0) ans += mod;
        cout << ans << el;
    }
    return 0;
}