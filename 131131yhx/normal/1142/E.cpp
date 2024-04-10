#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define PII pair <int, int>
#define x first
#define y second
#define M 200010

using namespace std;

int n, m, Head[M], Next[M], Go[M], vis[M], Deg[M], inst[M], Cnt = 0;

vector <int> G[M];

set <PII> ovo;

int Query(int x, int y) { // who ru
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}

void DFS(int x, int bel) {
    inst[x] = 1, vis[x] = 1;
    for(int T = Head[x]; T; T = Next[T]) {
        if(!vis[Go[T]]) DFS(Go[T], bel);
        if(!inst[Go[T]])G[x].push_back(Go[T]), Deg[Go[T]]++;
    }
    inst[x] = 0;
}

int main() {
    scanf("%d%d", &n, &m);
    if(n == 1) {
        puts("! 1");
        fflush(stdout);
        return 0;
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Go[++Cnt] = b;
        Next[Cnt] = Head[a];
        Head[a] = Cnt;
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i]) DFS(i, i);
    vector <int> V(0);
    for(int i = 1; i <= n; i++) if(!Deg[i]) V.push_back(i);
    int v = V[0];
    for(int i = 1; i < V.size(); i++) {
        int x = V[i];
        int o = Query(x, v);
        if(o == 1) swap(v, x);
        for(int j = 0; j < G[x].size(); j++)
            if(!--Deg[G[x][j]]) V.push_back(G[x][j]);
    }
    printf("! %d\n", v);
    fflush(stdout);
    return 0;
}