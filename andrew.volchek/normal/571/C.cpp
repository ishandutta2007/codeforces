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

const int maxn = 2e5 + 5;

vector<pair<int,int>> l2c[maxn];
vector<pair<int,int>> c[maxn];
int ans[maxn];

vector<pair<int,int>> g[maxn];
int mt[maxn];
int used[maxn];
int currUsed = 1;

bool go(int v) {
    for (auto to : g[v]) {
        if (mt[to.fst] == -1) {
            mt[to.fst] = v;
            ans[v] = !to.snd;
            return true;
        }
    }

    used[v] = currUsed;

    for (auto to : g[v]) {
        if (used[mt[to.fst]] != currUsed && go(mt[to.fst])) {
            mt[to.fst] = v;
            ans[v] = !to.snd;
            return true;
        }
    }

    return false;
}

int main() {
    srand(123);

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

    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            c[i].pb(mp(abs(x), x < 0));
            l2c[abs(x)].pb(mp(i, x < 0));
        }
    }

    fill(ans, ans + maxn, -1);

    for (int i = 1; i <= m; i++) {
        if (l2c[i].empty()) {
            ans[i] = 0;
        } else if (l2c[i].size() == 1) {
            ans[i] = !l2c[i][0].snd;
        } else {
            if (l2c[i][0].snd == l2c[i][1].snd) {
                ans[i] = !l2c[i][0].snd;
            }
        }
    }

    set<int> alive;

    for (int i = 1; i <= n; i++) {
        bool has = false;
        for (auto p : c[i]) {
            if (ans[p.fst] == !p.snd) {
                has = true;
            }
        }

        if (!has) {
            alive.insert(i);
        }
    }

    fill(mt, mt + maxn, -1);

    vector<int> order;

    for (int i = 1; i <= m; i++) {
        if (ans[i] != -1) {
            continue;
        }

        for (auto to : l2c[i]) {
            if (!alive.count(to.fst)) {
                continue;
            }

            g[i].pb(to);
        }

        random_shuffle(g[i].begin(), g[i].end());
        order.pb(i);

        for (auto to : g[i]) {
            if (mt[to.fst] == -1) {
                mt[to.fst] = i;
                ans[i] = !to.snd;
                break;
            }
        }
    }

    random_shuffle(order.begin(), order.end());

    while (true) {
        bool was = false;
        currUsed++;
        for (int i : order) {
            if (ans[i] != -1) {
                continue;
            }

            was |= go(i);
        }
        if (!was) {
            break;
        }
    }


    for (int x : alive) {
        if (mt[x] == -1) {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (ans[i] == -1) {
            ans[i] = 0;
        }
    }

    printf("YES\n");

    for (int i = 1; i <= m; i++) {
        printf("%d", ans[i]);
    }


    return 0;
}