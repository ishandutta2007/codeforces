#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 2005;

int A[Nmax][Nmax];
vector< pair<int, int> > G[Nmax];

int F[Nmax];

struct Edge {
    int x, y, cost;

    Edge(int x, int y, int cost) {
        this->x = x;
        this->y = y;
        this->cost = cost;
    }

    bool operator<(const Edge &other) const {
        return cost < other.cost;
    }
};

int Find(int x) {
    int y, p;
    for (y = F[x]; F[y] != y; y = F[y]);
    for (; x != y; x = p) {
        p = F[x];
        F[x] = y;
    }
    return y;
}

void Union(int x, int y) {
    F[Find(x)] = Find(y);
}

bool ok = true;
int Root;

void Dfs(int node, int father, int dist) {
    if (A[node][Root] != dist) {
        ok = false;
        return;
    }

    for (auto p: G[node]) {
        if (p.first != father) {
            Dfs(p.first, node, dist + p.second);
        }

        if (!ok)
            return;
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

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            scanf("%d", &A[i][j]);

            if (i == j && A[i][j] != 0) {
                printf("NO\n");
                return 0;
            }

            if (i != j && A[i][j] == 0) {
                printf("NO\n");
                return 0;
            }

            if (i > j && A[i][j] != A[j][i]) {
                printf("NO\n");
                return 0;
            }
        }
    }

    vector<Edge> edges;
    for (int i = 1; i <= N; ++i) {
        F[i] = i;
        for (int j = i + 1; j <= N; ++j)
            edges.push_back(Edge(i, j, A[i][j]));
    }

    sort(edges.begin(), edges.end());

    for (Edge curr: edges) {
        if (Find(curr.x) != Find(curr.y)) {
            Union(curr.x, curr.y);
            G[curr.x].push_back(make_pair(curr.y, curr.cost));
            G[curr.y].push_back(make_pair(curr.x, curr.cost));
        }
    }

    for (int i = 1; i <= N && ok; ++i) {
        Root = i;
        Dfs(i, 0, 0);
    }

    if (ok)
        printf("YES\n");
    else
        printf("NO\n");
}