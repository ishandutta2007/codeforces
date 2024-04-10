#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 1005;

vector<int> graph[MAX_N];
int vis[MAX_N];
int nr;

void dfs(int node) {
    vis[node] = true;
    nr += 1;
    for (auto son : graph[node]) {
        if (!vis[son]) {
            dfs(son);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << ((nr == n && m == n - 1) ? "yes\n" : "no\n");
    return 0;
}