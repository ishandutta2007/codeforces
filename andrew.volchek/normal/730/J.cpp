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


//-----------------------------------------------------------------------------

const int maxn = 2e4 + 7;
const int zero = maxn / 2 + 1;
const int inf = 1e9;
int f[105][maxn];
int nf[105][maxn];

int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    // gen();

    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < 105; i++) {
        for (int j = 0; j < maxn; j++) {
            f[i][j] = inf;
        }
    }

    f[0][zero] = 0;

    vector<pair<int,int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i].fst;
    }
    for (int i = 0; i < n; i++) {
        cin >> g[i].snd;
    }


    for (int it = 0; it < n; it++) {
        int a = g[it].fst, b = g[it].snd;

        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < maxn; j++) {
                nf[i][j] = inf;
            }
        }

        for (int taken = 0; taken < 105; taken++) {
            for (int bal = 0; bal < maxn; bal++) {
                if (f[taken][bal] == inf) {
                    continue;
                }

                if (taken + 1 < 105 && bal - (b - a) >= 0) {
                    chmin(nf[taken + 1][bal - (b - a)], f[taken][bal]);
                }

                if (bal + a < maxn) {
                    chmin(nf[taken][bal + a], f[taken][bal] + a);
                }
            }
        }


        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < maxn; j++) {
                f[i][j] = nf[i][j];
            }
        }
    }

    pair<int, int> ans(1e9, 1e9);
    for (int i = 0; i < 105; i++) {
        for (int j = 0; j <= zero; j++) {
            if (f[i][j] != inf) {
                chmin(ans, mp(i, f[i][j]));
            }
        }
    }

    cout << ans.fst << " " << ans.snd << endl;

    return 0;
}