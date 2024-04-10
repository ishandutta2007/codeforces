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
vector<int> vis1, vis2;
vector<int> a, b;
vector<int> ansu, ansv, ansd;
int n, vol, e;

void balance1(int v, int p, int u) {
    vis2[v] = 1;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis2[edge[v][i]] == 0)
            balance1(edge[v][i], v, u);
    if (p == u)
        return;
    if (p == -1) {
        for (int i = 0; i < edge[v].size(); i++)
            if (vis2[edge[v][i]] != 2) {
                int d = max(min(a[edge[v][i]], b[v] - a[v]), 0);
                if (d != 0) {
                    ansu.push_back(edge[v][i]);
                    ansv.push_back(v);
                    ansd.push_back(d);
                    a[edge[v][i]] -= d;
                    a[v] += d;
                }
            }
        return;
    }
    int d = max(min(a[v], vol - a[p]), 0);
    if (d != 0) {
        ansu.push_back(v);
        ansv.push_back(p);
        ansd.push_back(d);
        a[v] -= d;
        a[p] += d;
    }
}

void balance2(int v, int p) {
    vis2[v] = 1;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis2[edge[v][i]] == 0)
            balance2(edge[v][i], v);
    if (p == -1)
        return;
    int d = max(min(a[p], vol - a[v]), 0);
    if (d != 0) {
        ansu.push_back(p);
        ansv.push_back(v);
        ansd.push_back(d);
        a[p] -= d;
        a[v] += d;
    }
}


void dfs(int v) {
    vis1[v] = 1;
    for (int i = 0; i < edge[v].size(); i++)
        if (vis1[edge[v][i]] == 0)
            dfs(edge[v][i]);
    for (int i = 0; i < n; i++)
        if (vis2[i] == 1)
            vis2[i] = 0;
    balance2(v, -1);
    for (int i = 0; i < n; i++)
        if (vis2[i] == 1)
            vis2[i] = 0;
    balance1(v, -1, v);
    vis2[v] = 2;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> vol >> e;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    edge.resize(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vis1.resize(n);
    vis2.resize(n);
    for (int i = 0; i < n; i++)
        if (vis1[i] == 0)
            dfs(i);
    bool f = true;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            f = false;
    if (!f) {
        cout << "NO" << endl;
        return 0;
    }
    cout << ansd.size() << endl;
    for (int i = 0; i < (int)ansd.size(); i++)
        cout << ansu[i] + 1 << " " << ansv[i] + 1 << " " << ansd[i] << endl;
}