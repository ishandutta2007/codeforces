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
#define ld double
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
ostream operator << (ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int color[maxn];

void dfs(int v, int c) {
    color[v] = c;
    for (int to : g[v]) {
        if (color[to] == -1) {
            dfs(to, 1 - c);
        }
    }
}

set<pair<int,int>> a[2];
int deg[maxn];
int alive[maxn];
set<int> gg[maxn];

void del(int v) {
    assert(a[color[v]].count(mp(deg[v], v)));
    a[color[v]].erase(mp(deg[v], v));
    alive[v] = 0;
    for (int to : g[v]) {
        if (!alive[to]) {
            continue;
        }
        assert(a[color[to]].count(mp(deg[to], to)));
        a[color[to]].erase(mp(deg[to], to));
        deg[to]--;
        a[color[to]].insert(mp(deg[to], to));
        gg[to].erase(v);
    }
    assert(!a[color[v]].count(mp(deg[v], v)));
}

vector<int> get(int v) {
    vector<int> res;
    for (auto x : a[1 - color[v]]) {
        if (gg[v].count(x.snd)) {
            continue;
        }
        res.pb(x.snd);
        if (res.size() == 2) {
            return res;
        }
    }
    assert(0);
}

int ans[maxn];

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

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++, deg[v]++;
        gg[u].insert(v);
        gg[v].insert(u);
    }


    auto solve = [&]() {
        fill(deg, deg + maxn, 0);
        for (int i = 1; i <= n; i++) {
            for (int to : g[i]) {
                gg[i].insert(to);
            }
            deg[i] = g[i].size();
        }

        fill(color, color + maxn, -1);
        fill(alive, alive + maxn, 1);


        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                dfs(i, 0);
            }

            for (int to : g[i]) {
                assert(color[to] != color[i]);
            }
        }



        a[0].clear();
        a[1].clear();

        for (int i = 1; i <= n; i++) {
            a[color[i]].insert(mp(deg[i], i));
        }

        int k = n / 3;
        set<int> was;



        while (k && ((a[0].size() % 3 != 0) || (a[1].size() % 3 != 0))) {
            int u = 0, v = 1;
            if (a[u].size() % 3 == 2) {
                swap(u, v);
            }

            if (a[v].size() - a[u].begin()->fst >= 2) {
                auto r = get(a[u].begin()->snd);
                ans[r[0]] = k;
                ans[r[1]] = k;
                assert(!was.count(r[0]));
                assert(!was.count(r[1]));
                assert(!was.count(a[u].begin()->snd));
                assert(r[0] != r[1]);
                assert(r[0] != a[u].begin()->snd);
                assert(r[1] != a[u].begin()->snd);
                assert(1 <= r[0] && r[0] <= n);
                assert(1 <= r[1] && r[1] <= n);
                assert(1 <= a[u].begin()->snd && a[u].begin()->snd <= n);
                ans[a[u].begin()->snd] = k;
                int vv = a[u].begin()->snd;

                del(r[0]);
                del(r[1]);
                del(vv);
                k--;
                assert(a[0].size() % 3 == 0);
                assert(a[1].size() % 3 == 0);
                continue;
            }

            swap(u, v);

            if (a[v].size() - a[u].begin()->fst >= 2) {
                auto r = get(a[u].begin()->snd);
                ans[r[0]] = k;
                ans[r[1]] = k;
                assert(!was.count(r[0]));
                assert(!was.count(r[1]));
                assert(!was.count(a[u].begin()->snd));
                assert(r[0] != r[1]);
                assert(r[0] != a[u].begin()->snd);
                assert(r[1] != a[u].begin()->snd);
                assert(1 <= r[0] && r[0] <= n);
                assert(1 <= r[1] && r[1] <= n);
                assert(1 <= a[u].begin()->snd && a[u].begin()->snd <= n);
                ans[a[u].begin()->snd] = k;
                int vv = a[u].begin()->snd;


                del(r[0]);
                del(r[1]);
                del(vv);
                k--;
                continue;
            }

            return;
        }

        for (int i = 0; i < 2; i++) {
            while (k && a[i].size()) {
                for (int j = 0; j < 3; j++) {
                    assert(!a[i].empty());
                    ans[a[i].begin()->snd] = k;
                    assert(!was.count(a[i].begin()->snd));
                    a[i].erase(a[i].begin());
                }
                k--;
            }
        }

        assert(a[0].empty() && a[1].empty());
        assert(k == 0);

        for (int i = 1; i <= n; i++) {
            for (int to : g[i]) {
                assert(ans[i] != ans[to]);
            }
        }

        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        exit(0);
    };

    for (int i = 0; i < 1; i++) {
        solve();
    }

    cout << "NO" << endl;

    return 0;
}