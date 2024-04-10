#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define M 800010

using namespace std;

int n, m, h, X[M], Head[M], Next[M], Go[M], Cnt = 0;

int DFN[M], MIN[M], vis[M], D[M], ins[M], S[M], Sz[M], mn = 1234567, v, tim = 0, ttim = 0;

vector <int> V, Ans;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    D[x]++;
}

void tarjan(int x) {
    DFN[x] = (MIN[x] = ++tim);
    ins[x] = 1;
    V.push_back(x);
    for(int T = Head[x]; T; T = Next[T]) {
        if(!DFN[Go[T]]) tarjan(Go[T]);
        if(ins[Go[T]]) MIN[x] = min(MIN[x], DFN[Go[T]]);
        else MIN[x] = min(MIN[x], MIN[Go[T]]);
    }
    if(MIN[x] == DFN[x]) {
        int t = (int) V.size() - 1;
        while(V[t] != x) t--;
        ttim++;
        Sz[ttim] = V.size() - t;
        int flag = (t == V.size() - 1);
        for(int i = (int) V.size() - 1; i >= t; i--) {
            vis[V[i]] = ttim;
            ins[V[i]] = 0;
            V.pop_back();
        }
    }
    ins[x] = 0;
}

int main() {
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if(((X[x] - X[y] + h) % h == 1)) addedge(y, x);
        if(((X[y] - X[x] + h) % h == 1)) addedge(x, y);
    }
    for(int i = 1; i <= n; i++) if(!DFN[i]) tarjan(i);
    for(int i = 1; i <= n; i++)
        for(int T = Head[i]; T; T = Next[T]) if(vis[Go[T]] != vis[i]) Sz[vis[i]] = 2333333;
    for(int i = 1; i <= ttim; i++) if(Sz[i] < mn) {
        mn = Sz[i];
        v = i;
    }
    for(int i = 1; i <= n; i++) if(vis[i] == v) Ans.push_back(i);
    printf("%d\n", Ans.size());
    for(int i = 0; i < Ans.size(); i++) printf("%d ", Ans[i]);
    return 0;
}