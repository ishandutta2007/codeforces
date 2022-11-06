#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;

vector<int> g[V];
int d[V];
void dfs(int u, int f) {
    if (f == -1) d[u] = 0;
    else d[u] = d[f] + 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v == f) continue;
        dfs(v, u);
    }
}

int _, n, A, B, da, db, u, v;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d%d%d", &n, &A, &B, &da, &db);
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
            g[v].PB(u);
        }
        bool ok = true;
        if (da * 2 >= db) ok = false;
        dfs(1, -1);
        int id = 1;
        for (int i = 1; i <= n; ++i) if (d[i] > d[id]) id = i;
        dfs(id, -1);
        id = 1;
        for (int i = 1; i <= n; ++i) if (d[i] > d[id]) id = i;
        if (da * 2 >= d[id]) ok = false;
        dfs(A, -1);
        if (d[B] <= da) ok = false;
        if (ok) puts("Bob");
        else puts("Alice");

    }
    return 0;
}

/*
4
4 3 2 1 2
1 2
1 3
1 4
6 6 1 2 5
1 2
6 5
2 3
3 4
4 5
9 3 9 2 5
1 2
1 6
1 9
1 3
9 5
7 9
4 8
4 3
11 8 11 3 3
1 2
11 9
4 9
6 5
2 10
3 2
5 9
8 3
7 4
7 10
*/