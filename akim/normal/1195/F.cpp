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
const int maxn = 300100;

vector<pair<int, int> > f[maxn];
pair<int, int> g[maxn];
vector<int> p;

vector<pair<int, int> > q[maxn];

map<pair<int, int>, int> ma;
map<int, int> last;
int id = 0;
int ans[maxn];

int t[4 * maxn];

void set_v(int v, int tl, int tr, int pos, int val) {
    if(pos < tl || tr < pos) {
        return;
    }
    if(tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    set_v(v + v + 1, tl, tm, pos, val);
    set_v(v + v + 2, tm + 1, tr, pos, val);
    t[v] = t[v + v + 1] + t[v + v + 2];
    return;
}
int get_s(int v, int tl, int tr, int lf, int rg) {
    if(rg < tl || tr < lf) {
        return 0;
    }
    if(lf <= tl && tr <= rg) {
        return t[v];
    }
    int tm = (tl + tr) >> 1;
    return get_s(v + v + 1, tl, tm, lf, rg) + get_s(v + v + 2, tm + 1, tr, lf, rg);
}

int solution() {

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        g[i].fs = p.size();
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++) {
            f[i].pb(mp(0, 0));
            scanf("%d%d", &f[i][j].fs, &f[i][j].sc);
        }
        f[i].pb(f[i][0]);
        for(int j = 0; j < m; j++) {
            int vx = f[i][j + 1].fs - f[i][j].fs, vy = f[i][j + 1].sc - f[i][j].sc;
            int d = __gcd(abs(vx), abs(vy));
            vx /= d, vy /= d;
            if(!ma.count(mp(vx, vy))) {
                ma[mp(vx, vy)] = id++;
            }
            p.pb(ma[mp(vx, vy)]);
        }
        g[i].sc = p.size() - 1;
    }

    int qq;
    scanf("%d", &qq);
    for(int i = 0; i < qq; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = g[l - 1].fs, r = g[r - 1].sc;
        q[r].pb(mp(l, i));
    }

    n = p.size();
    for(int i = 0; i < n; i++) {
        if(last.count(p[i])) {
            set_v(0, 0, n - 1, last[p[i]], 0);
        }
        set_v(0, 0, n - 1, i, 1);
        last[p[i]] = i;
        for(int j = 0; j < q[i].size(); j++) {
            ans[q[i][j].sc] = get_s(0, 0, n - 1, q[i][j].fs, i);
        }
    }

    for(int i = 0; i < qq; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
    return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim