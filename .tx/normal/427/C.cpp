#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int c[111111];
vector<int> g[111111];
vector<int> rg[111111];
bool used[111111];
int col[111111];
vector<int> ts;

void dfs(int v) {
    used[v] = true;
    for (int i : g[v]) {
        if (!used[i]) {
            dfs(i);
        }
    }
    ts.push_back(v);
}

map<int, int> mc[111111];

void rdfs(int v, int cc) {
    col[v] = cc;
    mc[cc][c[v]]++;
    for (int i : rg[v]) {
        if (col[i] == 0) {
            rdfs(i, cc);
        }
    }
}

int main() {
    scid(n);
    for (int i = 0; i < n; ++i) {
        sci(c[i]);
    }
    scid(m);
    for (int i = 0; i < m; ++i) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        rg[y].push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    memset(used, 0, sizeof(used));
    reverse(all(ts));
    int gc = 0;
    for (int i = 0; i < n; i++) {
        int x = ts[i];
        if (col[x] == 0) {
            rdfs(x, ++gc);
        }
    }
    cerr << gc << endl;
    lint ac = 0;
    lint aw = 1;
    for (int i = 1; i <= gc; i++) {
        ac += mc[i].begin()->first;
        aw *= mc[i].begin()->second;
        aw %= lint(1e9 + 7);
    }
    cout << ac << " " << aw;

    return 0;
}