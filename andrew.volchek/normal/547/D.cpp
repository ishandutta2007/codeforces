#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <assert.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 4e6 + 5;

int f[maxn], c[maxn], idx[maxn];
vector<pair<int, int>> g[maxn];
int pr[maxn];
int eCnt = 0;

int level[maxn], ptr[maxn];


void bfs(int s, int n, int minFlow) {
    for (int i = 0; i < n; i++) {
        level[i] = -1;
    }

    queue<int> q({s});
    level[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto vto : g[v]) {
            int to = vto.fst;
            int ee = vto.snd;

            if (level[to] != -1) {
                continue;
            }

            if (c[ee] - f[ee] < minFlow) {
                continue;
            }

            level[to] = level[v] + 1;
            q.push(to);
        }
    }
}

int dfs(int v, int flow, int t, int minFlow) {
    if (!flow || v == t) {
        return flow;
    }

    for (; ptr[v] < g[v].size(); ptr[v]++) {
        int to = g[v][ptr[v]].fst;
        int ee = g[v][ptr[v]].snd;

        if (level[to] != level[v] + 1) {
            continue;
        }

        if (c[ee] - f[ee] < minFlow) {
            continue;
        }

        if (int res = dfs(to, min(flow, c[ee] - f[ee]), t, minFlow)) {
            assert(res <= c[ee] - f[ee]);
            f[ee] += res;
            f[ee ^ 1] -= res;
            return res;
        }
    }

    return 0;
}

void dinic(int ns, int nt, int n, int minFlow) {
    while (true) {
        bfs(ns, n, minFlow);

        //cerr << ns << " " << nt << " " << level[ns] << endl;


        if (level[nt] == -1) {
            break;
        }

        for (int i = 0; i < n; i++) {
            ptr[i] = 0;
        }

        while (int res = dfs(ns, 1e9, nt, minFlow)) {
            //cerr << res << endl;
        }
    }
}



void addEdge(int u, int v, int cap, int id) {
    g[u].pb(mp(v, eCnt));
    g[v].pb(mp(u, eCnt + 1));

    c[eCnt] = cap;
    idx[eCnt] = id;

    eCnt += 2;

    assert(eCnt < maxn);
}

const int inf = 1e9;


int main() {
    //freopen("a.in", "r", stdin);
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> p;
    vector<int> xcc, ycc;

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p.pb(mp(x, y));
        xcc.pb(x);
        ycc.pb(y);
    }

    sort(xcc.begin(), xcc.end());
    xcc.resize(unique(xcc.begin(), xcc.end()) - xcc.begin());
    sort(ycc.begin(), ycc.end());
    ycc.resize(unique(ycc.begin(), ycc.end()) - ycc.begin());

    for (auto &f : p) {
        f.fst = lower_bound(xcc.begin(), xcc.end(), f.fst) - xcc.begin();
        f.snd = lower_bound(ycc.begin(), ycc.end(), f.snd) - ycc.begin();
    }

    int s = xcc.size() + ycc.size() + 1;
    int t = s + 1;
    int ns = t + 1;
    int nt = ns + 1;

    for (int i = 0; i < p.size(); i++) {
        addEdge(p[i].fst, xcc.size() + p[i].snd, 1, i + 1);
    }

    addEdge(t, s, inf, 0);

    for (int i = 0; i < xcc.size(); i++) {
        int l = g[i].size() / 2;
        int r = g[i].size() - l;

        addEdge(ns, i, l, 0);
        addEdge(s, nt, l, 0);
        addEdge(s, i, r - l, 0);
    }

    for (int i = 0; i < ycc.size(); i++) {
        int l = g[xcc.size() + i].size() / 2;
        int r = g[xcc.size() + i].size() - l;

        addEdge(ns, t, l, 0);
        addEdge(xcc.size() + i, nt, l, 0);
        addEdge(xcc.size() + i, t, r - l, 0);
    }

    for (int i = 19; i >= 0; i--) {
        dinic(ns, nt, xcc.size() + ycc.size() + 5, 1 << i);
    }

    vector<int> ans(n, 0);

    for (int i = 0; i < maxn; i++) {
        for (auto to : g[i]) {
            if (idx[to.snd]) {
                ans[idx[to.snd] - 1] = f[to.snd];
            }
        }
    }

    for (int i : ans) {
        if (i) {
            printf("b");
        } else {
            printf("r");
        }
    }


    return 0;
}