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
const int oo = 1000000000;
const int P = 1000000007;

const int V = 300100;

struct Node{
    int l, r, lz;
    PII mx;
}tr[4 * V];
int a[V], b[V];

void pull(int id) {
    if(tr[id * 2].mx.se > tr[id * 2 + 1].mx.se) tr[id].mx = MP(tr[id * 2].mx.fi, tr[id * 2].mx.se);
    else tr[id].mx = MP(tr[id * 2 + 1].mx.fi, tr[id * 2 + 1].mx.se);
}

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    tr[id].lz = 0;
    if (l == r) {
        tr[id].mx = MP(l, b[l]);
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 +1, mid + 1, r);
    pull(id);
    //tr[id].mx = max(tr[id * 2].mx, tr[id * 2 + 1].mx);
}

void push(int id) {
    tr[id * 2].mx.se += tr[id].lz;
    tr[id * 2].lz += tr[id].lz;
    tr[id * 2 + 1].mx.se += tr[id].lz;
    tr[id * 2 + 1].lz += tr[id].lz;
    tr[id].lz = 0;
}

void update(int id, int l, int r, int v) {
    if (tr[id].l == l && tr[id].r == r) {
        tr[id].lz += v;
        tr[id].mx.se += v;
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
    pull(id);
    //tr[id].mx = max(tr[id * 2].mx + tr[id * 2 + 1].mx);
}

PII read(int id, int l, int r) {
    if (tr[id].l == l && tr[id].r == r) {
        return tr[id].mx;
    }
    int mid = (tr[id].l + tr[id].r) / 2;
    push(id);
    if (r <= mid) return read(id * 2, l, r);
    else if (l > mid) return read(id * 2 + 1, l, r);
    else {
        PII a = read(id * 2, l, mid);
        PII b = read(id * 2 + 1, mid + 1, r);
        if (a.se > b.se) return a;
        else return b;
    }
}

int T[V], N;

void U(int k, int v) {
    while (k <= N) {
        T[k] += v;
        k += k & -k;
    }
}
int R(int k) {
    int res = 0;
    while (k) {
        res += T[k];
        k -= k & -k;
    }
    return res;
}


int n;

void D(int i) {
    printf("D %d\n", i);
    update(1, i, i, -oo);
    if (i + 1 <= n) update(1, i + 1, n, 1);
}

void del(int i) {
    printf("DEL %d\n", i);
    PII mx_i = read(1, i, i);
    if (mx_i.se <= 0 && mx_i.se > -oo) {
        D(i);
    }
    while (tr[1].mx.se > 0) {
        int id = tr[1].mx.fi;
        D(id);
    }
}

void A(int i) {
   // printf("A %d\n", i);
    U(i, 1);
    update(1, i, i, -oo);
    if (i + 1 <= n) update(1, i + 1, n, 1);
}

void add(int i) {
    //printf("add %d\n", i);
    if(read(1, i, i).se >= 0) A(i);
    while (true) {
        PII mx = read(1, i, n);
        if (mx.se < 0) break;
        int id = mx.fi;
        A(id);
    }
}

vector<PII> g[V];
int ans[V];
int Q, x, y;
int main() {
    while (~scanf("%d%d", &n, &Q)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) b[i] = a[i] - i;
        for (int i = 1; i <= n; ++i) if(b[i] > 0) b[i] = -oo;
        //for (int i = 1; i <= n; ++i) printf("%d ", b[i]); puts("");
        for (int i = 1; i <= n; ++i) T[i] = 0;
        N = n;
        init(1, 1, n);
        for (int i = 0; i <= n; ++i) g[i].clear();
        for (int i = 0; i < Q; ++i) {
            scanf("%d%d", &x, &y);
            g[x].PB(MP(y, i));
        }
        for (int i = n; i >= 0; --i) {
            for (int j = 0; j < g[i].size(); ++j) {
                int k = g[i][j].se;
                //printf("R %d %d\n", k, n - g[i][j].fi);
                ans[k] = R(n - g[i][j].fi);
            }
            if (i > 0) add(i);
        }
        for (int i = 0; i < Q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}

/*
13 5
2 2 3 9 5 4 6 5 7 8 3 11 13
3 1
0 0
2 4
5 0
0 12

5 2
1 4 1 2 4
0 0
1 0
*/