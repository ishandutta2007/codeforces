#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define M 200010

using namespace std;

int n, Head[M], Next[M], Go[M], L[M], R[M], D[M], Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    D[x]++;
}

int end(int x) {
    puts(x ? "Yes" : "No");
    exit(0);
}

int DFS(int x, int f = 0, int dep = 0) {
    int A[5] = {0, 0, 0, 0, 0};
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        A[DFS(Go[T], x, dep)]++;
        if(A[4]) {
            if(dep == 1) end(0);
            DFS(Go[T], 0, 1), end(1);
        }
    }
    if(D[x] <= 2 && !A[3] && !A[2]) return 1;
    if(D[x] <= 3 && !A[3] && !A[2]) return 2;
    if(A[3] <= 1) return 3;
    if(A[3] <= 2) return 4;
    end(0);
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
    end(1);
}