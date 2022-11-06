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
const int N = 18;
int a[1 << N];
int b[N + 2];

struct Node {
    int l, r, lv;
    LL s;
}tr[1 << (N + 2)];

void init(int id, int lv, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].lv = lv;
    if (l == r) {
        tr[id].s = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, lv - 1, l, mid);
    init(id * 2 + 1, lv - 1, mid + 1, r);
    tr[id].s = tr[id * 2].s + tr[id * 2 + 1].s;
}

void update(int id, int pos, int v) {
    //printf("U %d %d %d %d %d %d %I64d\n", id, pos, v, tr[id].l, tr[id].r, tr[id].lv, tr[id].s);
    if (tr[id].l == tr[id].r) {
        tr[id].s = v;
        return;
    }
    if (b[tr[id].lv]) pos = tr[id].r - (pos - tr[id].l);
    int mid = (tr[id].l + tr[id].r) / 2;
    if (pos <= mid) update(id * 2, pos, v);
    else update(id * 2 + 1, pos, v);
    tr[id].s = tr[id * 2].s + tr[id * 2 + 1].s;
}

LL read(int id, int l, int r) {
    //printf("R %d %d %d %d %d %d %I64d\n", id, l, r, tr[id].l, tr[id].r, tr[id].lv, tr[id].s);
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].s;
    }
    int _l = l, _r = r;
    if (b[tr[id].lv]) {
        _l = tr[id].r - (r - tr[id].l);
        _r = tr[id].r - (l - tr[id].l);
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    if (_r <= mid) return read(id * 2, _l, _r);
    else if (_l > mid) return read(id * 2 + 1, _l, _r);
    else {
        LL res = 0;
        res += read(id * 2, _l, mid);
        res += read(id * 2 + 1, mid + 1, _r);
        return res;
    }
}

int n, Q, type, x, y;

int main() {
    while (~scanf("%d%d", &n, &Q)) {
        for (int i = 1; i <= (1 << n); ++i) scanf("%d", &a[i]);
        init(1, n, 1, 1 << n);
        memset(b, 0, sizeof(b));
        while (Q--) {
            scanf("%d", &type);
            if (type == 1) {
                scanf("%d%d", &x, &y);
                update(1, x, y);
            } else if (type == 2) {
                scanf("%d", &x);
                b[x] ^= 1;
            } else if (type == 3) {
                scanf("%d", &x);
                b[x] ^= 1;
                b[x + 1] ^= 1;
            } else if (type == 4) {
                scanf("%d%d", &x, &y);
                LL ans = read(1, x, y);
                printf("%I64d\n", ans);
            }
            //for (int i = 0; i <= n; ++i) printf("%d ", b[i]);puts("B");
        }
    }
    return 0;
}

/*
2 3
7 4 9 9
1 2 8
3 1
4 2 4

3 8
7 0 8 8 7 1 5 2
4 3 7
2 1
3 2
4 1 6
2 3
1 5 16
4 8 8
3 0
*/