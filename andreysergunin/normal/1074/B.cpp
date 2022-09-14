#include <iostream>
#include <stdio.h>
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
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(random_device{}());

const int MAXN = 1e4;
vector<int> g[MAXN];
int m[2];
int x[2][MAXN];
int used[MAXN];

int ask(char ch, int u) {
    cout << ch << " " << u + 1 << endl;
    int id;
    cin >> id;
    --id;
    return id;
}

int dfs(int v, int p = -1) {
    if (used[v]) {
        return v;
    }
    for (int u : g[v]) {
        if (u == p) {
            continue;
        }
        int w = dfs(u, v);
        if (w != -1) {
            return w;
        }
    }
    return -1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int k = 0; k < 2; ++k) {
        cin >> m[k];
        for (int i = 0; i < m[k]; ++i) {
            cin >> x[k][i];
            --x[k][i];
        }
    }

    for (int i = 0; i < m[0]; ++i) {
        used[x[0][i]] = 1;
    }

    int v = ask('B', x[1][0]);

    int u = dfs(v);

    int w = ask('A', u);

    bool res = false;

    for (int i = 0; i < m[1]; ++i) {
        if (w == x[1][i]) {
            res = true;
        }
    }

    if (res) {
        cout << "C " << u + 1 << endl; 
    } else {
        cout << "C -1" << endl;
    }

    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
    memset(used, 0, n * sizeof(int));
}

int main() {
    
     ios_base::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
    
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        solve();
    }
    
}