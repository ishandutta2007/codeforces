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
const int ooo = 1e9;
const LL oo = (LL) ooo * ooo;
const int V = 300100;

struct Node{
    int l, r;
    LL lz, mx;
}tr[V * 4];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].lz = tr[id].mx = -oo;
    if (l == r) return;
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
}

void update(int id, int l, int r, LL mx) {
    //printf("U %d %d %d %d %d %lld\n", id, l, r, tr[id].l, tr[id].r, mx);
    if (l > r) return;
    if (tr[id].l == l && tr[id].r == r) {
        tr[id].lz = max(tr[id].lz, mx);
        tr[id].mx = max(tr[id].mx, mx);
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    mx = max(mx, tr[id].lz);
    if (r <= mid) update(id * 2, l, r, mx);
    else if (l > mid) update(id * 2 + 1, l, r, mx);
    else {
        update(id * 2, l, mid, mx);
        update(id * 2 + 1, mid + 1, r, mx);
    }
    tr[id].mx = max(tr[id * 2].mx, tr[id * 2 + 1].mx);
}

LL read(int id, int l, int r) {
    if (l > r) return -oo;
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].mx;
    }
    LL ans = tr[id].lz;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) ans = max(ans, read(id * 2, l, r));
    else if (l > mid) ans = max(ans, read(id * 2 + 1, l, r));
    else {
        ans = max(ans, read(id * 2, l, mid));
        ans = max(ans, read(id * 2 + 1, mid + 1, r));
    }
    return ans;
}

int n, h[V], l[V], r[V], a[V];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
        h[0] = h[n + 1] = 0;
        for (int i = 1; i <= n; ++i) {
            while (l[i] != 0 && h[l[i]] > h[i]) l[i] = l[l[i]];
        }
        for (int i = n; i > 0; --i) {
            while (r[i] != n + 1 && h[r[i]] > h[i]) r[i] = r[r[i]];
        }
        init(1, 0, n);
        update(1, 0, 0, 0);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            LL mx = read(1, l[i], i - 1);
            //printf("R %d %d %d %lld\n", i, l[i], r[i], mx);
            update(1, i, r[i] - 1, mx + a[i]);
        }
        printf("%I64d\n", read(1, n, n));
    }
    return 0;
}

/*
5
1 2 3 5 4
1 5 3 2 4

5
1 4 3 2 5
-3 4 -10 2 7

2
2 1
-2 -3

10
4 7 3 2 5 1 9 10 6 8
-4 40 -46 -8 -16 4 -10 41 12 3

*/