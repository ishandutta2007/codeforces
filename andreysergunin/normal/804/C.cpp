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

typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
mt19937 rr(random_device{}());

const int P = 1e9 + 7;
const int INF = 1e9;

vector<vector<int>> g;

vector<int> col;
vector<vector<int>> forbid;
vector<vector<int>> s;
vector<vector<int>> r;

void dfs1(int v, int p) {

    vector<int> toCol;
    for (int cr : s[v]) {
        if (col[cr] == 0)
            toCol.push_back(cr);
    }

    sort(all(forbid[v]));
    forbid[v].resize(unique(all(forbid[v])) - forbid[v].begin());
    int cur = 1;
    int k = 0;
    for (int i = 0; i < sz(forbid[v]) && k < sz(toCol); ++i) {
        if (forbid[v][i] != cur) {
            col[toCol[k]] = cur;
            ++k;
            --i;
        }
        ++cur;
    }

    for (int i = k; i < sz(toCol); ++i) {
        col[toCol[i]] = cur;
        ++cur;
    }

    for (int sub : toCol) {
        for (int i = 0; i < sz(r[sub]); ++i)
            forbid[r[sub][i]].push_back(col[sub]);
    }

    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs1(u, v);
    }
}



int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    g.resize(n);
    s.resize(n);
    r.resize(m);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        s[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> s[i][j];
            --s[i][j];
            r[s[i][j]].push_back(i);
        }
    }


    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    col.resize(m);
    forbid.resize(n);

    dfs1(0, -1);

    int c = 0;

    for (int i = 0; i < m; ++i) {
        if (sz(r[i]) == 0)
            col[i] = 1;
    }

    for (int i = 0; i < m; ++i)
        c = max(c, col[i]);

    cout << c << endl;
    for (int i = 0; i < m; ++i)
        cout << col[i] << " ";
    cout << endl;

    return 0;
}