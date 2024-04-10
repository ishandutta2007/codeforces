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

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int ooo = 1000000000;
const LL oo = (LL) ooo * ooo;
const int P = 1000000007;
const int V = 200100;

struct Node {
    int l, r;
    LL mi, lazy;
}tr[4 * V];

LL s[V];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].lazy = 0;
    if (l == r) {
        tr[id].mi = s[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    tr[id].mi = min(tr[id * 2].mi, tr[id * 2 + 1].mi);
}

void push(int id) {
    tr[id * 2].lazy += tr[id].lazy;
    tr[id * 2].mi += tr[id].lazy;
    tr[id * 2 + 1].lazy += tr[id].lazy;
    tr[id * 2 + 1].mi += tr[id].lazy;
    tr[id].lazy = 0;
}

void update(int id, int l, int r, int v) {
    if (tr[id].l == l &&tr[id].r == r) {
        tr[id].mi += v;
        tr[id].lazy += v;
        return;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    push(id);
    if (r <= mid) update(id * 2, l, r, v);
    else if (l > mid) update(id * 2 + 1, l, r, v);
    else {
        update(id * 2, l, mid, v);
        update(id * 2 + 1, mid + 1, r, v);
    }
    tr[id].mi = min(tr[id * 2].mi, tr[id * 2 + 1].mi);
}


int a[V], p[V], b[V], n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) b[p[i]] = i;
        s[0] = 0;
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
        //for (int i = 1; i < n; ++i) printf("%I64d ", s[i]); puts("");
        init(1, 1, n - 1);
        LL ans = oo;
        LL tn = 0;
        for (int i = 0; i <= n; ++i) {
            if (i != 0) {
                if (b[i] != n) update(1, b[i], n - 1, -2 * a[b[i]]);
                //printf("UP %d %d\n", b[i], -2 * a[b[i]]);
                tn += a[b[i]];
            }
            LL tmp = tn + tr[1].mi;
            //printf("TMP %d %I64d %I64d\n", i, tmp, tn);
            ans = min(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3
3 1 2
7 1 4

4
2 4 1 3
5 9 8 3

6
3 5 1 6 2 4
9 1 9 9 1 9

*/