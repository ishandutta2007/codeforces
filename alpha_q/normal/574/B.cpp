#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = 4005;
const int inf = (int) 1e9;

struct edge {
    int u, v;
    edge (int _u, int _v) {u = _u; v = _v;}
    edge () {}
} E[N];

int D[N], A[N][N], n, m, i, a, b, c, Ret = inf;

int main () {
    scanf("%d %d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        A[a][b] = A[b][a] = 1;
        ++D[a], ++D[b];
        E[i] = edge(a, b);
    }

    for (i = 1; i <= m; i++) {
        a = E[i].u, b = E[i].v;
        for (c = 1; c <= n; c++)
            if (A[a][c] && A[b][c])
                Ret = min(Ret, D[a] + D[b] + D[c]);
    }

    printf("%d\n", Ret == inf ? -1 : Ret - 6);
    return 0;
}