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

struct pt {
    int x, y;
    pt() {}
    pt(int x, int y): x(x), y(y) {}
};
ll operator %(const pt &a, const pt &b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}
pt operator -(const pt &a, const pt &b) {
    return pt{a.x - b.x, a.y - b.y};
}
vector<int> p, h;
void init(int n) {
    h.assign(n, 0); p.resize(n);
    forn(i, n) p[i] = i;
}
int getp(int a) {
    return a == p[a] ? a : p[a] = getp(p[a]);
}
vector<pair<int, int>> ans;
void unite(int a, int b) {
    a = getp(a), b = getp(b);
    if (h[a] < h[b])
        swap(a, b);
    p[b] = a;
    if (h[a] == h[b])
        h[a]++;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pt> t(n);
    vector<int> a(n);
    forn(i, n) {
        cin >> t[i].x >> t[i].y >> a[i];
        a[i]--;
    }
    vector<int> cl(n, -1);
    init(n);
    vector<int> ord;
    forn(i, n) {
        if (cl[i] != -1 || a[i] == i) continue;
        ord.push_back(i);
        cl[i] = i;
        for (int j = a[i]; j != i; j = a[j]) {
            unite(i, j);
            cl[j] = i;
            ord.push_back(j);
        }
    }
    if (ord.empty()) {
        cout << 0 << el;
        return 0;
    }
    sort(all(ord), [&t](const int &a, const int &b) -> bool { return t[a].x < t[b].x || (t[a].x == t[b].x && t[a].y < t[b].y); });
    int v = ord.back();
    ord.pop_back();
    pt Q(1, 0);
    sort(all(ord), [&t, Q, v](const int &a, const int &b) -> bool {
        if (Q % (t[a] - t[v]) >= 0 && Q % (t[b] - t[v]) < 0) return true;
        if (Q % (t[a] - t[v]) < 0 && Q % (t[b] - t[v]) >= 0) return false;
        return (t[a] - t[v]) % (t[b] - t[v]) > 0;
    });
    int cnt = 0;
    ord.push_back(ord[0]);
    firn(i, ord.size()) {
        int tmp = (t[ord[i - 1]] - t[v]) % (t[ord[i]] - t[v]) < 0;
        cnt += tmp;
        if (!tmp && getp(ord[i - 1]) != getp(ord[i])) {
            ans.emplace_back(ord[i - 1], ord[i]);
            swap(a[ord[i - 1]], a[ord[i]]);
            unite(ord[i - 1], ord[i]);
        }
    }
    assert(cnt < 2);
    while(a[v] != v) {
        ans.emplace_back(v, a[v]);
        swap(a[v], a[a[v]]);
    }
    cout << (int)ans.size() << el;
    for (auto to : ans)
        cout << to.x + 1 << ' ' << to.y + 1 << el;
    return 0;
}