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
const int V = 200100;

struct Node{
    int l, r, mi, mx;
}tr[4 * V];

int a[V];

void init(int id, int l, int r) {
    tr[id].l = l;
    tr[id].r = r;
    if (l == r) {
        tr[id].mi = tr[id].mx = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2, l, mid);
    init(id * 2 + 1, mid + 1, r);
    tr[id].mi = min(tr[id * 2].mi, tr[id * 2 + 1].mi);
    tr[id].mx = max(tr[id * 2].mx, tr[id * 2 + 1].mx);
}

int readmi(int id, int l, int r) {
    if (l > r) return 1e9;
    if (tr[id].l == l && tr[id].r == r) return tr[id].mi;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return readmi(id * 2, l, r);
    else if (l > mid) return readmi(id * 2 + 1, l, r);
    else {
        int a = readmi(id * 2, l, mid);
        int b = readmi(id * 2 + 1, mid + 1, r);
        return min(a, b);
    }
}

int readmx(int id, int l, int r) {
    if (l > r) return -1e9;
    if (tr[id].l == l && tr[id].r == r) return tr[id].mx;
    int mid = (tr[id].l + tr[id].r) / 2;
    if (r <= mid) return readmx(id * 2, l, r);
    else if (l > mid) return readmx(id * 2 + 1, l, r);
    else {
        int a = readmx(id * 2, l, mid);
        int b = readmx(id * 2 + 1, mid + 1, r);
        return max(a, b);
    }
}
char s[V];
int _, n, Q, x, y;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &Q);
        a[0] = 0;
        scanf("%s", s);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') a[i + 1] = a[i] - 1;
            else a[i + 1] = a[i] + 1;
        }
        init(1, 1, n);
        while (Q--) {
            scanf("%d%d", &x, &y);
            int mi = readmi(1, 1, x - 1);
            int mx = readmx(1, 1, x - 1);
            if (mi > 0) mi = 0;
            if (mx < 0) mx = 0;
            int mi2 = readmi(1, y + 1, n) - a[y] + a[x - 1];
            int mx2 = readmx(1, y + 1, n) - a[y] + a[x - 1];
            if (mi2 > a[x]) mi2 = a[x - 1];
            if (mx2 < a[x]) mx2 = a[x - 1];
            printf("%d\n", max(mx, mx2) - min(mi2, mi) + 1);
        }
    }
    return 0;
}

/*
2
8 4
-+--+--+
1 8
2 8
2 5
1 1
4 10
+-++
1 1
1 2
2 2
1 3
2 3
3 3
1 4
2 4
3 4
4 4
*/