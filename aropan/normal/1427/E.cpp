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


int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    ll n;
    vector<tuple<ll, char, ll>> ans;
    // int delta = 1001;
    // for (ll iter = 0, n = ; iter < 2 * delta; ++iter, n += 2) {
    //     dbg(n);
    while (cin >> n) {
        ans.clear();

        ll limit = 2e+18;

        auto get = [&](ll n, ll d) {
            ll s = n;
            ll cur = 0;
            for (int i = 0; i < 60 && d; ++i) {
                if (d & (1LL << i)) {
                    d ^= (1LL << i);
                    if (cur) {
                        ans.emplace_back(cur, '+', s);
                    }
                    cur += s;
                }
                if (s > limit) {
                    break;
                }
                ans.emplace_back(s, '+', s);
                s += s;
            }
        };

        vector<int> c(1e+6);
        iota(c.begin() + 1, c.end(), 1);
        // for (ll i = 3; i < 1e+6; i += 2) {
            ll t = 0;
            bool ok = false;
            c[0] = n - 1;
            for (auto j : c) {
                ll x = (n * j) ^ n;
                if (gcd(x, n) == 1) {
                    ok = true;
                    t = j;
                    break;
                }
            }
        // }
        //
        assert(ok);
        // dbg(t);

        get(n, t);
        ll m = n * t;
        ans.emplace_back(m, '^', n);
        m ^= n;

        assert(gcd(m, n) == 1);

        ll mt, nt;
        mt = nt = -1;
        for (ll i = 1; i < n; ++i) {
            if (m * i % n == 1) {
                mt = i;
                nt = (m * i - 1) / n;
                break;
            }
        }
        // cout << nt << " " << mt << nl;

        get(n, nt);
        get(m, mt);
        ll a = n * nt;
        ll b = m * mt;

        ll x = a ^ b;
        ans.emplace_back(a, '^', b);
        if (x != 1) {
            ans.emplace_back(x, '+', x);
            ans.emplace_back(x, '^', 2 * x);
            ll y = (2 * x) ^ x;
            ans.emplace_back(x, '+', y);
            ans.emplace_back(y, '+', y);
            ans.emplace_back(2 * y, '^', x + y);
            ll p = (2 * y) ^ (x + y);

            ll d = n / p;
            get(p, d);
            ll v = p * d;
            ans.emplace_back(n, '^', v);
        }


        assert(ans.size() < 1e+5);

        set <ll> st;
        st.insert(n);
        for (auto& [x, op, y] : ans) {
            assert(st.count(x));
            assert(st.count(y));
            ll z;
            if (op == '+') {
                z = x + y;
            } else {
                z = x ^ y;
            }
            assert(z <= limit);
            st.insert(z);
        }

        cout << ans.size() << nl;
        for (auto& [x, op, y] : ans) {
            cout << x << " " << op << " " << y << nl;
        }

        assert(st.count(1));
    }


#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}