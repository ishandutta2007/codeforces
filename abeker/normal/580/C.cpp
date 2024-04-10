#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
int cat[MAXN];
vector <int> E[MAXN];
int sol;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", cat + i);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p, int len, bool ok) {
    if (!cat[x]) len = 0;
    len += cat[x];
    if (len > M) ok = 0;
    bool leaf = 1;
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) {
            dfs(E[x][i], x, len, ok);
            leaf = 0;
        }
    if (leaf) sol += ok;
}

int main() {
    load();
    dfs(1, 0, 0, 1);
    printf("%d\n", sol);
    return 0;
}