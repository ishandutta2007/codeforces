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

const ld pi = acos(-1.0l);

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


//-----------------------------------------------------------------------------


const int maxn = 1e6 + 5;
const ll mod = 1000000007;


//vector<int> cnt[maxn];
ll overall[maxn];
ll sum[maxn];
vector<int> fact[maxn];
ll g[maxn];

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

ll f[maxn], fi[maxn];

ll C(ll n, ll k) {
    if (n < k) {
        return 0;
    }
    return f[n] * fi[k] % mod * fi[n - k] % mod;
}

int k;
ll ans;

void add(int x) {

    for (int y : fact[x]) {

        ans -= sum[y] * g[y] % mod;

        int d = x / y;

        sum[y] -= C(overall[y], k);
        overall[y]++;
        sum[y] += C(overall[y], k);


        /*if (d > 1) {
            sum[y] += C(cnt[y][d], k);
        }

        cnt[y][d]++;

        if (d > 1) {
            sum[y] -= C(cnt[y][d], k);
        }

        sum[y] = (sum[y] % mod);
        if (sum[y] < 0) {
            sum[y] += mod;
        }

        cout << y << " " << sum[y] << " " << g[y] << endl;
        */

        ans += sum[y] * g[y] % mod;

        ans %= mod;
        ans += mod;
        ans %= mod;
    }
}


int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    f[0] = fi[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1] * i % mod;
        fi[i] = bpow(f[i], mod - 2);
    }


    for (int i = 1; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            fact[j].pb(i);
        }
    }


    g[1] = 1;
    for (int i = 2; i < maxn; i++) {
        g[i] = i;
        for (int x : fact[i]) {
            if (x != i) {
                g[i] -= g[x];
            }
        }
        //cout << g[i] << endl;
    }


    for (int i = 1; i < maxn; i++) {
        //cnt[i].resize(maxn / i + 2);
    }


    int n, q;
    scanf("%d %d %d", &n, &k, &q);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        add(x);
    }

    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        add(x);
        printf("%d\n", (int)ans);
    }




    return 0;
}