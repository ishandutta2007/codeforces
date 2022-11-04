#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define M 1000010

using namespace std;

int Head[M], Next[M], Go[M], Val[M], iscut[M], Len[M], Dep[M], Fa[400010][21], Cnt = 1, n, m, q;

int Head2[M], Next2[M], Go2[M], Val2[M], Cnt2 = 1;

int DFN[M], MIN[M], ins[M], Bel[M], vis[M], tim = 0, tt = 0;

vector <int> S;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void addedge2(int x, int y, int v) {
    Go2[++Cnt2] = y;
    Next2[Cnt2] = Head2[x];
    Head2[x] = Cnt2;
    Val2[Cnt2] = v;
}

void Tarjan(int x, int f = 0) {
    ins[x] = 1;
    S.push_back(x);
    DFN[x] = ++tim;
    MIN[x] = DFN[x];
    int las = x;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        if(!DFN[Go[T]]) {
            Tarjan(Go[T], x);
            MIN[x] = min(MIN[x], MIN[Go[T]]);
            if(DFN[x] <= MIN[Go[T]]) {
                tt++;
                for(; ;) {
                    if(S.back() == las) break;
                    addedge2(tt + n + 1, S.back(), 1);
                    addedge2(S.back(), tt + n + 1, 1);
                    //ins[S.back()] = 0;
                    S.pop_back();
                }
                addedge2(x, tt + n + 1, 1);
                addedge2(tt + n + 1, x, 1);
            } else las = S.back();
        } else if(ins[Go[T]]) MIN[x] = min(MIN[x], DFN[Go[T]]);
        /*if(MIN[Go[T]] > DFN[x]) {
            iscut[T] = (iscut[T ^ 1] = 1);
            addedge2(x, Go[T], 2);
            addedge2(Go[T], x, 2);
        }*/
    }
    ins[x] = 0;
    //if(DFN[x] == MIN[x]) S.pop_back();
}

void DFS2(int x, int dep = 1, int len = 0) {
    vis[x] = 1;
    Len[x] = len;
    Dep[x] = dep;
    for(int T = Head[x]; T; T = Next[T]) if(!vis[Go[T]]) {
        Fa[Go[T]][0] = x;
        DFS2(Go[T], dep + 1, len + Val[T]);
    }
}

int lca(int x, int y) {
    if(Dep[x] < Dep[y]) swap(x, y);
    int det = Dep[x] - Dep[y];
    for(int i = 18; i >= 0; i--)
        if((det >> i) & 1) x = Fa[x][i];
    if(x == y) return x;
    for(int i = 18; i >= 0; i--)
        if(Fa[x][i] != Fa[y][i]) x = Fa[x][i], y = Fa[y][i];
    return Fa[x][0];
}
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    for(int i = 1; i <= n; i++) if(!DFN[i]) Tarjan(i);
    memcpy(Head, Head2, sizeof Head);
    memcpy(Next, Next2, sizeof Next);
    memcpy(Go, Go2, sizeof Go);
    memcpy(Val, Val2, sizeof Val);
    for(int i = 1; i <= n + tt + 1; i++) if(!vis[i]) DFS2(i);
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= n + tt + 1; j++)
            Fa[j][i] = Fa[Fa[j][i - 1]][i - 1];
    for(int i = 1; i <= q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (Len[a] + Len[b] - 2 * Len[lca(a, b)]) / 2);
    }
    return 0;
}