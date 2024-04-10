#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 600010
#define P 998244353

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], Cnt = 0, n;

ll F[M][3];

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS(int x, int f = -1) {
    memset(F[x], 0, sizeof F[x]);
    F[x][0] = 0;
    F[x][1] = 0;
    F[x][2] = 1;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        DFS(Go[T], x);
        ll tmp0 = F[x][0], tmp1 = F[x][1], tmp2 = F[x][2];
        ll g0 = F[Go[T]][0], g1 = F[Go[T]][1], g2 = F[Go[T]][2];
        F[x][2] = (tmp2 * (g1 + g2)) % P;
        F[x][0] = (tmp0 * g1 + tmp2 * g1 + tmp0 * (g1 + g2)) % P;
        F[x][1] = (tmp2 * (g0 + g2) + tmp1 * g1 + tmp1 * (g1 + g2) + tmp0 * (g0 + g2)) % P;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x, y);
        addedge(y, x);
    }
    DFS(1);
    printf("%lld\n", ((F[1][1] + F[1][2]) % P + P) % P);
    return 0;
}