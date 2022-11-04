#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <string>
#define M 1000010
#define int long long

using namespace std;

int n, k, m, Head[M], Next[M], Go[M], Val[M], Dep[M], F[M], Fa[M], L[M], R[M], C[M], tmpF[M], AnsCho[M], Cho[M], ans = 0, Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] =y ;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int getf(int x) {return F[x] == x ? x : F[x] = getf(F[x]);}

void DFS(int x, int f = 0, int d = 1) {
    Dep[x] = d;
    Fa[x] = f;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x, d + 1);
}

signed main() {
    scanf("%lld%lld%lld", &n, &k, &m);
    for(int i = 1; i <= n; i++) F[i] = i;
    for(int i = 1; i <= k; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        addedge(a, b);
        addedge(b, a);
        F[getf(a)] = getf(b);
    }
    for(int i = 1; i <= m; i++) scanf("%lld%lld%lld", &L[i], &R[i], &C[i]);
    for(int i = 1; i <= m; i++)
        if(getf(L[i]) != getf(R[i])) {
            F[getf(L[i])] = getf(R[i]);
            addedge(L[i], R[i]);
            addedge(R[i], L[i]);
            ans -= C[i];
            Cho[i] = 1;
        }
    DFS(1);
    memset(Val, 63, sizeof Val);
    for(int i = 1; i <= n; i++) F[i] = i;
    for(int i = 1; i <= m; i++) {
        int l = L[i], r = R[i], c = C[i];
        l = getf(l), r = getf(r);
        while(l != r) {
            if(Dep[l] < Dep[r]) swap(l, r);
            Val[l] = c;
            F[l] = Fa[l];
            l = getf(l);
        }
    }
    for(int i = 2; i <= n; i++) if(Val[i] > 2e9) {
        puts("-1");
        return 0;
    } else ans += Val[i];
    printf("%lld\n", ans);
    return 0;
}