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

const int maxn = 4005;

namespace std {
    template <>
    struct hash<vector<int>> {
        size_t operator() (const vector<int> &x) const {
            size_t res = 1;
            for (int y : x) {
                res = res * 23 + y;
            }
            return res;
        }
    };
}

unordered_map<vector<int>, int> cache;


int get(const vector<int> &v) {
    auto it = cache.find(v);
    if (it == cache.end()) {
        int n = cache.size();
        cache[v] = n;
        return n;
    } else {
        return it->snd;
    }
}

int newId[maxn];
int newIdUsed[maxn];
int newIdVer = 1;

int nn;

int computeHash(vector<pair<int,int>> edges, bool addOne = false) {
    newIdVer++;

    int newIdNum = nn;



    int n = newIdNum + edges.size();

    vector<vector<int>> g(n);

    for (auto e : edges) {
        g[e.fst].pb(newIdNum);
        g[newIdNum].pb(e.fst);

        g[e.snd].pb(newIdNum);
        g[newIdNum].pb(e.snd);

        newIdNum++;
    }

    vector<int> used(n);
    vector<int> vis;
    function<void(int)> flood;
    flood = [&](int v) {
        used[v] = 1;
        vis.pb(v);
        for (int to : g[v]) {
            if (!used[to]) {
                flood(to);
            }
        }
    };

    vector<int> res;

    for (int start = 0; start < n; start++) {

        if (used[start]) {
            continue;
        }

        vis.clear();
        flood(start);

        vector<int> pr(n);

        function<pair<int, int>(int, int)> dfsD;
        dfsD = [&](int v, int p) {
            pr[v] = p;
            pair<int, int> res(0, v);
            for (int to : g[v]) {
                if (to != p) {
                    auto r = dfsD(to, v);
                    r.fst++;
                    chmax(res, r);
                }
            }
            return res;
        };

        int center = -1;

        for (int i : vis) {
            if (g[i].size() <= 1) {
                auto u = dfsD(i, i);
                auto v = dfsD(u.snd, u.snd);
                center = v.snd;
                for (int j = 0; j < v.fst / 2; j++) {
                    center = pr[center];
                }
                break;
            }
        }

        assert(center != -1);

        function<int(int, int)> dfsH;
        dfsH = [&](int v, int p) {
            vector<int> res;
            for (int to : g[v]) {
                if (to != p) {
                    res.pb(dfsH(to, v));
                }
            }
            sort(res.begin(), res.end());
            return get(res);
        };

        res.pb(dfsH(center, center));
    }

    if (addOne) {
        res.pb(get({}));
    }

    sort(res.begin(), res.end());

    return get(res);
}



int main() {
    srand(time(NULL));

    retry:
#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("lock.in", "r", stdin);
    //freopen("lock.out", "w", stdout);
#endif

    int tt;
    scanf("%d", &tt);

    while (tt--) {
        cache.clear();

        int n, k;
        scanf("%d %d", &n, &k);
        nn = n;

        vector<vector<vector<int>>> g(k, vector<vector<int>>(n));
        vector<vector<pair<int,int>>> edges(k);

        for (int i = 0; i < k; i++) {
            int cnt;
            scanf("%d", &cnt);

            for (int j = 0; j < cnt; j++) {
                int u, v;
                scanf("%d %d", &u, &v);
                u--, v--;
                edges[i].pb(mp(u, v));
                g[i][u].pb(v);
                g[i][v].pb(u);
            }
        }

        if (n == 2) {
            if (edges[0].size() == 0 && edges[1].size() == 0) {
                cout << "YES" << endl;
                cout << "1 2" << endl;
            } else {
                cout << "NO" << endl;
            }
            continue;
        }

        set<int> hashesWithOne;
        for (int i = 0; i < k; i++) {
            hashesWithOne.insert(computeHash(edges[i]));
        }

        map<int,vector<int>> hashes;
        for (int i = 0; i < k; i++) {
            hashes[computeHash(edges[i])].pb(i);
        }

        bool found = false;

        for (int i = 0; i < k; i++) {
            vector<int> used(n);
            function<void(int)> dfsC;
            dfsC = [&](int v) {
                used[v] = 1;
                for (int to : g[i][v]) {
                    if (!used[to]) {
                        dfsC(to);
                    }
                }
            };

            int comp = 0;
            for (int j = 0; j < n; j++) {
                if (!used[j]) {
                    comp++;
                    dfsC(j);
                }
            }

            if (comp != 2) {
                continue;
            }

            int absent = -1;
            for (int j = 0; j < n; j++) {
                if (g[i][j].size() == 0) {
                    absent = j;
                }
            }

            if (absent == -1) {
                continue;
            }



            bool was = false;
            for (int j = 0; j < n; j++) {
                if (g[i][j].size() == 0) {
                    continue;
                }

                vector<pair<int,int>> newEdges;
                for (auto e : edges[i]) {
                    if (e.fst != j && e.snd != j) {
                        newEdges.pb(e);
                    }
                }

                int h = computeHash(newEdges);

                if (hashesWithOne.count(h)) {
                    auto oldG = g[i];
                    auto oldE = edges[i];
                    auto oldH = hashes;

                    g[i][absent].pb(j);
                    g[i][j].pb(absent);
                    edges[i].pb(mp(j, absent));

                    bool good = true;
                    vector<int> p(n);

                    for (int j = 0; j < n; j++) {
                        vector<pair<int,int>> newEdges;
                        for (auto e : edges[i]) {
                            if (e.fst != j && e.snd != j) {
                                newEdges.pb(e);
                            }
                        }

                        int res = computeHash(newEdges);
                        if (hashes[res].empty()) {
                            good = false;
                            break;
                        }

                        p[j] = hashes[res].back();
                        hashes[res].pop_back();
                    }

                    if (!good) {
                        g[i] = oldG;
                        edges[i] = oldE;
                        hashes = oldH;
                        continue;
                    }

                    cout << "YES" << endl;
                    for (int j = 0; j < n; j++) {
                        for (int to : g[i][j]) {
                            if (to < j) {
                                cout << p[to] + 1 << " " << p[j] + 1 << endl;
                            }
                        }
                    }

                    found = true;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        if (!found) {
            cout << "NO" << endl;
        }
    }

    return 0;
}