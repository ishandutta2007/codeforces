#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
const char el = '\n';
const int inf = 1e9, mod = 998244353;
const ll llinf = 1e18;
const ld pi = 3.1415926;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define pb push_back
#define debug(x) cout << #x << ": " << x << el
#define left left228
#define right right228
#define prev prev228

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true;} return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true;} return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

#define int ll
struct node {
    int l, r, sum;
    node() { sum = 0; }
};
struct Segment_Tree {
    vector<node> t;
    void build(int l, int r, int v = 1) {
        t[v].l = l, t[v].r = r;
        if (l + 1 == r) {
        }
        else {
            int m = (l + r) >> 1;
            build(l, m, v + v);
            build(m, r, v + v + 1);
        }
    }
    Segment_Tree(int n) {
        t.resize(4 * n);
        build(0, n);
    }
    Segment_Tree() {}
    void update(int pos, int d, int v = 1) {
        if (t[v].l + 1 == t[v].r) {
            t[v].sum = d;
        }
        else {
            int m = (t[v].l + t[v].r) >> 1;
            if (pos < m) update(pos, d, v + v);
            else update(pos, d, v + v + 1);
            t[v].sum = (t[v + v].sum + t[v + v + 1].sum) % mod;
        }
    }
    int get(int l, int r, int v = 1) {
        if (l >= r) return 0;
        if (t[v].l == l && t[v].r == r) return t[v].sum;
        int m = (t[v].l + t[v].r) >> 1;
        return get(l, min(m, r), v + v) + get(max(l, m), r, v + v + 1);
    }
};

const int N = 200'002;
Segment_Tree w;
set<int> t;
int p[N], pref[N], obr[N], ans[N], sum[N], sumi[N];
inline void ins(int k) {
    auto j = *t.upper_bound(k);
    ans[k] = 0;
    ans[k] += ((sumi[j] - sumi[k]) - (sum[j] - sum[k]) * 1ll * k) % mod;
    ans[k] = ans[k] * 1ll * obr[k] % mod;
    ans[k] = ans[k] * 1ll * obr[j] % mod * 1ll * pref[k] % mod;
    ans[k] = (ans[k] + (j - k)) % mod;
    ans[k] = (ans[k] % mod + mod) % mod;
    w.update(k, ans[k]);
    t.insert(k);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> r(101);
    r[1] = 1;
    for (int i = 2; i <= 100; ++i)
        r[i] = (mod - (mod / i) * r[mod % i] % mod) % mod;
    pref[0] = obr[0] = 1;
    forn(i, n) {
        cin >> p[i];
        pref[i + 1] = pref[i];
        pref[i + 1] = pref[i + 1] * 1ll * (p[i] * 1ll * r[100] % mod) % mod;
        obr[i + 1] = obr[i];
        obr[i + 1] = obr[i + 1] * 1ll * (100ll * r[p[i]] % mod) % mod;
        sum[i + 1] = (sum[i] + pref[i] * (1 - p[i] * r[100] % mod) % mod) % mod;
        sumi[i + 1] = (sumi[i] + ((pref[i] * (1 - p[i] * r[100] % mod)) % mod * 1ll * (i + 1) % mod)) % mod;
    }
    w = Segment_Tree(n + 1);
    t.insert(0); t.insert(n);
    ins(0);
    forn(i, q) {
        int k;
        cin >> k;
        k--;
        if (t.find(k) == t.end()) {
            ins(k);
            auto j = t.lower_bound(k);
            j--;
            int k1 = *j;
            t.erase(j);
            ins(k1);
        }
        else {
            w.update(k, 0);
            t.erase(k);
            auto j = t.lower_bound(k);
            j--;
            int k1 = *j;
            t.erase(j);
            ins(k1);
        }
        int an = w.t[1].sum;
        an = (an % mod + mod) % mod;
        cout << an << el;
    }
    return 0;
}