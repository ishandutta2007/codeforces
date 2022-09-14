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
vector<int> vis;
int n, m;

pair<int, int> g(int v) {
    if (v < m)
        return make_pair(0, v);
    if (m <= v && v < n + m)
        return make_pair(v - m, m);
    if (n + m <= v && v < n + 2 * m)
        return make_pair(n, 2 * m + n - v);
    return make_pair(2 * n + 2 * m - v, 0);
}

int f(pair<int, int> p) {
    if (p.first == 0)
        return p.second;
    if (p.second == m)
        return m + p.first;
    if (p.first == n)
        return n + 2 * m - p.second;
    return 2 * n + 2 * m - p.first;
}

bool inBoard(pair<int, int> a) {
    return (0 <= a.first && a.first <= n && 0 <= a.second && a.second <= m);
}

void dfs(int v) {
    vis[v] = 1;
    pair<int, int> p = g(v);
    pair<int, int> q;
    
    q = make_pair(0, p.first + p.second);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(0, p.second - p.first);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(p.second + p.first, 0);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(p.first - p.second, 0);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    
    q = make_pair(n, p.second + n - p.first);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(n, p.second - n + p.first);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(p.first + m - p.second, m);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
    q = make_pair(p.first - m + p.second, m);
    if (inBoard(q) && !vis[f(q)])
        dfs(f(q));
    
}

int main() {
    cin >> n >> m;
    n--; m--;
    int ans = 0;
    vis.resize(2 * n + 2 * m);
    for (int i = 0; i < 2 * n + 2 * m; i++)
        if (vis[i] == 0) {
            ++ans;
            dfs(i);
        }
    cout << ans << endl;
    return 0;
}