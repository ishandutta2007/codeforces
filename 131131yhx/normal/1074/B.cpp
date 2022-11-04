#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>
#define M 10010

using namespace std;

int n, Head[M], Next[M], Go[M], Cnt = 0;

void addedge(int x, int y) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
}

int ask(int op, int x) {
    if(op == 0) printf("A %d\n", x); else printf("B %d\n", x);
    fflush(stdout);
    int v;
    scanf("%d", &v);
    return v;
}

int tmpans;

bool B[M];

void DFS(int x, int f = 0) {
    if(B[x]) {
        tmpans = x;
        return;
    }
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) DFS(Go[T], x);
}

void Solve() {
    Cnt = 0;
    memset(Head, 0, sizeof Head);
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addedge(a, b);
        addedge(b, a);
    }
    memset(B, 0, sizeof B);
    int k1, k2;
    scanf("%d", &k1);
    vector <int> V1(k1);
    for(int i = 0; i < k1; i++) scanf("%d", &V1[i]), B[V1[i]] = 1;
    scanf("%d", &k2);
    vector <int> V2(k2);
    for(int i = 0; i < k2; i++) scanf("%d", &V2[i]);
    int tmp = ask(1, V2[0]);
    if(B[tmp]) {
        printf("C %d\n", tmp);
        fflush(stdout);
        return;
    }
    DFS(tmp);
    int o = ask(0, tmpans);
    for(int i = 0; i < k2; i++) if(V2[i] == o) {
        printf("C %d\n", tmpans);
        fflush(stdout);
        return;
    }
    puts("C -1");
    fflush(stdout);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) Solve();
}