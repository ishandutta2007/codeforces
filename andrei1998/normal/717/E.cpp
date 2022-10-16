#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 200000 + 5;

vector <int> graph[NMAX];

bool color[NMAX];

vector <int> sol;

void dfs(int node, int father) {
    color[node] ^= 1;
    sol.push_back(node);
    for (auto it: graph[node])
        if (it != father) {
            dfs(it, node);
            color[node] ^= 1;
            sol.push_back(node);
        }

    if (color[node] == 1 && node > 1) {
        sol.push_back(father);
        sol.push_back(node);

        color[father] ^= 1;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    int type;
    for (int i = 1; i <= n; ++ i) {
        cin >> type;
        if (type == -1)
            color[i] = 1;
    }

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    int node = 1;
    int son = graph[1].back();

    if (color[1] == 0) {
        sol.push_back(son);
        sol.push_back(node);
        sol.push_back(son);
    }

    for (int i = 0; i < sol.size(); ++ i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];

    return 0;
}