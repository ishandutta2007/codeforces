#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

vector<int> g[3333];
int dist[3333];
queue<int> q;
bool used[3333];

int dfs(int v, int p) {
    used[v] = true;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (used[i]) {
            dist[v] = 0;
            q.push(v);
            return i;
        }
        int r = dfs(i, v);
        if (r == -2) {
            return -2;
        }
        if (r != -1) {
            dist[v] = 0;
            q.push(v);
            return v == r ? -2 : r;
        }
    }
    return -1;
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        dist[i] = 1e9;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (dfs(i, -1) != -1) {
                break;
            }
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : g[v]) {
            if (dist[i] > dist[v] + 1) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}