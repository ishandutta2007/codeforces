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
int gcd(int a, int b) {
    return a ? gcd(b % a, a) : b;
}

map<int,int> cache;
int phi(int x) {
    if (cache.count(x)) {
        return cache[x];
    }
    int res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)  {
            int c = 1;
            while (x % i == 0) {
                c *= i;
                x /= i;
            }
            res *= c - c / i;
        }
    }
    if (x > 1) {
        res *= x - 1;
    }
    return cache[x] = res;
}

ll bpow(ll x, ll n, ll md) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % md;
        }
        x = x * x % md;
        n >>= 1;
    }
    return res;
}

int mod;

ll transition(ll from, ll to) {
    ll u = from, v = to;
    ll g1 = gcd(from, mod);
    ll g2 = gcd(to, mod);
    from /= g1, to /= g2;
    assert(g2 % g1 == 0);

    ll res = to * bpow(from, phi(mod) - 1, mod) % mod;

    res = res * g2 / g1 % mod;

    assert(u * res % mod == v);

    return res;
}

map<int, set<int>> allowed;

map<int, int> dp;
map<int, int> go;
vector<int> g;


int dfs(int v) {
    if (dp.count(v)) {
        return dp[v];
    }

    pair<int,int> bst(-1, -1);
    for (int x : g) {
        if (x > v && x % v == 0) {
            chmax(bst, mp(dfs(x), x));
        }
    }


    go[v] = bst.snd;

    return dp[v] = allowed[v].size() + bst.fst;
}

int main() {

    srand(0);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("brackets.in", "r", stdin);
    //freopen("brackets.out", "w", stdout);
#endif


    int n;
    cin >> n >> mod;
    for (int i = 1; i < mod; i++) {
        allowed[gcd(i, mod)].insert(i);
    }

    if (n == mod) {
        cout << 0 << endl;
        return 0;
    }


    bool zeroF = false;
    set<int> bad;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bad.insert(x);
        if (x == 0) {
            zeroF = true;
        } else {
            allowed[gcd(x, mod)].erase(x);
        }
    }

    if (mod == 1) {
        if (bad.count(0)) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << 0 << endl;
        }
        return 0;
    }

    if (mod == 2) {
        if (bad.size() == 0) {
            cout << 2 << endl;
            cout << 1 << " " << 0 << endl;
        } else if (bad.count(0) && !bad.count(1)) {
            cout << 1 << endl;
            cout << 1 << endl;
        } else if (!bad.count(0) && bad.count(1)) {
            cout << 1 << endl;
            cout << 0 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }



    for (auto kv : allowed) {
        g.pb(kv.fst);
    }

    pair<int,int> bst(-1, -1);
    for (int v : g) {
        chmax(bst, mp(dfs(v), v));
    }




    vector<int> ans;
    int u = bst.snd;

    ll ff = 1;
    while (u != -1) {

        for (int x : allowed[u]) {
            ans.pb(transition(ff, x));
            ff *= ans.back();
            ff %= mod;
            assert(ff == x);
        }
        u = go[u];
    }

    set<ll> was;
    ll x = 1;



    if (!zeroF) {
        ans.pb(0);
    }

    for (int y : ans) {
        x = x * y % mod;
        assert(!bad.count(x));
        assert(!was.count(x));
        was.insert(x);
    }


    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            printf(" ");
        }
        printf("%d", ans[i]);
    }
    printf("\n");

    cerr << (ld)clock() / CLOCKS_PER_SEC  << endl;

    return 0;
}