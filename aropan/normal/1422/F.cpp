#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
#define sz(v) ((int)(v).size())

#define vec1d(x) vector<x>
#define vec2d(x) vector<vec1d(x)>
#define vec3d(x) vector<vec2d(x)>
#define vec4d(x) vector<vec3d(x)>

#define ivec1d(x, n, v) vec1d(x)(n, v)
#define ivec2d(x, n, m, v) vec2d(x)(n, ivec1d(x, m, v))
#define ivec3d(x, n, m, k, v) vec3d(x)(n, ivec2d(x, m, k, v))
#define ivec4d(x, n, m, k, l, v) vec4d(x)(n, ivec3d(x, m, k, l, v))

#ifdef LOCAL
#include "pretty_print.h"
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define nl "\n"

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));


const int MAXX = (int)sqrt(2e+5 + 42);
const int MAXN = 1e+5 + 42;
const int MAXT = 4 * MAXN;
const int MOD = (int)1e+9 + 7;

struct TNode {
    vector<pair<int, int>> low;
    vector<pair<int, int>> high;
    vector<int> prod;
};

vector<TNode> t(MAXT);
map<int, int> lst;
vector<int> a;
vector<int> ps;

vector<int> upd(MAXX, 0);
vector<int> val(MAXX, 0);
vector<int> seq(MAXX, 0);
int cnt = 0;
int ans = 0;

void node_merge(TNode& a, TNode& b, TNode& r) {
    {
        auto fs = a.low.begin();
        auto sc = b.low.begin();
        while (fs != a.low.end() || sc != b.low.end()) {
            if (sc == b.low.end() || (fs != a.low.end() && fs->first < sc->first)) {
                r.low.emplace_back(fs->first, fs->second);
                ++fs;
            } else if (fs == a.low.end() || (sc != b.low.end() && sc->first < fs->first)) {
                r.low.emplace_back(sc->first, sc->second);
                ++sc;
            } else {
                assert(fs != a.low.end());
                assert(sc != b.low.end());
                assert(fs->first == sc->first);
                r.low.emplace_back(fs->first, max(fs->second, sc->second));
                ++fs;
                ++sc;
            }
        }
    }
    merge(all(a.high), all(b.high), back_inserter(r.high));

    int p = 1;
    for (auto& [_, x] : r.high) {
        p = p * (ll)x % MOD;
        r.prod.push_back(p);
    }
}

void build_tree(int idx, int l, int r) {
    if (l + 1 == r) {
        int x = a[l];
        for (auto& p : ps) {
            if (p * p > x) {
                break;
            }
            int c = 0;
            while (x % p == 0) {
                x /= p;
                ++c;
            }
            if (c) {
                t[idx].low.emplace_back(p, c);
            }
        }
        if (x > 1) {
            if (x >= MAXX) {
                auto it = lst.find(x);
                int prv = it == lst.end()? -1 : it->second;
                t[idx].high.emplace_back(prv, x);
                t[idx].prod.emplace_back(x);
                lst[x] = l;
            } else {
                t[idx].low.emplace_back(x, 1);
            }
        }

        return;
    }

    int c = (l + r) / 2;
    int lid = 2 * idx + 0;
    int rid = 2 * idx + 1;
    build_tree(lid, l, c);
    build_tree(rid, c, r);
    node_merge(t[lid], t[rid], t[idx]);
}

void get(int idx, int l, int r, int lq, int rq) {
    if (lq <= l && r <= rq) {
        for (auto& [p, s] : t[idx].low) {
            if (upd[p] != cnt) {
                upd[p] = cnt;
                seq.push_back(p);
                val[p] = 0;
            }
            chmax(val[p], s);
        }

        int pos = lower_bound(all(t[idx].high), make_pair(lq, 0)) - t[idx].high.begin();
        if (pos) {
            ans = ans * (ll)t[idx].prod[pos - 1] % MOD;
        }
        return;
    }

    int c = (l + r) / 2;
    int lid = 2 * idx + 0;
    int rid = 2 * idx + 1;

    if (lq < c) {
        get(lid, l, c, lq, rq);
    }

    if (c < rq) {
        get(rid, c, r, lq, rq);
    }
}

int powmod(int a, int b) {
    ll s = a;
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * s % MOD;
        }
        s = s * s % MOD;
        b >>= 1;
    }
    return ret;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    vector<int> fp(MAXX, 1);
    for (int i = 2; i < MAXX; ++i) {
        if (!fp[i]) {
            continue;
        }
        ps.push_back(i);
        if (i <= MAXX / i) {
            for (int j = i * i; j < MAXX; j += i) {
                fp[j] = false;
            }
        }
    }

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int root = 1;
    build_tree(root, 0, n);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        l = (l + ans) % n;
        r = (r + ans) % n;
        if (l > r) {
            swap(l, r);
        }

        ++cnt;
        seq.clear();

        ans = 1;
        get(root, 0, n, l, r + 1);

        for (auto& x : seq) {
            ans = ans * (ll)powmod(x, val[x]) % MOD;
        }

        cout << ans << nl;
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}