#include <algorithm>
#include <bitset>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int Nmax = 100005, Mod = 1000000007;

vector< pair<int, int> > G[Nmax];
int Val[Nmax];
int Nn;

int Col[Nmax];

bool NoSolution = false;

inline int mabs(const int x) {
    return x < 0 ? -x: x;
}

void AddEdge(const int x, const int y, const int type) {
    int left = max(mabs(y - x) + 1 - 2, 0);
    int right = min(x + y - 1, 2 * Nn - (x + y - 1));

    G[left].push_back(make_pair(right, type));
    G[right].push_back(make_pair(left, type));
}

void Dfs(const int node, const int col) {
    if (Col[node] != -1) {
        if (Col[node] != col)
            NoSolution = true;

        return;
    }
    Col[node] = col;

    for (const auto p: G[node]) {
        if (NoSolution)
            return;

        Dfs(p.first, col ^ p.second);
    }
}

void Solve(const int N, const vector< tuple<int, int, int> >& A) {
    Nn = N;

    for (const auto current: A) {
        int x, y, type;
        tie(x, y, type) = current;

        if (y % (N + 1) == 0)
            continue;

        y %= (N + 1);

        AddEdge(x, y, type);
    }

    int Ans = 1;

    memset(Col, -1, sizeof(Col));

    Dfs(0, 0);
    for (int i = 1; i <= N && !NoSolution; ++i) {
        if (Col[i] == -1) {
            Dfs(i, 0);
            Ans = Ans * 2 % Mod;
        }
    }

    if (NoSolution)
        printf("0\n");
    else
        printf("%d\n", Ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    int N, M;
    scanf("%d%d", &N, &M);

    vector< tuple<int, int, int> > A(M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        char type;

        scanf("%d %d %c\n", &x, &y, &type);
        if (type == 'o')
            A[i] = make_tuple(x, y, 1);
        else
            A[i] = make_tuple(x, y, 0);
    }

    Solve(N, A);
}