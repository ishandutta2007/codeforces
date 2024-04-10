#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 10000 + 5;

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
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        int node;
        cin >> node;
        graph[i].push_back(node);
        graph[node].push_back(i);
    }

    int cnt = 0;
    for (int i = 1; i <= N; ++ i)
        if (!vis[i]) {
            ++ cnt;
            dfs(i);
        }

    cout << cnt << '\n';
    return 0;
}