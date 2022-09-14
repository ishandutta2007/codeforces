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

vector< vector<int> > edge;
vector<int> l;

void dfs(int v, int p, int d) {
    for (int i = 0; i < edge[v].size(); i++) {
        if (edge[v][i] == p)
            continue;
        dfs(edge[v][i], v, d + 1);
    }
    if (edge[v].size() == 1)
        l.push_back(d);
}

int main() {
    int n;
    cin >> n;
    edge.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < edge[0].size(); i++) {
        dfs(edge[0][i], 0, 0);
        sort(l.begin(), l.end());
        int cur = l[0];
        for (int j = 1; j < l.size(); ++j)
            cur = max(l[j], cur + 1);
        ans = max(ans, cur);
        l.clear();
    }
    cout << ans + 1 << endl;
    return 0;
}