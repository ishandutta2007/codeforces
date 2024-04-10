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

const int maxn = 2e5 + 5;
const ll mod = 1000000007;
map<int, map<int, int>> tr[maxn * 4];




void add(int v, int l, int r, int i, pair<ll, ll> val) {

    ll s = tr[v][val.fst][i] + val.snd;
    if (s >= mod) {
        s -= mod;
    }
    tr[v][val.fst][i] = s;

    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        add(2 * v, l, c, i, val);
    } else {
        add(2 * v + 1, c + 1, r, i, val);
    }
}


void del(int v, int l, int r, int i, pair<ll, ll> val) {
    ll s = tr[v][val.fst][i] - val.snd;
    if (s < 0) {
        s += mod;
    }
    if (s == 0) {
        tr[v][val.fst].erase(i);
        if (tr[v][val.fst].empty()) {
            tr[v].erase(val.fst);
        }
    }

    if (l == r) {
        return;
    }

    int c = (l + r) >> 1;
    if (i <= c) {
        del(2 * v, l, c, i, val);
    } else {
        del(2 * v + 1, c + 1, r, i, val);
    }
}

vector<pair<int, pair<int, int>>> toDel;

int h, w, n;

ll get(int v, int l, int r, int i, int j, int ub) {


    if (i <= l && r <= j) {
        ll res = 0;

        auto it = tr[v].begin();
        while (it != tr[v].end()) {

            if (it->fst > ub) {
                break;
            }

            for (auto x : it->snd) {
                res += x.snd;
                if (res >= mod) {
                    res -= mod;
                }

                toDel.pb(mp(x.fst, mp(it->fst, x.snd)));
            }
            it++;
        }

        for (auto x : toDel) {
            del(1, 1, w, x.fst, x.snd);
        }
        toDel.clear();

        return res;
    }

    ll res = 0;
    int c = (l + r) >> 1;
    if (i <= c) {
        res += get(2 * v, l, c, i, j, ub);
        if (res >= mod) {
            res -= mod;
        }
    }
    if (c < j) {
        res += get(2 * v + 1, c + 1, r, i, j, ub);
        if (res >= mod) {
            res -= mod;
        }
    }

    return res;
}

int main(int argc, char* argv[]) {

    srand(134);

#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //gen();
    //return 0;

#else
    //freopen("identification.in", "r", stdin);
    //freopen("identification.out", "w", stdout);
#endif


    scanf("%d %d %d", &h, &w, &n);
    //h = 1e9, w = 2e5, n = 1e5;

    vector<pair<pair<int,int>, pair<int,int>>> q(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &q[i].fst.fst, &q[i].fst.snd, &q[i].snd.fst, &q[i].snd.snd);
        /*q[i].fst.fst = i + 1;
        q[i].fst.snd = rand() % w + 1;
        q[i].snd.fst = rand() % w + 1;
        if (q[i].fst.snd > q[i].snd.fst) {
            swap(q[i].fst.snd, q[i].snd.fst);
        }
        q[i].snd.snd = 1e9;*/
    }

    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());

    for (int i = 1; i <= w; i++) {
        add(1, 1, w, i, mp(h + 1, 1));
    }


    for (auto x : q) {
        int u = x.fst.fst, l = x.fst.snd, r = x.snd.fst, s = x.snd.snd;

        ll res = get(1, 1, w, l, r, u + s);

        if (res) {
            if (l == 1) {
                add(1, 1, w, r + 1, mp(u, res * 2 % mod));
            } else if (r == w) {
                add(1, 1, w, l - 1, mp(u, res * 2 % mod));
            } else {
                add(1, 1, w, l - 1, mp(u, res));
                add(1, 1, w, r + 1, mp(u, res));
            }
        }
    }

    ll res = get(1, 1, w, 1, w, 2e9);

    cout << res << endl;
    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}