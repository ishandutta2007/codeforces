#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

vector< vector<int> > edge;
vector<int> w;
vector<int> used;
vector<int> ans;

void dfs(int v, int a) {
    w[v] = 1;;
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] != a && used[edge[v][i]] == 0) {
            dfs(edge[v][i], v);
            w[v] += w[edge[v][i]];
        }
    }
}

int center(int v) {
    dfs(v, -1);
    for (; ;) {
        bool f = true;
        int k = 0;
        for (k = 0; k < edge[v].size(); k++)
            if (used[edge[v][k]] == 0 && 2 * w[edge[v][k]] > w[v]) {
                f = false;
                break;
            }
        if (f)
            return v;
        w[v] -= w[edge[v][k]];
        w[edge[v][k]] += w[v];
        v = edge[v][k];
    }
}

void solve(int v, int c) {
    int u = center(v);
    used[u] = 1;
    ans[u] = c;
    for (int i = 0; i < edge[u].size(); i++)
        if (used[edge[u][i]] == 0)
            solve(edge[u][i], c + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    edge.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    w.resize(n);
    used.resize(n);
    ans.resize(n);
    solve(0, 0);
    for (int i = 0; i < n; i++)
        cout << (char)('A' + ans[i]) << " ";
    return 0;
}