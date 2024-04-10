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
#define ld long double
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


const int maxn = 105;
const int inf = 1e9;

int g[maxn][maxn];
int f[maxn][maxn];
int fw[maxn][maxn][maxn];

int s[maxn], t[maxn];

int distO[maxn], dist[maxn][maxn];


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m, st, fn;
    scanf("%d %d %d %d", &n, &m, &st, &fn);

    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            f[i][j] = i == j ? 0 : inf;
            for (int k = 0; k < maxn; k++) {
                fw[k][i][j] = i == j ? 0 : inf;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u][v] = 1;
        f[u][v] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                chmin(f[j][k], f[j][i] + f[i][k]);
            }
        }
    }

    for (int w = 1; w <= n; w++) {
        for (int i = 1; i <= n; i++) {
            if (i == w) {
                continue;
            }

            for (int j = 1; j <= n; j++) {
                if (j == w) {
                    continue;
                }

                if (g[i][j]) {
                    chmin(fw[w][i][j], 1);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    chmin(fw[w][j][k], fw[w][j][i] + fw[w][i][k]);
                }
            }
        }
    }

    int q;
    scanf("%d", &q);

    for (int i = 1; i <= q; i++) {
        scanf("%d %d", s + i, t + i);

        for (int j = 1; j <= n; j++) {
            dist[i][j] = inf;
        }
    }

    fill(distO, distO + maxn, inf);

    distO[fn] = 0;

    vector<pair<int,int>> order;
    for (int i = 1; i <= n; i++) {
        order.pb(mp(f[i][fn], i));
    }

    sort(order.begin(), order.end());

    for (int i1 = 1; i1 <= q; i1++) {
        bool ch = false;
        for (int i = 1; i <= q; i++) {
            if (f[s[i]][t[i]] == inf) {
                continue;
            }

            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > distO[j] + 1) {
                    ch = true;
                }
                chmin(dist[i][j], distO[j] + 1);
            }

            for (auto jj : order) {
                int j = jj.snd;
                int c = 0;
                bool any = false;
                for (int k = 1; k <= n; k++) {
                    if (g[j][k] && f[s[i]][j] + f[k][t[i]] + 1 == f[s[i]][t[i]]) {
                        chmax(c, dist[i][k]);
                        any = true;
                    }
                }
                if (any) {
                    if (dist[i][j] > c) {
                        ch = true;
                    }
                    chmin(dist[i][j], c);
                }
            }

            for (int j = 1; j <= n; j++) {
                if (f[s[i]][t[i]] != fw[j][s[i]][t[i]]) {
                    if (distO[j] > dist[i][j]) {
                        ch = true;
                    }
                    chmin(distO[j], dist[i][j]);
                }
            }
        }

        if (!ch) {
            break;
        }
    }

    if (distO[st] == inf) {
        cout << -1 << endl;
    } else {
        cout << distO[st] << endl;
    }

    return 0;
}