#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#define M 200010
#define int long long
#define P 998244353

using namespace std;

typedef long long ll;

struct node {
    int a, b, c;
    node() {}
    node(int _1, int _2, int _3) {a = _1, b = _2, c = _3;}
    bool operator < (const node& X) const {return c < X.c;}
};
int Head[M], Next[M], Go[M], Val[M], Cnt = 0;
int n, m, k;

node E[M];

int Fa[M];

void addedge(int x, int y, int z) {
    Go[++Cnt] = y;
    Next[Cnt] = Head[x];
    Head[x] = Cnt;
    Val[Cnt] = z;
}

int getf(int x) {return Fa[x] == x ? x : Fa[x] = getf(Fa[x]);}

int X[M];

int merge(int x, int y) {
    if(getf(x) != getf(y)) {
        Fa[getf(x)] = getf(y);
        return 1;
    } else return 0;
}

int ans = 0;

bool used[M];

int DFS(int x, int f = 0) {
    int o = 0;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f) {
        if(DFS(Go[T], x)) o = 1, ans = max(ans, Val[T]);
    }
    return o | used[x];
}

signed main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 1; i <= k; i++) scanf("%lld", &X[i]), used[X[i]] = 1;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        E[i] = node(a, b, c);
    }
    for(int i = 1; i <= n; i++) Fa[i] = i;
    sort(E + 1, E + m + 1);
    for(int i = 1; i <= m; i++) {
        int a = E[i].a, b = E[i].b, c = E[i].c;
        if(merge(a, b)) addedge(a, b, c), addedge(b, a, c);
    }
    DFS(X[1]);
    for(int i = 1; i <= k; i++) printf("%lld ", ans);
    putchar('\n');
    return 0;
}