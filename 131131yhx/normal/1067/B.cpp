#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>

#define M 200010

using namespace std;

int n, k, Head[M], Next[M], Go[M], D[M], Dis[M], Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    D[x]++;
}

void DFS(int x, int f = 0) {
    int flag = 0;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        flag++;
        DFS(Go[T], x);
        if(Dis[Go[T]] != Dis[x] - 1) {
            puts("No");
            exit(0);
        }
    }
    if(flag == 2 || flag == 1) {
        puts("No");
        exit(0);
    }
    if(!flag && Dis[x]) {
        puts("No");
        exit(0);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    vector <int> V;
    V.clear();
    for(int i = 1; i <= n; i++) if(D[i] == 1) V.push_back(i);
    for(int i = 0; i < V.size(); i++) {
        for(int T = Head[V[i]]; T; T = Next[T])
            if(--D[Go[T]] == 1) V.push_back(Go[T]), Dis[Go[T]] = Dis[V[i]] + 1;
    }
    if(V.empty()) {
        puts("No");
        return 0;
    }
    if(Dis[V.back()] != k) {
        puts("No");
        return 0;
    }
    DFS(V.back());
    puts("Yes");
    return 0;
}