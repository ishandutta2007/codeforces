#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 300005;

vector <int> graph[NMAX];
int father[NMAX];

int c[NMAX];
int sz[NMAX];

void dfs(int node) {
    sz[node] = 1;

    int biggest = 0;
    for (auto it: graph[node]) {
        dfs(it);
        sz[node] += sz[it];

        if (sz[it] > sz[biggest])
            biggest = it;
    }

    if (!biggest || sz[biggest] <= sz[node] / 2)
        c[node] = node;
    else {
        c[node] = c[biggest];
        while (sz[node] - sz[c[node]] > sz[node] / 2)
            c[node] = father[c[node]];
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++ i) {
        cin >> father[i];
        graph[father[i]].push_back(i);
    }

    dfs(1);

    int node;
    while (q --) {
        cin >> node;
        cout << c[node] << '\n';
    }
    return 0;
}