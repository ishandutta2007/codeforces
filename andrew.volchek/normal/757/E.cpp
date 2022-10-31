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
#include <limits>
#include <tuple>
#include <complex>
#include <numeric>
#include <future>

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

const ld pi = acos(-1.0);

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
bool chmin(T &x, T y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

template<typename T>
bool chmax(T &x, T y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//--------------------------------------------------------------------------
const ll mod = 1000000007;
map<pair<int,int>, int> dp;
ll foo(int n, int r) {
    if (dp.count(mp(n, r))) {
        return dp[mp(n, r)];
    }
    if (r == 0) {
        int ans = 1;
        int _n = n;
        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                ans *= 2;
                ans %= mod;
                while (n % i == 0) {
                    n /= i;
                }
            }
        }
        return dp[mp(_n, r)] = ans;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans += (foo(i, r - 1) + foo(n / i, r - 1));
            //ans %= mod;
        }
    }
    ans /= 2;

    return dp[mp(n, r)] = ans;
}

const int maxn = 1e6 + 12345;
int p[maxn];



ll f[maxn], fi[maxn];

ll C(ll n, ll k) {
    if (n < k) {
        return 0;
    }
    return f[n] * fi[k] % mod * fi[n - k] % mod;
}



ll bpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}




ll solve2(ll n, ll r) {

    if (r == 0) {
        ll ans = 1;
        while (n > 1) {
            ans *= 2;
            int z = p[n];
            while (n % z == 0) {
                n /= z;
            }
        }
        return ans % mod;
    }
    ll ans = 1;
    while (n > 1) {
        int z = p[n];
        int c = 1;
        while (n % z == 0) {
            n /= z;
            c++;
        }

        ll mul = 2;
        for (int i = 0; i + 1 < c; i++) {
            int k = c - i - 1;
            mul += (1LL << (i > 0)) * C(r + k - 1, k) % mod;
        }
        mul %= mod;
        ans = ans * mul % mod;
    }
    return ans;
}


int main() {
    srand(time(NULL));


#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif
    iota(p, p + maxn, 0);
    for (int i = 2; i < maxn; i++) {
        if (p[i] == i) {
            for (int j = i + i; j < maxn; j += i) {
                p[j] = i;
            }
        }
    }


    f[0] = 1;
    fi[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = bpow(f[i], mod - 2);
    }


    int q;
    scanf("%d\n", &q);
    while (q--) {
        int n, k;
        scanf("%d %d", &k, &n);
        printf("%d\n", (int)solve2(n, k));
    }


    return 0;
}