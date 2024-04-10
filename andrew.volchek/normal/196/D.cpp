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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair <U, V> &x) {
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

//-----------------------------------------------------------------------------


const int mc = 1;
const int maxn = 5e5 + 5;
const ll mods[] = {1000000007, 1000000009};
const ll base[] = {47, 73};

ll bpow(ll x, ll n, ll mod) {
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

ll pw[mc][maxn];
ll ipw[mc][maxn];

struct H {
    ll a[mc];

    H() {
        fill(a, a + mc, 0);
    }

    H(char c) {
        for (int i = 0; i < mc; i++) {
            a[i] = c - 'a' + 1;
        }
    }

    H operator+(const H &o) const {
        H res;
        for (int i = 0; i < mc; i++) {
            res.a[i] = (a[i] + o.a[i]);// % mods[i];
            if (res.a[i] >= mods[i]) {
                res.a[i] -= mods[i];
            }
        }
        return res;
    }

    H operator-(const H &o) const {
        H res;
        for (int i = 0; i < mc; i++) {
            res.a[i] = (a[i] - o.a[i] + mods[i]);// % mods[i];
            if (res.a[i] < 0) {
                res.a[i] += mods[i];
            }
        }
        return res;
    }

    H operator-() const {
        return H() - *this;
    }

    H operator<<(const int x) {
        H res;
        for (int i = 0; i < mc; i++) {
            res.a[i] = a[i] * pw[i][x] % mods[i];
        }
        return res;
    }

    H operator>>(const int x) {
        H res;
        for (int i = 0; i < mc; i++) {
            res.a[i] = a[i] * ipw[i][x] % mods[i];
        }
        return res;
    }

    bool operator==(const H &o) const {
        for (int i = 0; i < mc; i++) {
            if (a[i] != o.a[i]) {
                return false;
            }
        }

        return true;
    }
};

struct ft {
    H a[maxn];

    void add(int i, H v) {
        while (i < maxn) {
            a[i] = a[i] + v;
            i |= (i + 1);
        }
    }

    H get(int r) {
        H res;
        while (r >= 0) {
            res = res + a[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }
};

ft tr, trR;

char s[maxn];

void put(int p, char c) {
    tr.add(p, (-H(s[p])) << p);
    tr.add(p, H(c) << p);

    trR.add(maxn - 1 - p, (-H(s[p])) << (maxn - 1 - p));
    trR.add(maxn - 1 - p, H(c) << (maxn - 1 - p));

    s[p] = c;
}

H getH(int l, int r) {
    H res = tr.get(r);
    if (l) {
        res = res - tr.get(l - 1);
    }
    return (res >> l);
}

H getHR(int l, int r) {
    l = maxn - 1 - l, r = maxn - 1 - r;
    swap(l, r);
    H res = trR.get(r);
    if (l) {
        res = res - trR.get(l - 1);
    }
    return (res >> l);
}

bool isPal(int l, int r) {
    auto u = getH(l, r);
    auto v = getHR(l, r);
    return u == v;
}

char t[maxn];

void die() {
    cout << "Impossible" << endl;
    exit(0);
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 0; i < mc; i++) {
        pw[i][0] = ipw[i][0] = 1;
        for (int j = 1; j < maxn; j++) {
            pw[i][j] = pw[i][j - 1] * base[i] % mods[i];
            ipw[i][j] = bpow(pw[i][j], mods[i] - 2, mods[i]);
        }
    }

    int n, d;
    scanf("%d\n", &d);
    //d = 10;

    scanf("%s\n", t);
    n = strlen(t);
    //n = 5e5;
    for (int i = 0; i < n; i++) {
        //t[i] = (rand() % 26) + 'a';
    }

    bool found = false;
    int p;

    int ub = n - 1;

    for (int i = 0; i < n; i++) {
        put(i, t[i]);

        bool bad = false;
        if (i - d + 1 >= 0) {
            bad |= isPal(i - d + 1, i);
        }

        if (i - d >= 0) {
            bad |= isPal(i - d, i);
        }

        if (bad) {
            //found = true;
            ub = i;
            break;
        }
    }


    for (int i = ub; i >= 0; i--) {
        bool was = false;

        for (char c = t[i] + 1; c <= 'z'; c++) {
            put(i, c);

            bool bad = false;
            if (i - d + 1 >= 0) {
                bad |= isPal(i - d + 1, i);
            }

            if (i - d >= 0) {
                bad |= isPal(i - d, i);
            }

            if (!bad) {
                t[i] = c;
                was = true;
                break;
            }
        }

        if (was) {
            found = true;
            p = i + 1;
            break;
        }

        put(i, 0);
    }


    if (!found) {
        die();
    }

    for (int i = p; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            put(i, c);
            t[i] = c;

            bool bad = false;
            if (i - d + 1 >= 0) {
                bad |= isPal(i - d + 1, i);
            }

            if (i - d >= 0) {
                bad |= isPal(i - d, i);
            }

            if (!bad) {
                break;
            }
        }
    }

    printf("%s", t);

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}