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
vector< vector<int> > num;
vector<int> vis;
vector< pair<int, int> > ans;
vector<int> nxt;
int s = 0;

void dfs(int v) {
    for ( ; nxt[v] < edge[v].size(); nxt[v]++) {
        if (vis[num[v][nxt[v]]] == 0) {
            vis[num[v][nxt[v]]] = 1;
            int x = nxt[v];
            dfs(edge[v][nxt[v]]);
            if (s)
                ans.push_back(make_pair(v, edge[v][x]));
            else
                ans.push_back(make_pair(edge[v][x], v));
            s = 1 - s;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    edge.resize(n);
    num.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
        num[u].push_back(i);
        num[v].push_back(i);
    }
    vector<int> odd;
    for (int i = 0; i < n; i++)
        if (edge[i].size() % 2 == 1)
            odd.push_back(i);
    for (int i = 0; i < odd.size(); i += 2) {
        edge[odd[i]].push_back(odd[i + 1]);
        edge[odd[i + 1]].push_back(odd[i]);
        num[odd[i]].push_back(m + i / 2);
        num[odd[i + 1]].push_back(m + i / 2);
    }
    m = m + (int)odd.size() / 2;
    if (m % 2 == 1) {
        edge[0].push_back(0);
        num[0].push_back(m++);
    }
    nxt.resize(n);
    vis.resize(m);
    dfs(0);
    cout << m << endl;
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    return 0;
}