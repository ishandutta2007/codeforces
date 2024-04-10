#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 100005, Mod = 1000000007;

vector<int> G[Nmax];
int Type[Nmax];
int Dp[Nmax][2];

int Pow(int x, int y) {
    int ret = 1;

    for (; y; y >>= 1) {
        if (y & 1)
            ret = 1LL * ret * x % Mod;

        x = 1LL * x * x % Mod;
    }

    return ret;
}

int InvMod(const int x) {
    return Pow(x, Mod - 2);
}

void Dfs(const int node, const int father) {
    if (father)
        G[node].erase(find(G[node].begin(), G[node].end(), father));

    if (G[node].empty()) {
        if (Type[node])
            Dp[node][1] = 1;
        else
            Dp[node][0] = 1;
    } else {
        for (const int p: G[node])
            Dfs(p, node);

        if (Type[node]) {
            int s = 1;
            for (const int p: G[node]) {
                s = 1LL * s * (Dp[p][0] + Dp[p][1]) % Mod;
            }

            Dp[node][1] = s;
        } else {
            int s = 1;
            for (const int p: G[node]) {
                s = 1LL * s * (Dp[p][0] + Dp[p][1]) % Mod;
            }

            Dp[node][0] = s;

            int Sum = 0;
            for (const int p: G[node]) {
                Sum = (Sum + 1LL * s * InvMod((Dp[p][0] + Dp[p][1]) % Mod) % Mod * Dp[p][1] % Mod) % Mod;
            }

            Dp[node][1] = Sum;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N;
    scanf("%d", &N);

    for (int i = 2; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        ++x;

        G[i].push_back(x);
        G[x].push_back(i);
    }

    for (int i = 1; i <= N; ++i) {
        int x;
        scanf("%d", &x);
        Type[i] = x;
    }

    Dfs(1, 0);

    printf("%d\n", Dp[1][1]);
}