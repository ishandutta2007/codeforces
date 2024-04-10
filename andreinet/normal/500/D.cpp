#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>

using namespace std;

const int Nmax = 100005;

struct Edge {
    int x, y, cost;
    Edge() {}
    Edge(int _x, int _y, int _cost):
        x(_x), y(_y), cost(_cost) {}
};

vector<pair<int, int>> G[Nmax];
int H[Nmax], Father[Nmax];
int N;

Edge edges[Nmax];
double Exp1[Nmax], ExpT[Nmax];

double P31(int T, int n) {
    if (n < 3) return 0;
    return (double) n / T * (double) (n - 1) / (T - 1) * (double) (n - 2) / (T - 2);
}

double P32(int T, int n) {
    return 1 - P31(T, n) - P31(T, T - n);
}

void Dfs(const int node, const int father) {
    H[node] = 1;
    Father[node] = father;
    for (auto& p: G[node]) {
        int n = p.first, cost = p.second;
        if (n == father) continue;
        Dfs(n, node);
        H[node] += H[n];
    }

    double expd1 = 0;
    for (auto& p: G[node]) {
        int n = p.first, cost = p.second;
        if (n == father) continue;

        expd1 += (Exp1[n] + cost);
        ExpT[node] += P31(H[node], H[n]) * ExpT[n];
    }

    Exp1[node] = expd1;

    for (auto& p: G[node]) {
        int n = p.first, cost = p.second;
        if (n == father) continue;

        expd1 -= (Exp1[n] + cost);

        ExpT[node] += 2 * (ExpT[n] + expd1) * P32(H[node], H[n]);

        expd1 += (Exp1[n] + cost);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    scanf("%d", &N);

    for (int i = 1; i < N; ++i) {
        int x, y, cost;
        scanf("%d%d%d", &x, &y, &cost);

        G[x].push_back({y, cost});
        G[y].push_back({x, cost});

        edges[i] = Edge(x, y, cost);
    }

    Dfs(1, 0);
    double ans = 0;

    cout << setprecision(10) << fixed;

    for (int i = 1; i < N; ++i) {
        int x = edges[i].x, y = edges[i].y, cost = edges[i].cost;

        if (Father[y] == x) swap(x, y);

        ans += 2 * cost * P32(N, H[x]);
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int edg, newcost;
        scanf("%d%d", &edg, &newcost);

        int x = edges[edg].x, y = edges[edg].y, oldcost = edges[edg].cost;
        int diff = oldcost - newcost;

        if (Father[y] == x) swap(x, y);

        ans -= 2 * diff * P32(N, H[x]);

        edges[edg].cost = newcost;

        cout << ans << '\n';
    }
}