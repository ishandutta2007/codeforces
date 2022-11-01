#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdio>

using namespace std;

const int Nmax = 1005, Mmax = 12;

int N, M, K, W;

char Mats[Nmax][Mmax][Mmax];

struct Edge {
    int x, y, cost;

    Edge (const int _x = 0, const int _y = 0, const int _cost = 0)
    {
        x = _x;
        y = _y;
        cost = _cost;
    }

    bool operator< (const Edge &e) const {
        return cost < e.cost;
    };
};

vector<Edge> Edges;
int Father[Nmax];

vector<int> G[Nmax];

int Find(int x)
{
    int y, p;
    for (y = Father[x]; Father[y] != y; y = Father[y]);

    for (; x != y; x = p)
    {
        p = Father[x];
        Father[x] = y;
    }

    return y;
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    Father[x] = y;
}

bitset<Nmax> V;

void Dfs(const int node, const int father)
{
    V[node] = 1;
    if (node) printf("%d %d\n", node, father);

    for (auto p: G[node])
        if (!V[p])
            Dfs(p, node);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    scanf("%d %d %d %d\n", &N, &M, &K, &W);
    for (int i = 1; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
            fgets(Mats[i][j] + 1, Mmax, stdin);
    }

    for (int i = 1; i <= K; i++)
    {
        for (int j = i + 1; j <= K; j++)
        {
            int x = 0;
            for (int p = 1; p <= N; p++)
                for (int l = 1; l <= M; l++)
                    if (Mats[i][p][l] != Mats[j][p][l])
                        x++;

            x *= W;
            Edges.push_back(Edge(i, j, x));
        }

        Edges.push_back(Edge(0, i, N * M));
    }

    sort(Edges.begin(), Edges.end());

    for (int i = 0; i <= K; i++)
        Father[i] = i;

    long long Cost = 0;
    for (auto curr: Edges)
    {
        if (Find(curr.x) != Find(curr.y))
        {
            Cost += curr.cost;
            Union(curr. x, curr.y);

            G[curr.x].push_back(curr.y);
            G[curr.y].push_back(curr.x);
        }
    }

    printf("%I64d\n", Cost);
    Dfs(0, 0);
}