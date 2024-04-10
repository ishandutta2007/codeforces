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
const int inf = 1000'000'000, mod = 1000'000'007;
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

struct node {
    int l, r, c;
    int min, cnt;
    node() {min = cnt = c = 0;}
};
struct Segment_Tree {
    vector<node> t;
    void build(int l, int r, int v = 1) {
        t[v].l = l, t[v].r = r;
        t[v].cnt = r - l;
        if (l + 1 < r) {
            int m = (l + r) >> 1;
            build(l, m, v + v);
            build(m, r, v + v + 1);
        }
    }
    Segment_Tree(int n) {
        t.resize(4 * n);
        build(0, n);
    }
    inline void push(int v) {
        t[v + v].min += t[v].c;
        t[v + v + 1].min += t[v].c;
        t[v + v].c += t[v].c;
        t[v + v + 1].c += t[v].c;
        t[v].c = 0;
    }
    void add(int l, int r, int d, int v = 1) {
        if (r <= t[v].l || t[v].r <= l) return;
        if (t[v].l >= l && t[v].r <= r) {
            t[v].min += d;
            t[v].c += d;
            return;
        }
        push(v);
        add(l, r, d, v + v); add(l, r, d, v + v + 1);
        t[v].min = min(t[v + v].min, t[v + v + 1].min);
        t[v].cnt = (t[v + v].min == t[v].min ? t[v + v].cnt : 0) + (t[v + v + 1].min == t[v].min ? t[v + v + 1].cnt : 0);
    }
    int get(int l, int r, int v = 1) {
        if (r <= t[v].l || t[v].r <= l) return 0;
        if (t[v].l >= l && t[v].r <= r) return t[v].min == 0 ? t[v].cnt : 0;
        push(v);
        return get(l, r, v + v) + get(l, r, v + v + 1);
    }
};
const int N = 500'001;
vector<int> g[N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    forn(i, n) {
        cin >> a[i];
        a[i]--;
        p[i] = (int)g[a[i]].size();
        g[a[i]].push_back(i);
    }
    multiset<int> q;
    Segment_Tree T(n);
    ll ans = 0;
    forn(i, n) {
        if (p[i] < 2) {
            q.insert(i);
            if (p[i] > 0) q.erase(q.find(g[a[i]][p[i] - 1]));
            continue;
        }
        T.add(g[a[i]][p[i] - 2] + 1, i + 1, 1);
        if (p[i] == 2) q.erase(q.find(g[a[i]][p[i] - 1]));
        else q.insert(g[a[i]][p[i] - 3]), T.add(g[a[i]][p[i] - 3] + 1, g[a[i]][p[i] - 1] + 1, -1);
        int l = (q.empty() ? 0 : *q.rbegin() + 1);
        if (l >= i) continue;
        ans += T.get(l, i);
    }
    cout << ans << el;
    return 0;
}