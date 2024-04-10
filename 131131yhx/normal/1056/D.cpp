#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define M 200010

using namespace std;

int n, Head[M], Next[M], Go[M], Sz[M], O[M], tmp[M], F[M], D[M], _0 = 0, Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS(int x) {
    Sz[x] = 0;
    int mx = 0;
    if(!Head[x]) {
        Sz[x] = 1;
        _0++;
        O[x] = -1;
        return;
    }
    for(int T = Head[x]; T; T = Next[T]) {
        DFS(Go[T]);
        mx = max(mx, Sz[Go[T]]);
        Sz[x] += Sz[Go[T]];
    }
    O[x] = Sz[x] - mx;
}

bool cmp(int x, int y) {return O[x] < O[y];}

struct node {
    int x;
    node() {}
    node(int _1) {x = _1;}
    bool operator < (const node& X) const {return Sz[x] > Sz[X.x];}
};

int main() {
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        F[i] = x;
        D[x]++;
        addedge(x, i);
    }
    DFS(1);
    for(int i = 1; i <= n; i++) tmp[i] = i;
    sort(tmp + 1, tmp + n + 1, cmp);
    priority_queue <node> Q;
    while(!Q.empty()) Q.pop();
    for(int i = 1; i <= n; i++) if(!Head[i]) Q.push(node(i));
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        int x = Q.top().x;
        Q.pop();
        ans = max(ans, Sz[x]);
        printf("%d ", ans);
        if(!--D[F[x]]) Q.push(node(F[x]));
    }
    return 0;
}