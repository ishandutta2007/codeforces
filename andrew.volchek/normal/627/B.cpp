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

const int maxn = 2e5 + 5;

struct tree {
    int tr[maxn * 4];
    int ub;

    tree() {
        fill(tr, tr + maxn * 4, 0);
    }

    void add(int v, int l, int r, int i, int val) {
        if (l == r) {
            tr[v] = min(ub, tr[v] + val);
            return;
        }

        int c = (l + r) >> 1;

        if (i <= c) {
            add(2 * v, l, c, i, val);
        } else {
            add(2 * v + 1, c + 1, r, i, val);
        }

        tr[v] = tr[2 * v] + tr[2 * v + 1];
    }

    int get(int v, int l, int r, int i, int j) {
        if (i <= l && r <= j) {
            return tr[v];
        }

        int c = (l + r) >> 1;
        int res = 0;

        if (i <= c) {
            res += get(2 * v, l, c, i, j);
        }

        if (c < j) {
            res += get(2 * v + 1, c + 1, r, i, j);
        }

        return res;
    }
};

tree trA, trB;

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

    int n, k, a, b, q;
    scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);

    trA.ub = a;
    trB.ub = b;

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int d, x;
            scanf("%d %d", &d, &x);
            trA.add(1, 1, n, d, x);
            trB.add(1, 1, n, d, x);
        } else {
            int p;
            scanf("%d", &p);

            int res = 0;
            if (p > 1) {
                res += trB.get(1, 1, n, 1, p - 1);
            }

            if (p + k <= n) {
                res += trA.get(1, 1, n, p + k, n);
            }

            cout << res << endl;
        }
    }


    return 0;
}