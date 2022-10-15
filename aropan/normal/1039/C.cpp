#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x " = " << x << endl;
#include "pretty_print.h"
#else
#define dbg(x)
#endif

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }
template <typename T> bool chmin(T &x, const T& y) { if (x > y) { x = y; return true; } return false; }
template <typename T> bool chmax(T &x, const T& y) { if (x < y) { x = y; return true; } return false; }

const int MAXN = 500003;
const int MOD = (int)1e+9 + 7;

ll c[MAXN];
ll pow2[MAXN];

int rnk[MAXN];
int nxt[MAXN];
int cnt;
int upd[MAXN];

unordered_map<ll, vector<pair<int, int>>> mp;


void init(int x) {
    if (upd[x] != cnt) {
        upd[x] = cnt;
        rnk[x] = 1;
        nxt[x] = x;
    }
}

int get(int x) {
    return nxt[x] = (x == nxt[x]? x : get(nxt[x]));
}

bool munion(int u, int v) {
    init(u);
    init(v);
    u = get(u);
    v = get(v);
    if (u == v) {
        return false;
    }

    if (rnk[u] < rnk[v]) {
        swap(u, v);
    }

    nxt[v] = u;
    rnk[u] += rnk[v] == rnk[u];

    return true;
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif

    int n, m, k;
    cnt = 0;
    memset(upd, 0, sizeof(upd));
    while (cin >> n >> m >> k) {
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        pow2[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        mp.clear();
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            ll x = c[u] ^ c[v];
            mp[x].emplace_back(u, v);
        }

        ll xfree = (1LL << k) - (ll)mp.size();
        ll ans = xfree % MOD * pow2[n] % MOD;

        for (auto& it : mp) {
            ++cnt;
            int k = n;
            for (auto& p : it.second) {
                if (munion(p.first, p.second)) {
                    --k;
                }
            }
            ans = (ans + pow2[k]) % MOD;
        }
        cout << ans << endl;
    }


    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}