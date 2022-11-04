#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define M 400010

using namespace std;

int n, L[M], R[M], D[M], Head[M], Next[M], Go[M], Cnt = 0;

double Val[M], O[M];

vector <int> big[M];

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%lf", &Val[i]);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &L[i], &R[i]);
        D[L[i]]++;
        D[R[i]]++;
        addedge(L[i], R[i]);
        addedge(R[i], L[i]);
    }
    for(int i = 0; i < n; i++) if(D[i] * D[i] > n) {
        for(int T = Head[i]; T; T = Next[T])
            big[Go[T]].push_back(i);
    }
    int q;
    scanf("%d", &q);
    double ans = 1;
    for(int j = 0; j < n; j++) {
        ans += (D[j] - 1) * Val[j];
    }
    for(int j = 1; j < n; j++)
        ans -= Val[L[j]] * Val[R[j]];
    for(int i = 0; i < n; i++) if(D[i] * D[i] <= n)
        for(int T = Head[i]; T; T = Next[T])
            O[Go[T]] -= Val[i];
    for(int i = 1; i <= q; i++) {
        int a;
        double b;
        scanf("%d%lf", &a, &b);
        if(D[a] * D[a] <= n) {
            for(int T = Head[a]; T; T = Next[T])
                O[Go[T]] += Val[a];
        }
        for(int j = 0; j < big[a].size(); j++)
            ans += Val[a] * Val[big[a][j]];
        ans -= O[a] * Val[a];
        ans -= (D[a] - 1) * Val[a];
        Val[a] = b;
        ans += O[a] * Val[a];
        ans += (D[a] - 1) * Val[a];
        if(D[a] * D[a] <= n) {
            for(int T = Head[a]; T; T = Next[T])
                O[Go[T]] -= Val[a];
        }
        for(int j = 0; j < big[a].size(); j++)
            ans -= Val[a] * Val[big[a][j]];
        printf("%.5lf\n", ans);
    }
    return 0;
}