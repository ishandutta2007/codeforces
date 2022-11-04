#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <iostream>
#include <ctime>
#define M 400010

using namespace std;

int n, Head[M], Next[M], Go[M], A[M], Fa[M], D[M], Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

void DFS(int x = 1) {
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != Fa[x]) Fa[Go[T]] = x, DFS(Go[T]);
}

signed main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
        D[a]++, D[b]++;
    }
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if(A[1] != 1) {
        puts("No");
        return 0;
    }
    DFS(1);
    int l = 1;
    for(int i = 2; i <= n; i++) {
        if(Fa[A[i]] != A[l]) {
            puts("No");
            return 0;
        }
        D[A[l]]--;
        D[A[i]]--;
        while(D[A[l]] == 0 && l <= n) l++;
    }
    puts("Yes");
    return 0;
}