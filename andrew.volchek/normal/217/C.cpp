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

ll add(ll x, ll y) {
    return (x + y) % mod;
}

ll sub(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll mul(ll x, ll y) {
    return (x * y) % mod;
}



enum val {
    Z = 0,
    O = 1,
    VG = 2,

};

vector<val> f_or(val x, val y) {
    if (x == Z) {
        return {y};
    } else if (x == O) {
        return {O};
    } else if (x == VG) {
        if (y == Z) {
            return {x};
        } else if (y == O) {
            return {O};
        } else {
            return {O, VG};
        }
    }
}

vector<val> f_and(val x, val y) {
    if (x == Z) {
        return {Z};
    } else if (x == O) {
        return {y};
    } else if (x == VG) {
        if (y == Z) {
            return {Z};
        } else if (y == O) {
            return {x};
        } else {
            return {Z, VG};
        }
    }
}

vector<val> f_xor(val x, val y) {
    if (x == Z) {
        return {y};
    } else if (x == O) {
        if (y == O) {
            return {Z};
        } else if (y == Z) {
            return {O};
        } else {
            return {y};
        }
    } else if (x == VG) {
        if (y == Z) {
            return {VG};
        } else if (y == O) {
            return {VG};
        } else {
            return {O, Z};
        }
    }
}


const int maxn = 1e6 + 5;
char s[maxn];

enum op {
    OB,
    OR,
    AND,
    XOR,
};

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    vector<vector<val>> v;
    vector<op> u;

    int n;
    scanf("%d\n", &n);
    scanf("%s", s);

    auto doOp = [&](op x) {
        auto a = v.back();
        v.pop_back();
        auto b = v.back();
        v.pop_back();

        vector<val> res;

        for (auto u : a) {
            for (auto v : b) {
                vector<val> r;
                if (x == OR) {
                    r = f_or(u, v);
                } else if (x == AND) {
                    r = f_and(u, v);
                } else if (x == XOR) {
                    r = f_xor(u, v);
                } else {
                    assert(0);
                }

                for (auto h : r) {
                    res.pb(h);
                }
            }
        }

        sort(res.begin(), res.end());
        res.resize(unique(res.begin(), res.end()) - res.begin());

        v.pb(res);
    };

    n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            v.pb({Z});
        } else if (s[i] == '1') {
            v.pb({O});
        } else if (s[i] == '?') {
            v.pb({VG});
        } else if (s[i] == '(') {
            u.pb(OB);
        } else if (s[i] == ')') {
            while (true) {
                op x = u.back();
                u.pop_back();
                if (x == OB) {
                    break;
                }

                doOp(x);
            }
        } else if (s[i] == '&') {
            u.pb(AND);
        } else if (s[i] == '|') {
            u.pb(OR);
        } else if (s[i] == '^') {
            u.pb(XOR);
        }
    }

    while (u.size()) {
        doOp(u.back());
        u.pop_back();
    }

    assert(v.size() == 1);

    bool good = false;
    for (auto x : v[0]) {
        good |= x == VG;
    }

    if (good) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}