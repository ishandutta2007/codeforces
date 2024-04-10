#include <bits/stdc++.h>

#define lint long long int
using namespace std;

const int NMAX = 100005;

double dp[NMAX];
int sz[NMAX];
vector <int> graph[NMAX];

void dfs(int node) {
    sz[node] = 1;
    for (auto it: graph[node]) {
        dfs(it);
        sz[node] += sz[it];
    }
}

void dfs2(int node, int father) {
    if (!father)
        dp[node] = 1;
    else
        dp[node] = 1 + dp[father] + (sz[father] - sz[node] - 1) * 0.5;

    for (auto it: graph[node])
        dfs2(it, node);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int n;
    cin >> n;

    int f;
    for (int i = 2; i <= n; ++ i) {
        cin >> f;
        graph[f].push_back(i);
    }

    dfs(1);
    dfs2(1, 0);

    for (int i = 1; i <= n; ++ i)
        cout << fixed << setprecision(6) << dp[i] << " \n"[i == n];
    return 0;
}