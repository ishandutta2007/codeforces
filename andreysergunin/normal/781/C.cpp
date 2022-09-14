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

vector<int> path;
vector<bool> used;

void dfs(int v) {
    path.push_back(v);
    used[v] = 1;
    for (int u : g[v]) {
        if (used[u])
            continue;
        dfs(u);
        path.push_back(v);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    used.resize(n);
    dfs(0);

    int s = sz(path);
    int st = (s - 1) / k + 1;
    for (int i = 0; i < k; ++i) {
        if (i * st >= s) {
            cout << 1 << " " <<  1 << endl;
            continue;
        }
        cout << min(s, st * (i + 1)) - i * st << " ";
        for (int j = i * st; j < min(s, st * (i + 1)); ++j)
            cout << path[j] + 1 << " ";
        cout << endl;
    }
}