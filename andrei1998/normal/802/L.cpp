#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000000 + 7;
int inv(int nr) {
    int ans = 1, aux = nr % MOD, b = MOD - 2;
    while (b) {
        if (b & 1)
            ans = (1LL * ans * aux) % MOD;
        aux = (1LL * aux * aux) % MOD;
        b >>= 1;
    }
    return ans;
}

const int NMAX = 100000 + 5;
vector <pair <int, int> > graph[NMAX];

//dp[node] = a[node] * dp[father[node]] + b[node]
int a[NMAX], b[NMAX];

void dfs(int node, int father, int edge) {
    int sons = 0;
    for (auto it: graph[node])
        if (it.first != father) {
            dfs(it.first, node, it.second);
            ++ sons;
        }

    if (sons) {
        int sumASons = 0, sumBSOns = 0;
        for (auto it: graph[node])
            if (it.first != father) {
                sumASons += a[it.first];
                sumBSOns += b[it.first] + it.second;

                if (sumASons >= MOD)
                    sumASons -= MOD;
                while (sumBSOns >= MOD)
                    sumBSOns -= MOD;
            }

        a[node] = inv(graph[node].size() + MOD - sumASons);
        b[node] = ((1LL * edge + sumBSOns) * a[node]) % MOD;
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int N;
    cin >> N;

    for (int i = 1; i < N; ++ i) {
        int a, b, c;
        cin >> a >> b >> c;
        ++ a, ++ b;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1, 0, 0);

    cout << b[1] << '\n';
    return 0;
}