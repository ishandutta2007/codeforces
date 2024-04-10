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
const int oo = 2000000001;
const int V = 200200;
struct N1{
    int v, c;
}a[V], b[V];
bool cmp1(N1 x, N1 y) {
    return x.v > y.v;
}

struct N2{
    int x, y, c;
}c[V];

bool cmp2(N2 x, N2 y) {
    if (x.x != y.x) return x.x < y.x;
    return x.y < y.y;
}

const int N = 1000010;

int n, m, P;

int fa(int x) {
    int lo = -1, up = n;
    while (lo + 1 < up) {
        int mid = (lo + up) / 2;
        if (a[mid].v >= x) lo = mid;
        else up = mid;
    }
    if (lo == -1) return oo;
    return a[lo].c;
}

int fb(int x) {
    int lo = -1, up = m;
    while (lo + 1 < up) {
        int mid = (lo + up) / 2;
        if (b[mid].v >= x) lo = mid;
        else up = mid;
    }
    if (lo == -1) return oo;
    return b[lo].c;
}

struct Node{
    int l, r;
    LL mi, lz;
}tr[4 * N];
LL cost[N + 10];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].lz = 0;
    if (l == r) {
        tr[id].mi = cost[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    tr[id].mi = max(tr[id * 2].mi, tr[id * 2 + 1].mi);
}

void down(int id) {
    tr[id * 2].lz += tr[id].lz;
    tr[id * 2].mi += tr[id].lz;
    tr[id * 2 + 1].lz += tr[id].lz;
    tr[id * 2 + 1].mi += tr[id].lz;
    tr[id].lz = 0;
}
void update(int id, int l, int r, int v) {
    if (tr[id].l == l && tr[id].r == r) {
        tr[id].mi += v;
        tr[id].lz += v;
        //if (tr[id].r <= 5) printf("%d %d %d %I64d %I64d\n", id, tr[id].l, tr[id].r, tr[id].mi, tr[id].lz);
        return;
    }
    down(id);
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) update(id * 2, l, r, v);
    else if (l > mid) update(id * 2 + 1, l, r, v);
    else {
        update(id * 2, l, mid, v);
        update(id * 2 + 1, mid + 1, r, v);
    }
    tr[id].mi = max(tr[id * 2].mi, tr[id * 2 + 1].mi);
    //if (tr[id].r <= 5) printf("%d %d %d %I64d %I64d\n", id, tr[id].l, tr[id].r, tr[id].mi, tr[id].lz);
}

int main() {
    while (~scanf("%d%d%d", &n, &m, &P)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].v, &a[i].c);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &b[i].v, &b[i].c);
        }
        for (int i = 0; i < P; ++i) {
            scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].c);
        }
        sort(a, a + n, cmp1);
        for (int i = 1; i < n; ++i) a[i].c = min(a[i].c, a[i - 1].c);
        sort(b, b + m, cmp1);
        for (int i = 1; i < m; ++i) b[i].c = min(b[i].c, b[i - 1].c);
        sort(c, c + P, cmp2);
        LL ans = -oo;
        ans = -a[n - 1].c - b[m - 1].c;
        for (int i = 1; i <= N; ++i) cost[i] = -fb(i);
        init(1, 1, N);
        for (int i = 0; i < P; ++i) {
            update(1, c[i].y + 1, N, c[i].c);
            //printf("U %d %d\n", c[i].y + 1, c[i].c);
            int ca = fa(c[i].x + 1);
            LL tmp = tr[1].mi - ca;
            //printf("I %d %d %d %d %I64d\n", i, c[i].x, c[i].y, ca, tr[1].mi);
            ans = max(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2 3 3
2 3
4 7
2 4
3 2
5 11
1 2 4
2 1 6
3 4 6
*/