#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex> 
#include <ctime>
#include <cstring>
#include <stack>
#include <random>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

const double EPS = 1e-9;

vector<vector<int>> edge;

vector<int> w, cen, par;

void dfs(int v, int p) {
    par[v] = p;
    w[v] = 1;
    for (int i = 0; i < sz(edge[v]); ++i) {
        if (edge[v][i] != p) {
            dfs(edge[v][i], v);
            w[v] += w[edge[v][i]]; 
        }
    }

    bool f = true;
    int x = 0;
    for (int i = 0; i < sz(edge[v]); ++i)
        if (edge[v][i] != p) {
            if (2 * w[edge[v][i]] > w[v]) {
                f = false;
                x = cen[edge[v][i]];
            }
        }

    if (f) {
        cen[v] = v;
        return;
    }

    for (; (w[v] - w[x]) * 2 > w[v]; x = par[x]);
    cen[v] = x;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    edge.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }

    w.resize(n);
    cen.resize(n);
    par.resize(n);
    dfs(0, -1);

    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        --v;
        cout << cen[v] + 1 << endl;
    }

    return 0;
}