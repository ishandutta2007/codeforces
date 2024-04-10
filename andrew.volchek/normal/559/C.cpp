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

const int maxn = 2e5 + 5;
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

ll fa[maxn], ifa[maxn];

ll C(ll n, ll k) {
    return ((fa[n] * ifa[k]) % mod) * ifa[n - k] % mod;
}

ll ways(int h, int w) {
    return C(h + w - 2, h - 1);
}

ll dp[2005][2];

int main() {
    srand(time(NULL));

    //freopen("a.in", "r", stdin);

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("factory.in", "r", stdin);
    //freopen("factory.out", "w", stdout);
#endif

    fa[0] = ifa[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fa[i] = fa[i - 1] * i % mod;
        ifa[i] = bpow(fa[i], mod - 2);
    }

    int n, h, w;
    cin >> h >> w >> n;

    vector<pair<int,int>> a;

    a.pb(mp(1, 1));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.pb(mp(x, y));
    }

    a.pb(mp(h, w));

    sort(a.begin(), a.end());


    dp[0][0] = 1;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].fst <= a[i].fst && a[j].snd <= a[i].snd) {
                dp[i][0] += dp[j][1] * ways(a[i].fst - a[j].fst + 1, a[i].snd - a[j].snd + 1) % mod;
                dp[i][0] %= mod;
                dp[i][1] += dp[j][0] * ways(a[i].fst - a[j].fst + 1, a[i].snd - a[j].snd + 1) % mod;
                dp[i][1] %= mod;
            }
        }
    }

    cout << (dp[a.size() - 1][1] - dp[a.size() - 1][0] + mod) % mod << endl;

    return 0;
}