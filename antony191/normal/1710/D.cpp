#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <complex>
#include <chrono>
#include <sstream>
#include <fstream>
#include <deque>
#include <cassert>
#include <unordered_map>

#pragma GCC optimize("O3")
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
const int inf = 1000'000'000, mod = 998244353;//, mod2 = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int (i) = 0; i < (int)(n); ++(i))
#define firn(i, n) for (int (i) = 1; i < (int)(n); ++(i))
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
//#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T& a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T& a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd_64(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4001;
vector<int> g[N];
vector<pair<int, int>> h;
int cnt;

void create_tree(const vector<pair<int, int>>& a) {
    int n = a.size();
    if (n == 2) {
        h.emplace_back(a[0].x, a[1].y);
        return;
    }
    if (n & 1) {
        forn(i, n / 2) {
            if (i == 0) {
                h.emplace_back(a[0].x, a[n - 1].y);
                h.emplace_back(a[n - 1].y, a[n / 2].x);
            } else {
                h.emplace_back(a[i].x, a[i + n / 2].y);
            }
            if (i + 1 < n / 2) h.emplace_back(a[i].x, a[i + 1 + n / 2].y);
        }
    } else {
        forn(i, n / 2) {
            h.emplace_back(a[i].x, a[i + n / 2].y);
            if (i + 1 < n / 2) h.emplace_back(a[i].x, a[i + 1 + n / 2].y);
        }
    }
}

struct DSU {
    struct node {
        int l, r, p, num, h = 0;
    };

    vector<node> t;

    DSU(int n) {
        t.resize(n);
        forn(i, n) t[i] = node{i, i, i, i};
    }

    int getp(int a) {
        return a == t[a].p ? a : t[a].p = getp(t[a].p);
    }

    pair<int, int> get_seg(int a) {
        int p = getp(a);
        return {t[p].l, t[p].r};
    }

    void unite(int a, int b) {
        a = getp(a), b = getp(b);
        if (t[a].h < t[b].h) swap(a, b);
        t[b].p = a;
        uin(t[a].l, t[b].l); uax(t[a].r, t[b].r);
        if (t[a].h == t[b].h) ++t[a].h;
    }

    void unite_seg(int l, int r) {
        vector<pair<int, int>> tmp;
        int i = l;
        while (i <= r) {
            int p = getp(i);
            int il = t[p].l, ir = t[p].r;
            tmp.emplace_back(max(il, l), min(ir, r));
            i = ir + 1;
        }
        create_tree(tmp);
        firn(i, tmp.size()) unite(tmp[i - 1].x, tmp[i].x);
    }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        forn(i, n) g[i].clear();
        h.clear();
        cnt = n;
        forn(i, n) {
            string s;
            cin >> s;
            firn(j, n - i) {
                if (s[j] == '1') g[i].push_back(j + i);
            }
        }
        vector<int> r(n, 0);
        DSU dsu(n);
        while (true) {
            bool good = false;
            for (int i = n - 2; i >= 0; --i) {
                if (r[i] == (int)g[i].size()) continue;
                dsu.unite_seg(i, g[i][r[i]]);
                ++r[i];
                good = true;
                break;
            }
            if (!good) break;
        }
        if (dsu.getp(0) != dsu.getp(n - 1)) dsu.unite_seg(0, n - 1);
        forn(i, n - 1) {
            cout << h[i].x + 1 << ' ' << h[i].y + 1 << el;
        }
    }
    return 0;
}