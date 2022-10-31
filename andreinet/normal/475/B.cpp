#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int Nmax = 25;

char A[Nmax], B[Nmax];
int N, M;

vector<int> G[Nmax * Nmax], Gt[Nmax * Nmax];
int Snodes[Nmax * Nmax];

bool used[Nmax * Nmax];

inline int getkey(int i, int j) {
    return (i - 1) * M + j;
}

void Dfs(const int node) {
    used[node] = 1;
    for (int p: G[node])
        if (!used[p])
            Dfs(p);

    Snodes[++Snodes[0]] = node;
}

void Dfs1(const int node) {
    used[node] = 1;
    for (int p: Gt[node])
        if (!used[p])
            Dfs1(p);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d %d\n", &N, &M);
    fgets(A + 1, Nmax, stdin);
    fgets(B + 1, Nmax, stdin);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (A[i] == '<' && j > 1)
                G[getkey(i, j)].push_back(getkey(i, j - 1));
            if (A[i] == '>' && j < M)
                G[getkey(i, j)].push_back(getkey(i, j + 1));

            if (B[j] == '^' && i > 1)
                G[getkey(i, j)].push_back(getkey(i - 1, j));
            if (B[j] == 'v' && i < N)
                G[getkey(i, j)].push_back(getkey(i + 1, j));
        }
    }

    for (int i = 1; i <= N * M; ++i) {
        for (int p: G[i])
            Gt[p].push_back(i);
    }

    for (int i = 1; i <= N * M; ++i)
        if (!used[i])
            Dfs(i);

    for (int i = 1; i <= N * M; ++i)
        used[i] = false;

    int ans = 0;
    for (int i = N * M; i; --i) {
        if (!used[Snodes[i]]) {
            Dfs1(Snodes[i]);
            ++ans;
        }
    }

    if (ans <= 1)
        printf("YES\n");
    else
        printf("NO\n");
}