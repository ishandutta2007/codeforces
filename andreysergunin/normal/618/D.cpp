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
vector<int> p, q;

void dfs(int v, int a) {
    for (int i = 0; i < edge[v].size(); i++)
        if (edge[v][i] != a)
            dfs(edge[v][i], v);
    vector<int> x;
    int s = 0;
    for (int i = 0; i < edge[v].size(); i++)
        if (edge[v][i] != a) {
            x.push_back(q[edge[v][i]] - p[edge[v][i]]);
            s += p[edge[v][i]];
        }
    sort(x.begin(), x.end());
    q[v] = s + 1;
    if (x.size() > 0)
        q[v] = min(q[v], s + x[0]);
    p[v] = q[v];
    if (x.size() > 1)
        p[v] = min(p[v], s + x[0] + x[1] - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    long long x, y;
    cin >> n >> x >> y;
    edge.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    long long ans;
    if (x >= y) {
        bool f = true;
        for (int i = 0; i < n; i++)
            if (edge[i].size() == n - 1)
                f = false;
        if (f)
            ans = ((long long)n - 1) * y;
        else
            ans = ((long long)n - 2) * y + x;
        cout << ans << endl;
        return 0;
    }
    p.resize(n);
    q.resize(n);
    dfs(0, - 1);
    ans = y * ((long long)p[0] - 1) + x * ((long long)n - (long long)p[0]);
    cout << ans;
    
    
    return 0;
}