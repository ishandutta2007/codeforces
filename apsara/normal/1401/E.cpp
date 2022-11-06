#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 1000100;

int N = 1000000;
int tr[V];

void add(int k, int v) {
    if (k <= 0) return;
    while (k <= N) {
        tr[k] += v;
        k += k & -k;
    }
}

int read(int k) {
    int res = 0;
    while (k > 0) {
        res += tr[k];
        k -= k & -k;
    }
    return res;
}

struct Node{
    int type, v, l, r;
}e[V];

bool cmp(Node x, Node y) {
    if (x.v != y.v) return x.v < y.v;
    return x.type < y.type;
}
int K;
void adde(int type, int v, int l, int r) {
    e[K].type = type;
    e[K].v = v;
    e[K].l = l;
    e[K].r = r;
    K++;
}

struct Point {
    int v, l, r;
}a[V], b[V];

int n, m;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i].v, &a[i].l, &a[i].r);
        for (int i = 0; i < m; ++i) scanf("%d%d%d", &b[i].v, &b[i].l, &b[i].r);
        LL ans = 1;
        for (int i = 0; i < n; ++i) if (a[i].l == 0 && a[i].r == N) ++ans;
        for (int i = 0; i < m; ++i) if (b[i].l == 0 && b[i].r == N) ++ans;
        //printf("%I64d\n", ans);

        memset(tr, 0, sizeof(tr));
        K = 0;
        for (int i = 0; i < n; ++i) {
            adde(-1, a[i].v, a[i].l, a[i].r);
        }
        for (int i = 0; i < m; ++i) {
            if (b[i].l == 0) adde(1, b[i].r, b[i].v, 0);
        }
        sort(e, e + K, cmp);
        for (int i = 0; i < K; ++i) {
            //printf("E1 %d %d %d %d\n", e[i].type, e[i].v, e[i].l, e[i].r);
            if (e[i].type == -1) {
                add(max(e[i].l, 1), 1);
                add(e[i].r + 1, -1);
            } else {
                ans += read(e[i].l);
            }
        }
        //printf("%I64d\n", ans);

        memset(tr, 0, sizeof(tr));
        K = 0;
        for (int i = 0; i < n; ++i) {
            adde(-1, N - a[i].v, a[i].l, a[i].r);
        }
        for (int i = 0; i < m; ++i) {
            if (b[i].r == N && b[i].l != 0) adde(1, N - b[i].l, b[i].v, 0);
        }
        sort(e, e + K, cmp);
        for (int i = 0; i < K; ++i) {
            //printf("E2 %d %d %d %d\n", e[i].type, e[i].v, e[i].l, e[i].r);
            if (e[i].type == -1) {
                add(max(e[i].l, 1), 1);
                add(e[i].r + 1, -1);
            } else {
                ans += read(e[i].l);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3 3
2 3 1000000
4 0 4
3 0 1000000
4 0 1
2 0 5
3 1 1000000

*/