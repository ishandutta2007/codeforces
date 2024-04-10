#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char a[1111][11][11];

int cd(int k1, int k2) {
    int res = 0;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (a[k1][i][j] != a[k2][i][j]) {
                res++;
            }
        }
    }
    return res;
}

pair<int, pair<int, int> > es[1111111];

int dsu[1111];

int get(int x) {
    return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
}

void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (rand() & 1) {
        dsu[x] = y;
    } else {
        dsu[y] = x;
    }
}

vector<int> g[1111];
bool used[1111];

void dfs(int v, int p) {
    used[v] = true;
    printf("%d %d\n", v + 1, p + 1);
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v);
        }
    }
}

int main() {
    srand(31);
    sciiid(n, m, k);
    scid(w);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("\n%s", a[i][j]);
        }
    }
    int ce = 0;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int d = cd(i, j) * w;
            if (d < n * m) {
                es[ce++] = {d, {i, j}};
            }
        }
    }
    sort(es, es + ce);
    for (int i = 0; i < k; i++) {
        dsu[i] = i;
    }

    int ans = n * m * k;

    for (int j = 0; j < ce; j++) {
        auto& i = es[j];
        int f = i.second.first;
        int t = i.second.second;
        if (get(f) != get(t)) {
            g[f].push_back(t);
            g[t].push_back(f);
            unite(f, t);
            ans = ans - n * m + i.first;
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < k; i++) {
        if (!used[i] && g[i].size() <= 1) {
            dfs(i, -1);
        }
    }



    return 0;
}