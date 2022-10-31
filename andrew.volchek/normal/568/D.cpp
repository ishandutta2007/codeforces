#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

ll gcd(ll a, ll b) {
    return a ? gcd(b % a, a) : b;
}

struct R {
    ll n, d;

    R(ll _n = 0, ll _d = 1) {
        n = _n, d = _d;
        if (d < 0) {
            n = -n, d = -d;
        }
        ll g = gcd(abs(n), abs(d));
        n /= g;
        d /= g;
    }

    bool operator < (const R &o) const {
        return mp(n, d) < mp(o.n, o.d);
    }
};

bool intersect(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2, pair<R, R> &res) {
    ll det = a1 * b2 - a2 * b1;

    if (det == 0) {
        return false;
    }

    R x(c1 * b2 - c2 * b1, -det);
    R y(a1 * c2 - a2 * c1, -det);

    res = mp(x, y);
    return true;
}

const int maxn = 1e5 + 5;

int a[maxn], b[maxn], c[maxn];

bool contains(int id, pair<R, R> p) {
    const ll mods[2] = {1000000007, 1000000009};

    for (ll mod : mods) {
        ll res = p.fst.n * a[id] % mod * p.snd.d % mod;
        res += p.snd.n * b[id] % mod * p.fst.d % mod;
        res += p.fst.d * c[id] % mod * p.snd.d % mod;
        res %= mod;
        if (res != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> alive;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", a + i, b + i, c + i);
        alive.pb(i);
    }

    vector<pair<int,int>> ans;

    while (k && alive.size()) {
        if (alive.size() <= k) {
            for (int x : alive) {
                ans.pb(mp(x + 1, -1));
            }
            alive.clear();
            break;
        }

        map<pair<R, R>, int> cnt;
        map<pair<R, R>, pair<int,int>> repr;

        for (int i = 0; i < maxn; i++) {
            int u = rand() % alive.size();
            int v = rand() % alive.size();

            u = alive[u];
            v = alive[v];

            if (u == v) {
                continue;
            }

            pair<R, R> ip;
            if (intersect(a[u], b[u], c[u], a[v], b[v], c[v], ip)) {
                cnt[ip]++;
                repr[ip] = mp(u + 1, v + 1);
            }
        }

        pair<int, pair<R, R>> m(-1, mp(R(), R()));

        for (auto kv : cnt) {
            m = max(m, mp(kv.snd, kv.fst));
        }

        if (m.fst == -1) {
            printf("NO\n");
            return 0;
        }

        ans.pb(repr[m.snd]);

        vector<int> nalive;

        for (int x : alive) {
            if (!contains(x, m.snd)) {
                nalive.pb(x);
            }
        }

        alive = nalive;
        k--;
    }

    if (alive.size()) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    printf("%d\n", ans.size());
    for (auto x : ans) {
        printf("%d %d\n", x.fst, x.snd);
    }

    return 0;
}