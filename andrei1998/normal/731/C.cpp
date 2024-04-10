#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 200000 + 5;

int n, m, k;

int color[NMAX];
vector <int> graph[NMAX];

bool vis[NMAX];

int freq[NMAX];
vector <int> nodes;
int best;

void dfs(int node) {
    vis[node] = true;
    nodes.push_back(node);
    ++ freq[color[node]];
    if (freq[color[node]] > best)
        best = freq[color[node]];

    for (auto it: graph[node])
        if (!vis[it])
            dfs(it);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
        cin >> color[i];

    int a, b;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        if (!vis[i]) {
            best = 0;
            for (auto it: nodes)
                freq[color[it]] = 0;
            nodes.clear();

            dfs(i);

            ans += nodes.size() - best;
        }

    cout << ans << '\n';
    return 0;
}