#include <iostream>
#include <vector>

using namespace std;

vector <int> graph[200005];

int lanturi;
bool dfs(int node, int father) {
    int fii = 0;
    for (auto it: graph[node])
        if (it != father) {
            fii += dfs(it, node);
        }

    if (!fii) {
        lanturi ++;
        return true;
    }
    else if (fii == 1)
        return true;
    else {
        lanturi --;
        return false;
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    int a, b;
    for (int i = 1; i < n; ++ i) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (x < y) {
        //Arborele e mai bun
        dfs(1, 0);

        int muchii = lanturi - 1;

        cout << 1ll * muchii * y + (n - 1ll - muchii) * x << '\n';
    }
    else {
        for (int i = 1; i <= n; ++ i)
            if (graph[i].size() == n - 1) {
                cout << (n - 2ll) * y + x << '\n';
                return 0;
            }

        cout << (n - 1ll) * y << '\n';
    }

    return 0;
}