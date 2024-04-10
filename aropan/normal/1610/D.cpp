#include <bits/stdc++.h>

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

const int MOD = 1e+9 + 7;
const int MAXN = 2e+5 + 7;

vector<ll> fact(MAXN);
vector<ll> invf(MAXN);
vector<ll> pow2(MAXN);

ll powmod(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    ll ret = powmod(a, b >> 1);
    (ret *= ret) %= MOD;
    return b & 1? ret * a % MOD : ret;
}

ll divmod(ll a, ll b) {
    return a * powmod(b, MOD - 2) % MOD;
}

ll C(int n, int m) {
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}


int main(int /* argc */, const char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    assert(freopen("i.txt", "r", stdin));
    assert(freopen("o.txt", "w", stdout));
#endif

    fact[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i){
        fact[i] = fact[i - 1] * i % MOD;
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    invf[MAXN - 1] = divmod(1, fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; --i) {
        invf[i] = invf[i + 1] * (i + 1) % MOD;
        assert(invf[i] == divmod(1, fact[i]));
    }


    int n;
    while (cin >> n && n) {
        int m = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            if (x % 2 == 1) {
                m += 1;
                continue;
            }
        }
        ll ans = (pow2[n] - pow2[n - m] + MOD) % MOD;
        for (ll b = 2; ; b *= 2) {
            int n1 = 0;
            int n2 = 0;
            for (auto& x : a) {
                if (x % b) {
                    continue;
                }
                ((x / b) & 1? n1 : n2) += 1;
            }
            if (n1 > 1) {
                ans += (pow2[n1 - 1] + MOD - 1) % MOD * pow2[n2] % MOD;
                ans %= MOD;
            }
            if (n2 == 0) {
                break;
            }

        }
        cout << ans << nl;
    }

#ifdef LOCAL
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}