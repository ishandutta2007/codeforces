#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define int long long
#define P 1000000007
#define M 200010

using namespace std;

typedef long long ll;

int n, k, Head[M], Next[M], Go[M], _2[M], Sz[M], Cnt = 0;

ll F[100010][205], tmp[205], ans = 0, Ans[205], Fac[205], G[222][222];// D2 : Es

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS(int x, int f = 0) {
    Sz[x] = 1;
    F[x][0] = 1;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        DFS(Go[T], x);
        //Sz[x] += Sz[Go[T]];
        //F[x][1] = (F[x][1] + (_2[Sz[Go[T]]] - 1)) % P;
        for(int i = min(Sz[Go[T]], k); i >= 2; i--)
            F[Go[T]][i] = (F[Go[T]][i] + F[Go[T]][i - 1]) % P;
        F[Go[T]][1] = (F[Go[T]][1] + _2[Sz[Go[T]]] - 1) % P;
        F[Go[T]][0] = 0;
        memset(tmp, 0, sizeof tmp);
        // at least 1
        for(int i = min(Sz[Go[T]], k); i >= 1; i--)
            for(int j = 0; j < Sz[x] && j <= k; j++)
                tmp[i + j] = (tmp[i + j] + F[Go[T]][i] * F[x][j]) % P;
        // no
        for(int i = 0; i < Sz[x] && i <= k; i++)
            tmp[i] = (tmp[i] + F[x][i] * _2[Sz[Go[T]]]) % P;
        for(int i = 0; i <= k; i++) F[x][i] = tmp[i];
        Sz[x] += Sz[Go[T]];
    }
    for(int i = 0; i <= k; i++) F[x][i] = F[x][i] * 2 % P;
    if(x != 1) {
        Ans[1] = (Ans[1] - (_2[Sz[x]] - 1)) % P; // leaf
        for(int j = 2; j <= k; j++) Ans[j] = (Ans[j] - F[x][j - 1]) % P;// else
    }
}

signed main() {
    for(int i = 0; i < M; i++) _2[i] = !i ? 1 : _2[i - 1] * 2 % P;
    scanf("%lld%lld", &n, &k);
    G[0][0] = 1;
    for(int i = 0; i <= k; i++) Fac[i] = !i ? 1 : Fac[i - 1] * i % P;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= i; j++)
            G[i][j] = (G[i - 1][j - 1] + G[i - 1][j] * j) % P;
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    DFS(1);
    for(int i = 1; i <= k; i++) Ans[i] = (Ans[i] + F[1][i]) % P;
    ans = 0;
    for(int i = 1; i <= k; i++) ans = (ans + G[k][i] * Ans[i] % P * Fac[i]) % P;
    printf("%lld\n", ((ans) % P + P) % P);
    return 0;
}