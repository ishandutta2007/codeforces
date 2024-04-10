#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
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

const int maxn = 210, inf = (int)1e9;

vector <pii> ed[maxn];

int dst[maxn][maxn];

int c[maxn];

bool dfs(int v, int cl) {
    if (c[v] != -1) {
        return c[v] == cl;
    }

    c[v] = cl;

    for (auto[u, id] : ed[v]) {
        if (!dfs(u, cl ^ 1)) {
            return false;
        }
    }

    return true;
}

vector <int> d;
int n;
bool in[maxn];

int ford(int s) {
    d.assign(n, inf);
    d[s] = 0;
    queue <int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        in[v] = false;

        for (auto[u, w] : ed[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                if (!in[u]) {
                    in[u] = true;
                    q.push(u);
                }
            }
        }
    }

    int maxel = -inf;
    int minel = inf;

    for (int x : d) {
        maxel = max(maxel, x);
        minel = min(minel, x);
    }

    for (int &x : d) {
        x -= minel;
    }

    return maxel - minel;
}

int main() {
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dst[i][j] = (i == j ? 0 : inf);
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, b;
        scanf("%d %d %d", &x, &y, &b);
        x--;
        y--;
        if (b) {
            dst[x][y] = 1;
            dst[y][x] = -1;
            ed[x].push_back(mp(y, 1));
            ed[y].push_back(mp(x, -1));
        }
        else {
            dst[x][y] = 1;
            dst[y][x] = 1;
            ed[x].push_back(mp(y, 1));
            ed[y].push_back(mp(x, 1));
        }
    }

    memset(c, -1, sizeof c);
    if (!dfs(0, 0)) {
        cout << "NO\n";
        return 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dst[i][j] > dst[i][k] + dst[k][j]) {
                    dst[i][j] = max(-inf, dst[i][k] + dst[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dst[i][i] < 0) {
            cout << "NO\n";
            return 0;
        }
    }

    int ans = -1;
    vector <int> cur;

    for (int i = 0; i < n; i++) {
        int res = ford(i);
        if (res >= ans) {
            ans = res;
            cur = d;
        }
    }

    cout << "YES\n";
    cout << ans << '\n';
    for (int x : cur) {
        cout << x << ' ';
    }

    cout << '\n';
}