#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int NMAX = 1e5 + 5;

int n;
vector <int> graph[2 * NMAX];
int color[2 * NMAX];

pair <int, int> pairs[NMAX];

void dfs(int node) {
    for (auto it: graph[node])
        if (!color[it]) {
            color[it] = 3 ^ color[node];
            dfs(it);
        }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        cin >> pairs[i].first;
        cin >> pairs[i].second;

        graph[pairs[i].first].push_back(pairs[i].second);
        graph[pairs[i].second].push_back(pairs[i].first);
    }

    for (int i = 1; i <= 2 * n; i += 2) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }

    for (int i = 1; i <= 2 * n; ++ i)
        if (!color[i]) {
            color[i] = 1;
            dfs(i);
        }

    for (int i = 1; i <= n; ++ i)
        cout << color[pairs[i].first] << ' ' << color[pairs[i].second] << '\n';
    return 0;
}