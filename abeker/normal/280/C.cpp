#include <cstdio>
#include <vector>
using namespace std;

typedef long double ld;

const int MAXN = 100005;

int N;
vector <int> E[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

ld dfs(int x, int p, int d) {
    ld res = 1. / d;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) res += dfs(E[x][i], x, d + 1);
    return res;
}

int main() {
    load();
    printf("%.20lf\n", (double)dfs(1, 0, 1));
    return 0;
}