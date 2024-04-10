#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")

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
const int inf = 1000'000'000, mod = 1000000007;//, mod2 = 998244353;
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
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

struct node {
    ll mx = 0;
    ll sum = 0, linsum = 0;
    int d = 0;
    int l = -1, r = -1;
    node() {}
};
struct SegmentTree {
    vector<node> t;
    void build(int l, int r, vector<ll>& a, int v = 1) {
        t[v].l = l, t[v].r = r;
        if (l + 1 == r) {
            t[v].mx = t[v].sum = t[v].linsum = a[l];
        } else {
            int m = (l + r) / 2;
            build(l, m, a, v + v);
            build(m, r, a, v + v + 1);
            t[v].mx = t[v + v + 1].mx;
            t[v].sum = t[v + v].sum + t[v + v + 1].sum;
            t[v].linsum = t[v + v].linsum + t[v + v + 1].linsum + t[v + v].sum * (r - m);
        }
    }
    SegmentTree(int n, vector<ll>& a) {
        t.resize(4 * n);
        build(0, n, a);
    }
    void push(int v) {
        if (t[v].d > 0) {
            int m = (t[v].l + t[v].r) / 2;
            t[v + v].mx += t[v].d;
            t[v + v + 1].mx += t[v].d;
            t[v + v].sum += t[v].d * 1ll * (m - t[v].l);
            t[v + v + 1].sum += t[v].d * 1ll * (t[v].r - m);
            t[v + v].linsum += t[v].d * 1ll * ((m - t[v].l) * 1ll * (m - t[v].l + 1) / 2);
            t[v + v + 1].linsum += t[v].d * 1ll * ((t[v].r - m) * 1ll * (t[v].r - m + 1) / 2);
            t[v + v].d += t[v].d;
            t[v + v + 1].d += t[v].d;
            t[v].d = 0;
        }
    }
    void add(int l, int d, int v = 1) {
        if (l <= t[v].l) {
            t[v].d += d;
            t[v].mx += d;
            t[v].sum += d * (t[v].r - t[v].l);
            t[v].linsum += d * ((t[v].r - t[v].l) * 1ll * (t[v].r - t[v].l + 1) / 2);
            return;
        }
        if (l >= t[v].r) return;
        push(v);
        int m = (t[v].l + t[v].r) / 2;
        if (l < m) add(l, d, v + v);
        add(l, d, v + v + 1);
        t[v].sum = t[v + v].sum + t[v + v + 1].sum;
        t[v].mx = t[v + v + 1].mx;
        t[v].linsum = t[v + v + 1].linsum + t[v + v].linsum + t[v + v].sum * (t[v + v + 1].r - t[v + v].r);
    }
    ll find(ll x, int& pos) {
        int v = 1;
        ll ans = 0;
        while (true) {
            if (t[v].l + 1 == t[v].r) {
                pos = t[v].mx <= x ? t[v].r : t[v].l;
                ans += t[v].mx * (pos == t[v].r);
                break;
            }
            push(v);
            if (t[v + v].mx <= x) {
                ans += t[v + v].sum;
                v = 2 * v + 1;
            } else {
                v = 2 * v;
            }
        }
        return ans;
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    ll sum = 0, lst;
    vector<ll> a(n - 1), b(m - 1);
    cin >> lst;
    sum += lst;
    forn(i, n - 1) {
        cin >> a[i];
        a[i] -= lst;
        lst += a[i];
    }
    cin >> lst;
    sum += lst;
    forn(i, m - 1) {
        cin >> b[i];
        b[i] -= lst;
        lst += b[i];
    }
    SegmentTree tree(m - 1, b);
    while (q--) {
        int type, k, d;
        cin >> type >> k >> d;
        if (type == 1) {
            if (k == n) sum += d;
            for (int i = max(0, n - k - 1); i < n - 1; ++i) a[i] += d;
        } else {
            if (k == m) sum += d;
            tree.add(max(0, m - k - 1), d);
        }
        ll ans = sum * (n + m - 1);
        ans += tree.t[1].linsum;
        forn(i, n - 1) {
            int j;
            ans += tree.find(a[i], j);
            ans += a[i] * (m - j - 1 + (n - 1 - i));
        }
        cout << ans << el;
    }
    return 0;
}