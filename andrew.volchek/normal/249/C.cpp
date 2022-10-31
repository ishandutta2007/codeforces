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

const int maxn = 6e5 + 5;

int cnt[maxn];
vector<pair<int, ld>> a[maxn];

ld c[maxn][10];
ld f[maxn];
int used[maxn];
int currUsed = 1;

int main() {
    srand(time(NULL));

#ifdef LOCAL

    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 0; i < maxn; i++) {
        c[i][0] = 1.0;
        if (i < 10) {
            c[i][i] = 1.0;
        }

        for (int j = 1; j < min(i, 10); j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }

    int n;
    scanf("%d", &n);
    ld ans = 0.0;

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt[i] = x;
        ans += x == 0;
        a[i].pb(mp(0, 1.0));
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);

        if (u == v) {
            currUsed++;
            vector<int> was;
            for (auto &x : a[u]) {
                for (int j = 0; j <= k; j++) {
                    if (j > x.fst) {
                        continue;
                    }

                    ld p = (j <= x.fst ? c[x.fst][j] : 0) / c[cnt[u]][k] *
                           (k - j <= (cnt[u] - x.fst) ? c[cnt[u] - x.fst][k - j] : 0);

                    f[x.fst + k - j] += p * x.snd;
                    if (used[x.fst + k - j] != currUsed) {
                        used[x.fst + k - j] = currUsed;
                        was.pb(x.fst + k - j);
                    }
                }
            }
            for (auto x : a[u]) {
                if (x.fst == cnt[u]) {
                    ans -= x.snd;
                }
            }
            a[u].clear();
            for (int x : was) {
                if (f[x] > 1e-100) {
                    a[u].pb(mp(x, f[x]));
                }
                f[x] = 0;
            }

            assert(a[u].size());

            for (auto x : a[u]) {
                if (x.fst == cnt[u]) {
                    ans += x.snd;
                }
            }
        } else {

            currUsed++;

            cnt[v] += k;
            for (auto &x : a[v]) {
                x.fst += k;
            }

            vector<int> was;

            for (auto &x : a[u]) {
                for (int j = 0; j <= k; j++) {
                    if (x.fst < j) {
                        continue;
                    }

                    ld p = (j <= x.fst ? c[x.fst][j] : 0) / c[cnt[u]][k] *
                           (k - j <= (cnt[u] - x.fst) ? c[cnt[u] - x.fst][k - j] : 0);
                    f[x.fst - j] += x.snd * p;
                    if (used[x.fst - j] != currUsed) {
                        used[x.fst - j] = currUsed;
                        was.pb(x.fst - j);
                    }
                }
            }


            for (auto x : a[u]) {
                if (x.fst == cnt[u]) {
                    ans -= x.snd;
                }
            }

            cnt[u] -= k;

            a[u].clear();
            for (int x : was) {
                if (f[x] > 1e-100) {
                    a[u].pb(mp(x, f[x]));
                }
                f[x] = 0;
            }

            assert(a[u].size());

            for (auto x : a[u]) {
                if (x.fst == cnt[u]) {
                    ans += x.snd;
                }
            }
        }

        printf("%.11lf\n", (double)ans);
    }


    return 0;
}