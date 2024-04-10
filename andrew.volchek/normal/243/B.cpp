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

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int a[maxn];
int used[maxn];
int currUsed = 1;

int main() {
    //srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    int n, m, H, T;
    scanf("%d %d %d %d", &n, &m, &H, &T);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int u = 1; u <= n; u++) {
        for (int x : g[u]) {
            a[x] |= 1;
        }

        for (int v : g[u]) {

            vector<int> c[3];

            int cnt = 0;
            int cnt2 = 0;
            vector<int> was;

            int iter = 0;

            for (int x : g[v]) {
                iter++;
                if (x == u) {
                    continue;
                }

                if (a[x] == 1) {
                    cnt++;
                } else {
                    cnt2++;
                }

                a[x] |= 2;
                was.pb(x);

                if (cnt > 200 || cnt2 > 100) {
                    break;
                }
            }

            currUsed++;
            assert(iter < 400);
            iter = 0;

            for (int x : g[u]) {
                iter++;
                if (x == v) {
                    continue;
                }

                if (a[x] == 1) {
                    c[0].pb(x);
                } else {
                    used[x] = currUsed;
                    c[2].pb(x);
                }

                if (c[2].size() > H + T - c[0].size() - c[1].size() || c[0].size() > max(H, T)) {
                    break;
                }
            }

            assert(iter < 400);
            iter = 0;

            int hh = 0;
            for (int x : g[v]) {
                iter++;
                if (x == u) {
                    continue;
                }

                if (a[x] == 2) {
                    c[1].pb(x);
                } else {
                    if (used[x] != currUsed) {
                        c[2].pb(x);
                    } else {
                        //hh++;
                    }
                }

                if (c[2].size() > H + T - c[0].size() - c[1].size() || c[1].size() > max(H, T)) {
                    break;
                }
            }
            assert(iter < 400);



            if (max(0, H - (int)c[1].size()) + max(0, T - (int)c[0].size()) <= c[2].size()) {
                swap(c[0], c[1]);
                swap(u, v);
            }

            if (max(0, H - (int)c[0].size()) + max(0, T - (int)c[1].size()) <= c[2].size()) {


                while (!c[2].empty() && c[0].size() < H) {
                    c[0].pb(c[2].back());
                    c[2].pop_back();
                }

                while (!c[2].empty() && c[1].size() < T) {
                    c[1].pb(c[2].back());
                    c[2].pop_back();
                }

                if (c[0].size() >= H && c[1].size() >= T) {
                    printf("YES\n");
                    printf("%d %d\n", u, v);
                    c[0].resize(H);
                    for (int x : c[0]) {
                        printf("%d ", x);
                    }
                    printf("\n");

                    c[1].resize(T);
                    for (int x : c[1]) {
                        printf("%d ", x);
                    }
                    printf("\n");

                    return 0;
                }
            }

            {
                for (int x : was) {
                    if (a[x] & 2) {
                        a[x] ^= 2;
                    }
                }
            }
        }



        for (int x : g[u]) {
            a[x] = 0;
        }
    }

    printf("NO\n");

    return 0;
}