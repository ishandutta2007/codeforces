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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

const ll mod = 1000000007;

ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}


const int maxn = 1e5 + 5;

int cnt[maxn];
vector<int> f[maxn];

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 1; i < maxn; i++) {
        for (int j = i; j <= maxn; j += i) {
            f[j].pb(i);
        }
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i < maxn; i++) {
        cnt[i] += cnt[i - 1];
    }

    ll ans = 0;

    for (int i = 1; i < maxn; i++) {
        ll c = 1;
        for (int j = 0; j < f[i].size(); j++) {
            int prv = f[i][j] - 1;
            int nxt = j + 1 < f[i].size() ? f[i][j + 1] - 1 : maxn - 1;
            int g = cnt[nxt] - cnt[prv];

            if (j == (int)f[i].size() - 1) {
                c *= (bpow(j + 1, g) + mod - bpow(j, g)) % mod;
                c %= mod;
            } else {
                c *= bpow(j + 1, g);
                c %= mod;
            }
        }
        ans = (ans + c) % mod;
    }

    cout << ans << endl;

    return 0;
}