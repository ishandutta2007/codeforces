#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int N, D;
int a[MAXN];
int x[MAXN], y[MAXN];
int dist[MAXN][MAXN];

void load() {
    scanf("%d%d", &N, &D);
    for (int i = 1; i < N - 1; i++)
        scanf("%d", a + i);
    for (int i = 0; i < N; i++)
        scanf("%d%d", x + i, y + i);
}

int solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = D * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j];
    
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (i != j && j != k && k != i)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    return dist[0][N - 1];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}