#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define M 200010

using namespace std;

int n, Head[M], Next[M], Go[M], vis[M], Fa[M], Dep[M], Cnt = 0, nw, mx = 0, lstim[M], nwtim = 1;

struct node {
    int a, b, tim;
    node() {}
    node(int _1, int _2, int _3) {a = _1, b = _2, tim = _3;}
    bool operator < (const node& X) const {
        return a < X.a;
    }
};
priority_queue <node> Q;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS(int x) {
    memset(vis, 0, sizeof vis);
    vector <int> V;
    V.clear();
    V.push_back(x);
    vis[x] = 1;
    Dep[x] = 0;
    for(int i = 0; i < V.size(); i++)
        for(int T = Head[V[i]]; T; T = Next[T])
            if(!vis[Go[T]]) {
                if(Dep[V[i]] >= mx) {
                    mx = Dep[V[i]] + 1;
                    nw = Go[T];
                }
                Dep[Go[T]] = Dep[V[i]] + 1;
                V.push_back(Go[T]);
                Fa[Go[T]] = V[i];
                vis[Go[T]] = 1;
            }
}

void DFSx(int x, int f = -1, int dep = 0) {
    if(dep) {
        lstim[x] = nwtim;
        Q.push(node(dep, x, nwtim));
    }
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f && !vis[Go[T]]) DFSx(Go[T], x, dep + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    printf("1 ");
    mx = 0;
    DFS(1);
    mx = 0;
    int a = nw;
    DFS(nw);
    int b = nw;
    memset(vis, 0, sizeof vis);
    memset(Dep, -1, sizeof Dep);
    vector <int> V;
    V.clear();
    for(int i = b; i != a; i = Fa[i]) vis[i] = 1, Dep[i] = 0, V.push_back(i);
    vis[a] = 1, Dep[a] = 0, V.push_back(a);
    for(int i = 0; i < V.size(); i++)
        for(int T = Head[V[i]]; T; T = Next[T])
            if(Dep[Go[T]] == -1) {
                Dep[Go[T]] = Dep[V[i]] + 1;
                Q.push(node(Dep[Go[T]], Go[T], nwtim));
                V.push_back(Go[T]);
                Fa[Go[T]] = V[i];
                lstim[Go[T]] = nwtim;
            }
    printf("%d ", mx + 1);
    int ans = mx + 1;
    for(int i = 3; i <= n; i++) {
        while(!Q.empty() && (vis[Q.top().b] || Q.top().tim != lstim[Q.top().b])) Q.pop();
        if(Q.empty()) {
            for(int j = i; j <= n; j++) printf("%d ", n);
            return 0;
        }
        V.clear();
        printf("%d ", (ans += Q.top().a));
        for(int j = Q.top().b; !vis[j]; j = Fa[j]) V.push_back(j), vis[j] = 1, lstim[j] = -1;
        nwtim++;
        for(int j = 0; j < V.size(); j++) DFSx(V[j]);
    }
    return 0;
}