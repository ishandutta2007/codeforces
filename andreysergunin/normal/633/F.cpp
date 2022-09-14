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
#include <queue>

using namespace std;


vector<long long> a;
vector<long long> p, q, r, s;
vector<vector<int>> edge;

void dfs(int v, int an) {
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] == an)
            continue;
        dfs(edge[v][i], v);
    }
    int rF = -1;
    int rS = -1;
    
    int sF = -1;
    int sS = -1;
    int sT = -1;
    
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] == an)
            continue;
        if (rF == -1 || r[rF] < r[edge[v][i]]) {
            rS = rF;
            rF = edge[v][i];
        }
        else {
            if (rS == -1 || r[rS] < r[edge[v][i]])
                rS = edge[v][i];
        }
        
        if (sF == -1 || s[sF] < s[edge[v][i]]) {
            sT = sS;
            sS = sF;
            sF = edge[v][i];
        }
        else {
            if (sS == -1 || s[sS] < s[edge[v][i]]) {
                sT = sS;
                sS = edge[v][i];
            }
            else {
                if (sT == -1 || s[sT] < s[edge[v][i]])
                    sT = edge[v][i];
            }
        }
    }
    p[v] = 0;
    if (rF != -1)
        p[v] = max(p[v], a[v] + r[rF]);
    if (rF != -1 && rS != -1)
        p[v] = max(p[v], r[rF] + r[rS]);
    q[v] = 0;
    if (rF != -1)
        q[v] = a[v] + r[rF];
    r[v] = a[v] + (sF != -1 ? s[sF] : 0) + (sS != -1 ? s[sS] : 0);
    if (rF != -1)
        r[v] = max(r[v], r[rF]);
    s[v] = a[v];
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] == an)
            continue;
        
        p[v] = max(p[v], p[edge[v][i]]);
        long long w = a[v] + r[edge[v][i]];
        int t = 0;
        if (sF != -1 && edge[v][i] != sF) {
            ++t;
            w += s[sF];
        }
        if (sS != -1 && edge[v][i] != sS) {
            ++t;
            w += s[sS];
        }
        if (sT != -1 && t < 2 && edge[v][i] != sT)
            w += s[sT];
        p[v] = max(p[v], w);
        w = a[v] + q[edge[v][i]];
        if (sF != -1 && sF != edge[v][i])
            w += s[sF];
        else {
            if (sS != -1 && sS != edge[v][i])
                w += s[sS];
        }
        p[v] = max(p[v], w);
        p[v] = max(p[v], a[v] + r[edge[v][i]]);
        
        long long u = a[v] + s[edge[v][i]];
        if (rF != -1) {
            if (rF != edge[v][i])
                u += r[rF];
            else {
                if (rS != -1)
                    u += r[rS];
            }
        }
        q[v] = max(q[v], u);
        q[v] = max(q[v], a[v] + q[edge[v][i]]);
        q[v] = max(q[v], a[v] + r[edge[v][i]]);
        
        s[v] = max(s[v], a[v] + s[edge[v][i]]);
    }
    
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    edge.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    p.resize(n);
    q.resize(n);
    r.resize(n);
    s.resize(n);
    dfs(0, -1);
    cout << p[0] << endl;
    return 0;
}