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

const int maxn = 1e5 + 5;

int dsu[maxn];
int sz[maxn];
vector<pair<int&, int>> historyD, historyS;

void modD(int v, int val) {
    historyD.pb(pair<int&, int>(dsu[v], dsu[v]));
    dsu[v] = val;
}

void modS(int v, int val) {
    historyS.pb(pair<int&, int>(sz[v], sz[v]));
    sz[v] = val;
}

void rollback(int sz) {
    while (historyD.size() > sz) {
        historyD.back().fst = historyD.back().snd;
        historyD.pop_back();
    }

    while (historyS.size() > sz) {
        historyS.back().fst = historyS.back().snd;
        historyS.pop_back();
    }
}

int find(int v) {
    while (v != dsu[v]) {
        v = dsu[v];
    }
    return v;
}

bool unite(int v, int u) {
    v = find(v);
    u = find(u);

    if (u != v) {
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        modD(u, v);
        modS(v, sz[v] + sz[u]);
        return true;
    }
    return false;
}

const int blk = 400;

vector<int> gR[maxn], gL[maxn];

void clear() {
    historyS.clear();
    historyD.clear();
    fill(sz, sz + maxn, 1);
    iota(dsu, dsu + maxn, 0);
}

void gen() {
    int n = 10, k = 5;
    set<pair<int,int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= min(n, i + k); j++) {
            if (rand() & 1) {
                edges.insert(mp(i, j));
            }
        }
    }
    ofstream out("a.in");
    out << n << " " << k << endl;
    out << edges.size() << endl;
    for (auto e : edges) {
        out << e.fst << " " << e.snd << endl;
    }
    int q = 10;
    out << q << endl;
    for (int i = 0; i < q; i++) {
        int l = rand() % n + 1, r = rand() % n + 1;
        if (l > r) {
            swap(l, r);
        }
        out << l << " " << r << endl;
    }
    out.close();
}

int main() {
    srand(time(0));


#ifdef LOCAL
    //gen();
    //return 0;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
#endif

    int n, k;
    scanf("%d %d", &n, &k);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        if (u > v) {
            swap(u, v);
        }
        gR[u].pb(v);
        gL[v].pb(u);
    }

    int q;
    scanf("%d", &q);

    vector<pair<pair<int,int>, int>> qq;
    vector<int> ans(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        qq.pb(mp(mp(l, r), i));
    }

    sort(qq.begin(), qq.end(), [&](const pair<pair<int,int>, int> &u, const pair<pair<int, int>, int> &v) {
        return mp(u.fst.fst / blk, u.fst.snd) < mp(v.fst.fst / blk, v.fst.snd);
    });

    for (int i = 0; i < q; i++) {
        int j = i;
        while (j < qq.size() && qq[i].fst.fst / blk == qq[j].fst.fst / blk) {
            j++;
        }

        int bL = qq[i].fst.fst / blk * blk;
        int bR = min(n - 1, bL + blk - 1);

        clear();

        int cR = bR;
        int unR = 0;

        for (int h = i; h < j; h++) {
            int l = qq[h].fst.fst;
            int r = qq[h].fst.snd;
            int id = qq[h].snd;


            if (bL <= l && r <= bR) {
                int un = 0;
                for (int u = l; u <= r; u++) {
                    for (int to : gL[u]) {
                        if (l <= to && to <= r) {
                            un += unite(to, u);
                        }
                    }
                }

                ans[id] = r - l + 1 - un;
                rollback(0);
            } else {
                while (cR < r) {
                    cR++;
                    for (int to : gL[cR]) {
                        if (bR < to && to <= cR) {
                            unR += unite(cR, to);
                        }
                    }
                }

                int un = 0;
                int ts = historyD.size();

                for (int u = bR; u >= l; u--) {
                    for (int to : gR[u]) {
                        if (u <= to && to <= cR) {
                            un += unite(u, to);
                        }
                    }
                }

               // cout << l << " " << r << " " << un << " " << unR << endl;

                ans[id] = r - l + 1 - unR - un;
                rollback(ts);
            }
        }

        i = j - 1;
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    cerr << (ld)clock() / CLOCKS_PER_SEC << endl;


    return 0;
}

/*
 * 1
0.033047
2
2
2
1
2
2
2
1
2
 */