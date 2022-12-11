#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map = tree<T1, T2, std::less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

using namespace std;


#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
    starttime = 1000. * clock() / CLOCKS_PER_SEC;
    if (useinout().fs.fs)
        freopen("input.txt", "r", stdin);
    if (useinout().fs.sc)
        freopen("output.txt", "w", stdout);
#else
    srand(__rdtsc());
    const string file = useinout().sc.fs;
    if (!file.empty()) {
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);
    } else
    if(useinout().sc.sc) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
#endif
}

int solution();

void finish(int exitval) {
    fflush(stdout);
#ifdef SOL
    fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
#endif
}

int main() {
    initialization();
    finish(solution());
    return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

int qd(int u) {
    printf("d %d\n", u + 1);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r;
}

int qs(int u) {
    printf("s %d\n", u + 1);
    fflush(stdout);
    int r;
    scanf("%d", &r);
    return r - 1;
}

vector<int> g[maxn], lev[maxn];
int tin[maxn], tout[maxn], tt = 0;

void dfs(int u, int p = -1, int d = 0) {
    tin[u] = tt++;
    lev[d].pb(u);
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u, d + 1);
    }
    tout[u] = tt++;
}

int find_v(vector<int> &v, int val) {
    int l = -1, r = ((int)v.size()) - 1;
    while(l + 1 < r) {
        int m = (l + r) >> 1;
        if(tout[v[m]] > val) {
            r = m;
        } else {
            l = m;
        }
    }
    return v[r];
}

int solution() {

    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);

    int cur = 0;
    int dep = qd(0);
    int l = 0, r = ((int)lev[dep].size()) - 1;
    while(l < r) {
        int q = lev[dep][l + rand() % (r - l + 1)];
        int di = qd(q) / 2;
        if(di == 0) {
            printf("! %d\n", q + 1);
            return 0;
        }
        q = find_v(lev[dep - di], tout[q]);
        cur = qs(q);
        while(tin[lev[dep][l]] < tin[cur]) l++;
        while(tout[lev[dep][r]] > tout[cur]) r--;
    }
    printf("! %d\n", lev[dep][l] + 1);

    return 0;
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
    return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim