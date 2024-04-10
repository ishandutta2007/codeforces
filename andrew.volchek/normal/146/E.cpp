#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <assert.h>
#include <fstream>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const ll mod = 1000000007;
const int maxn = 1e5 + 5;

ll add(ll x, ll y) {
    return (x + y) % mod;
}

ll sub(ll x, ll y) {
    return (x + mod - y) % mod;
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll fact[maxn], invFact[maxn];

ll C(ll n, ll k) {
    if (k > n) {
        return 0;
    }

    return mul(fact[n], mul(invFact[k], invFact[n - k]));
}

bool isLucky(int x) {
    while (x) {
        int d = x % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

ll f[maxn], g[maxn], w[maxn];

int main() {
    //gen();
    //freopen("a.in", "r", stdin);

    fact[0] = invFact[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fact[i] = mul(fact[i - 1], i);
        invFact[i] = bpow(fact[i], mod - 2);
    }

    int n, k;
    scanf("%d %d", &n, &k);

    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }

    int right = 0;

    map<int, int> cnt;
    for (auto kv : a) {
        if (isLucky(kv.fst)) {
            cnt[kv.snd]++;
            right++;
        } else {
            cnt[1] += kv.snd;
            right += kv.snd;
        }
    }


    int ub = 0;
    f[0] = 1;

    for (auto kv : cnt) {
        right -= kv.snd;

        ll p = 1;

        for (int i = 0; i <= kv.snd; i++) {
            w[i] = mul(C(kv.snd, i), p);
            p = mul(p, kv.fst);
        }

        for (int j = 0; j < maxn; j++) {
            g[j] = 0;
        }

        int r = k, l = max(0, k - right);

        for (int i = l; i <= r; i++) {
            for (int j = 0; j <= kv.snd; j++) {
                int y = i - j;
                if (y < 0) {
                    break;
                }

                if (y > ub) {
                    continue;
                }

                g[i] = add(g[i], mul(w[j], f[y]));
            }
        }

        ub += kv.snd;

        for (int i = 0; i < maxn; i++) {
            f[i] = g[i];
        }
    }

    cout << f[k] << endl;

    return 0;
}