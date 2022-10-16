#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100005;

bool cat[NMAX];
vector <int> graph[NMAX];

int ans = 0, m;
void dfs (int node, int father, int cats, int maxcats) {
    if (cat[node])
        ++ cats;
    else
        cats = 0;
    maxcats = max(cats, maxcats);

    if (graph[node].size() == 1 && father) {
        ans += (maxcats <= m);
        return ;
    }

    for (auto it: graph[node])
        if (it != father)
            dfs(it, node, cats, maxcats);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n;
    cin >> n >> m;

    for (int i = 1; i <= n; ++ i)
        cin >> cat[i];

    int x, y;

    for (int i = 1; i < n; ++ i) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1, 0, 0, 0);

    cout << ans <<'\n';
    return 0;
}