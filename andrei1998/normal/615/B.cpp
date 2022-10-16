#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 100005;

int dp[NMAX];
int deg[NMAX];

vector <int> graph[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; ++ i) {
        cin >> a >> b;
        ++ deg[a], ++ deg[b];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    long long int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        for (auto it: graph[i])
            if (1 + dp[it] > dp[i])
                dp[i] = 1 + dp[it];
        if (1ll * dp[i] * deg[i] > ans)
            ans = 1ll * dp[i] * deg[i];
    }

    cout << ans << '\n';
    return 0;
}