#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100005;

vector <int> graph[NMAX];

bool vis[NMAX];

void dfs(int node) {
    vis[node] = true;
    for (auto it: graph[node])
        if (!vis[it])
            dfs(it);
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (m != (n - 1)) {
        cout << "no\n";
        return 0;
    }

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; ++ i)
        if (!vis[i]) {
            cout << "no\n";
            return 0;
        }

    cout << "yes\n";
    return 0;
}