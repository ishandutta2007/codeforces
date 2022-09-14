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

vector<int> vis;
vector< vector<int> > edge;
int n, m;
bool f = true;

void dfs(int v, int c) {
    vis[v] = c;
    for (int i = 0; i < n; i++) {
        if (edge[v][i] == 0) {
            if (vis[i] == 0)
                dfs(i, 3 - c);
            else {
                if (vis[i] + vis[v] != 3)
                    f = false;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    cin >> n >> m;
    edge.resize(n);
    for (int i = 0; i < n; i++) {
        edge[i].resize(n);
        edge[i][i] = 1;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u][v] = 1;
        edge[v][u] = 1;
    }
    vis.resize(n);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            dfs(i, 1);
    string ans;
    vector<int> a, b;
    
    for (int i = 0; i < n; i++) {
        bool t = true;
        for (int j = 0; j < n; j++)
            if (edge[i][j] == 0)
                t = false;
        if (t) {
            ans += 'b';
            continue;
        }
        if (vis[i] == 1) {
            ans += 'a';
            a.push_back(i);
        }
        else {
            ans += 'c';
            b.push_back(i);
        }
    }
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (edge[a[i]][b[j]] == 1)
                f = false;
    if (f) {
        cout << "YES" << endl;
        cout << ans << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}