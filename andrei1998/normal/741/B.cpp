#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 1000 + 5;

int n, m, W;
int w[NMAX];
int b[NMAX];

vector <int> graph[NMAX];
int comp[NMAX];

void dfs(int node, int cmp) {
    comp[node] = cmp;
    for (auto it: graph[node])
        if (!comp[it])
            dfs(it, cmp);
}

vector <pair <int, int> > groups[NMAX];

int dp[NMAX][NMAX];

int main()
{
    cin >> n >> m >> W;

    for (int i = 1; i <= n; ++ i)
        cin >> w[i];
    for (int i = 1; i <= n; ++ i)
        cin >> b[i];

    for (int i = 1; i <= m; ++ i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cmp = 0;
    for (int i = 1; i <= n; ++ i)
        if (!comp[i])
            dfs(i, ++ cmp);

    for (int i = 1; i <= n; ++ i)
        groups[comp[i]].push_back(make_pair(w[i], b[i]));

    for (int i = 1; i <= cmp; ++ i) {
        int sumW = 0;
        int sumB = 0;
        for (auto it: groups[i]) {
            sumW += it.first;
            sumB += it.second;
        }
        groups[i].push_back(make_pair(sumW, sumB));
    }

    for (int i = 1; i <= cmp; ++ i) {
        for (int j = 1; j <= W; ++ j) {
            dp[i][j] = dp[i - 1][j];
            for (auto it: groups[i])
                if (j - it.first >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - it.first] + it.second);
        }
    }

    cout << dp[cmp][W] << '\n';
    return 0;
}