#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <set>
#include <map>
#include <cassert>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ());

int rnd(int x) {
    return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
vector<int> g[maxn];

int read() {
    if (scanf("%d", &n) < 1) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    return true;
}

int dp[maxn];

int dfs(int v, int p) {
    int &res = dp[v];
    res = -2;
    if (sz(g[v]) == 1) {
        res = 0;
    }
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u == p) {
            continue;
        }
        int cur = dfs(u, v);
        if (cur != -1) {
            cur++;
        }
        if (res == -2) {
            res = cur;
        }
        if (res != cur) {
            res = -1;
        }
    }
    return res;
}

int dfs0(int v, int p, int up) {
    int res = inf;
    set<int> st;
    if (up != -2) {
        st.insert(up);
    }
    for (int i = 0; i < sz(g[v]) && sz(st) <= 2; i++) {
        int u = g[v][i];
        if (u == p) {
            continue;
        }
        int val = dp[u];
        if (val != -1) {
            val++;
        }
        st.insert(val);
    }
    if (sz(st) <= 2 && !st.count(-1)) {
        int cur = 0;
        for (auto it = st.begin(); it != st.end(); it++) {
            cur += *it;
        }
        while (!(cur & 1)) {
            cur /= 2;
        }
        res = min(res, cur);
    }
    vector<int> pref(sz(g[v]) + 1), suff(sz(g[v]) + 1);
    pref[0] = -2;
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        int cur = (u == p ? up : (dp[u] == -1 ? dp[u] : dp[u] + 1));
        if (pref[i] == -2) {
            pref[i + 1] = cur;
        } else {
            if (cur == -2) {
                pref[i + 1] = pref[i];
            } else {
                pref[i + 1] = (pref[i] == cur ? pref[i] : -1);
            }
        }
    }
    suff[sz(g[v])] = -2;
    for (int i = sz(g[v]) - 1; i >= 0; i--) {
        int u = g[v][i];
        int cur = (u == p ? up : (dp[u] == -1 ? dp[u] : dp[u] + 1));
        if (suff[i + 1] == -2) {
            suff[i] = cur;
        } else {
            if (cur == -2) {
                suff[i] = suff[i + 1];
            } else {
                suff[i] = (suff[i + 1] == cur ? suff[i + 1] : -1);
            }
        }
    }
    for (int i = 0; i < sz(g[v]); i++) {
        int u = g[v][i];
        if (u == p) {
            continue;
        }
        int nup = pref[i];
        if (nup == -2) {
            nup = suff[i + 1];
        } else {
            if (suff[i + 1] != -2) {
                if (suff[i + 1] != nup) {
                    nup = -1;
                }
            }
        }
        if (nup == -2) {
            nup = 1;
        } else {
            if (nup != -1) {
                nup++;
            }
        }
        res = min(res, dfs0(u, v, nup));
    }
    return res;
}

void solve() {
    dfs(0, -1);
    int res = dfs0(0, -1, -2);
    if (res >= inf) {
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }
}

int main() {
    precalc();
#ifdef LOCAL
    assert(freopen(TASK ".in", "r", stdin));
    assert(freopen(TASK ".out", "w", stdout));
#endif
    while (true) {
        if (!read()) {
            break;
        }
        solve();
#ifdef DEBUG
        eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
    }
    return 0;
}