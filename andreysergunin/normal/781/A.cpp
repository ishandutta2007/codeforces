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

vector<int> col;
int k = 1;

void dfs(int v, int p, int c1, int c2) {
    col[v] = c1;
    int cur = 1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        while (cur == c1 || cur == c2)
            ++cur;
        dfs(u, v, cur, c1);
        ++cur;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

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

    for (int i = 0; i < n; ++i)
        k = max(k, sz(g[i]) + 1);

    col.resize(n);
    dfs(0, -1, 1, 0);

    cout << k << endl;
    for (int i = 0; i < n; ++i)
        cout << col[i] << " ";
    cout << endl;
}