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

const int maxn = 1e5 + 5;
vector<pair<int,int>> g[maxn];

int n, m;

int dsu[maxn];
int sz[maxn];

int find(int v) {
    if (dsu[v] == v) {
        return v;
    }
    return dsu[v] = find(dsu[v]);
}

void unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (u != v) {
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        dsu[u] = v;
        sz[v] += sz[u];
    }
}


vector<int> solve(int need) {
    iota(dsu, dsu + maxn, 0);
    fill(sz, sz + maxn, 1);

    for (int i = 1; i <= n; i++) {
        for (auto to : g[i]) {
            if (to.snd == need) {
                unite(i, to.fst);
            }
        }
    }

    map<int, int> was;
    map<int, int> wasInv;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            int f = was.size();
            was[i] = f;
            wasInv[f] = i;
        }
    }

    vector<vector<int>> mn(was.size());
    for (int i = 1; i <= n; i++) {
        mn[was[find(i)]].pb(i);
    }

    vector<vector<int>> gg(was.size());
    for (int i = 1; i <= n; i++) {
        for (auto to : g[i]) {
            if (to.snd != need) {
                int u = find(i), v = find(to.fst);
                gg[was[u]].pb(was[v]);
                gg[was[v]].pb(was[u]);
            }
        }
    }


    vector<int> color(was.size(), -1);
    vector<int> ans;

    for (int i = 0; i < was.size(); i++) {
        if (color[i] == -1) {
            function<void(int, int)> dfs;
            int cnt[2] = { 0, 0 };
            vector<int> vis;
            bool bad = false;
            dfs = [&](int v, int c) {
                color[v] = c;
                vis.pb(v);
                cnt[color[v]] += sz[wasInv[v]];
                for (int to : gg[v]) {
                    if (color[to] == -1) {
                        dfs(to, c ^ 1);
                    } else if (color[to] != (c ^ 1)) {
                        bad = true;
                    }
                }
            };

            dfs(i, 0);

            if (bad) {
                return {-1};
            }

            int d = cnt[0] < cnt[1] ? 0 : 1;

            for (int x : vis) {
                if (color[x] == d) {
                    for (int y : mn[x]) {
                        ans.pb(y);
                    }
                }
            }
        }
    }


    return ans;
}

int main() {

#ifdef LOCAL
    freopen("a.in", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        g[u].pb(mp(v, c == 'R'));
        g[v].pb(mp(u, c == 'R'));
    }

    auto res = solve(0);
    auto res2 = solve(1);

    if (res.empty() || res2.empty()) {
        cout << 0 << endl;
        return 0;
    }

    auto print = [&](vector<int> res) {
        if (res[0] == -1) {
            cout << -1 << endl;
        } else {
            cout << res.size() << endl;
            for (int x : res) {
                cout << x << " ";
            }
            cout << endl;
        }
    };


    if (res[0] != -1 && res2[0] != -1) {
        if (res.size() > res2.size()) {
            swap(res, res2);
        }
        print(res);
    } else if (res[0] != -1) {
        print(res);
    } else {
        print(res2);
    }

    return 0;
}