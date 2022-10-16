#include <bits/stdc++.h>

using namespace std;

const int NMAX = 80 + 2;
vector <pair <int, int> > graph[NMAX];

int dp[NMAX][NMAX][NMAX][NMAX];

int compute(int l, int r, int node, int moves) {
    if (!moves)
        return 0;
    if (dp[l][r][node][moves])
        return dp[l][r][node][moves];
    dp[l][r][node][moves] = 1E9 + 15;

    for (auto it: graph[node]) {
        int where = it.first;
        int c = it.second;
        if (where < node && where >= l)
            dp[l][r][node][moves] = min(dp[l][r][node][moves], c + compute(l, node - 1, where, moves - 1));
        else if (where > node && where <= r)
            dp[l][r][node][moves] = min(dp[l][r][node][moves], c + compute(node + 1, r, where, moves - 1));
    }

    return dp[l][r][node][moves];
}

int main()
{
    int N, K;
    cin >> N >> K;
    K --;

    int M = 0;
    cin >> M;
    while (M --) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    int ans = 1E9 + 15;
    for (int i = 1; i <= N; ++ i)
        ans = min(ans, compute(1, N, i, K));

    if (ans > 1E9)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}