#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int Nmax = 405, INF = 0x3f3f3f3f;

int F[Nmax];
vector< pair<int, int> > G[Nmax];
vector<int> Cnt[Nmax][Nmax];

int Dp[Nmax][Nmax], Dpnode[Nmax][Nmax], Next[Nmax][Nmax];
int N, K;

void Dfs(const int node, const int father)
{
    F[node] = father;
    for (int i = 0; i < int(G[node].size()); i++)
    {
        if (G[node][i].first == father)
        {
            G[node][i] = G[node].back();
            G[node].pop_back();
            break;
        }
    }

    for (auto p: G[node])
        Dfs(p.first, node);

    const int edges = G[node].size();

    memset(Dpnode, INF, sizeof(Dpnode));
    Dpnode[0][1] = edges;

    for (int i = 1; i <= K; i++)
        Cnt[node][i].resize(edges + 1);

    for (int i = 1; i <= edges; i++)
    {
        const int nodec = G[node][i - 1].first;

        Dpnode[i][1] = edges;
        Cnt[node][1][i] = 0;

        for (int j = 2; j <= K; j++)
        {
            Dpnode[i][j] = Dpnode[i - 1][j];

            for (int k = 1; j - k > 0; k++)
            {
                if (Dpnode[i][j] > Dpnode[i - 1][j - k] + Dp[nodec][k] - 1)
                {
                    Dpnode[i][j] = Dpnode[i - 1][j - k] + Dp[nodec][k] - 1;
                    Next[i][j] = j - k;

                    Cnt[node][j][i] = k;
                }
            }
        }
    }
    memcpy(Dp[node], Dpnode[edges], sizeof(Dp[node]));
}

void Build(const int node, const int K1)
{
    if (!K1) return;

    const int edges = G[node].size();

    int k = K1;
    for (int i = edges; i; i--)
    {
        const int nodec = G[node][i - 1].first, x= Cnt[node][k][i];


        Build(nodec, x);
        if (!x)
            cout << G[node][i - 1]. second << " ";

        k -= Cnt[node][k][i];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    ios :: sync_with_stdio(false);

    cin >> N >> K;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        G[x].push_back(make_pair(y, i));
        G[y].push_back(make_pair(x, i));
    }

    Dfs(1, 0);

    int Sol = INF;
    for (int i = 1; i <= N; i++)
    {
        Sol = min(Sol, Dp[i][K] + (i != 1));
    }

    cout << Sol << "\n";

    for (int i = 1; i <= N; i++)
    {
        if (Dp[i][K] + (i != 1) == Sol)
        {
            Build(i, K);

            if (i != 1)
            {
                const int father = F[i];

                for (auto p: G[father])
                {
                    if (p.first == i)
                    {
                        cout << p.second << " ";
                        break;
                    }
                }
            }

            break;
        }
    }
    cout << "\n";
}