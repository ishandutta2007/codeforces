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

const ll mod = 1000000007;
const int maxn = 1000005;

ll f[maxn], fi[maxn];

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

ll C(ll n, ll k) {
    return (f[n] * fi[k] % mod) * fi[n - k] % mod;
}

int main() {
    //srand(time(NULL));
    //gen();
    //freopen("a.in", "r", stdin);

    f[0] = fi[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = fi[i - 1] * bpow(i, mod - 2) % mod;
    }

    int n;
    cin >> n;
    vector<int> a;
    ll m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        m += x;
        a.pb(x);
    }

    ll ans = 1;


    for (int i = n - 1; i >= 0; i--) {
        ans = ans * C(m - 1, a[i] - 1) % mod;
        m -= a[i];
    }

    cout << ans << endl;

    return 0;
}