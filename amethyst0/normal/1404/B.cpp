#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];

int dfs(int s, int t, int p) {
    if (s == t) {
        return 0;
    }

    for (int u : ed[s]) {
        if (u == p) {
            continue;
        }

        int d = dfs(u, t, s);
        if (d != -1) {
            return d + 1;
        }
    }

    return -1;
}

int dst[maxn];

void build(int v, int p, int hh) {
    dst[v] = hh;

    for (int u : ed[v]) {
        if (u != p) {
            build(u, v, hh + 1);
        }
    }
}

int main() {
    int t;

    cin >> t;

    while (t--) {
        int n, a, b, da, db;
        scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
        a--;
        b--;

        for (int i = 0; i < n; i++) {
            ed[i].clear();
        }

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            ed[x].push_back(y);
            ed[y].push_back(x);
        }

        build(0, -1, 0);

        int v = 0;

        for (int i = 0; i < n; i++) {
            if (dst[v] < dst[i]) {
                v = i;
            }
        }

        build(v, -1, 0);

        for (int i = 0; i < n; i++) {
            if (dst[v] < dst[i]) {
                v = i;
            }
        }

        db = min(db, dst[v]);
        da = min(da, dst[v]);

        if (dfs(a, b, -1) <= da) {
            printf("Alice\n");
        }
        else if (2 * da >= db) {
            printf("Alice\n");
        }
        else {
            printf("Bob\n");
        }
    }
}