#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

vector<vector<int>> g;
vector<int> c, col;

vector<int> up, down;

void dfs1(int v, int p) {
    col[v] = c[v];
    for (int u : g[v]) {
        if (p == u)
            continue;
        dfs1(u, v);
        if (col[u] != c[v]) 
            col[v] = -1;

        if (col[u] == -1) 
            down[v] = 0;
    }
}

void dfs2(int v, int p, int x) {
    if (c[v] != x)
        return;

    vector<int> diff;
    for (int u : g[v]) {
        if (p == u)
            continue;

        if (c[v] != col[u])
            diff.push_back(u);
    }
    if (sz(diff) == 1) {
        up[diff[0]] = 1;
        dfs2(diff[0], v, c[v]);
    }
}

int main() {
    // ifstream cin("input.txt");
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    c.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    down.resize(n, 1);
    up.resize(n, 0);
    col.resize(n);

    up[0] = 1;
    dfs1(0, -1);
    dfs2(0, -1, c[0]);

    // for (int i = 0; i < n; ++i) {
    //     cout << up[i] << " " << down[i] << endl;
    // }

    // for (int i = 0; i < n; ++i)
    //     cout << col[i] << " ";
    // cout << endl;

    for (int i = 0; i < n; ++i) {
        if (up[i] && down[i]) {
            cout << "YES" << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}