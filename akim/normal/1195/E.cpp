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
const int maxn = 100100;

int a[3000][3000];

int solution() {

    int n, m, k, l;
    scanf("%d%d%d%d", &n, &m, &k, &l);
    int g, x, y, z;
    scanf("%d%d%d%d", &g, &x, &y, &z);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = g;
            g = (1ll * g * x + y) % z;
        }
    }
    for(int i = 0; i < n; i++) {
        deque<pair<int, int> > d;
        for(int j = 0; j < m; j++) {
            while(!d.empty() && d.back().fs > a[i][j]) d.pop_back();
            d.push_back(mp(a[i][j], j));
            if(j - l + 1 >= 0) {
                a[i][j - l + 1] = d.front().fs;
                if(d.front().sc == j - l + 1) {
                    d.pop_front();
                }
            }
        }
    }

    for(int j = 0; j < m - l + 1; j++) {
        deque<pair<int, int> > d;
        for(int i = 0; i < n; i++) {
            while(!d.empty() && d.back().fs > a[i][j]) d.pop_back();
            d.push_back(mp(a[i][j], i));
            if(i - k + 1 >= 0) {
                a[i - k + 1][j] = d.front().fs;
                if(d.front().sc == i - k + 1) {
                    d.pop_front();
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n - k + 1; i++) {
        for(int j = 0; j < m - l + 1; j++) {
            ans += a[i][j];
        }
    }

    printf("%lld\n", ans);

    return 0;
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
    return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim