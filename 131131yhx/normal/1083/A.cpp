#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define M 600010

using namespace std;

typedef long long ll;

int Head[M], Next[M], Go[M], Val[M], Cnt = 0, n;

ll F[M], ndV[M], ans = 0;

void addedge(int x, int y, int z) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    Val[Cnt] = z;
}

void DFS(int x, int f = 0) {
    vector <ll> V(0);
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        DFS(Go[T], x);
        V.push_back(F[Go[T]] - Val[T]);
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    ll a = max(0ll, (V.size() >= 1 ? V[0] : 0ll));
    ll b = max(0ll, (V.size() >= 2 ? V[1] : 0ll));
    F[x] = a + ndV[x];
    ans = max(ans, a + b + ndV[x]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &ndV[i]);
    for(int i = 1; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addedge(a, b, c);
        addedge(b, a, c);
    }
    DFS(1);
    printf("%lld\n", ans);
    return 0;
}