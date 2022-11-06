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
const int V = 100100;
struct Node {
    int v, type;
}e[V * 10];
int m;
void add(int v, int type) {
    e[m].v = v;
    e[m++].type = type;
}
bool cmp(Node x, Node y) {
    return x.v < y.v;
}
int a[V], n, A, R, M;

int main() {
    while (~scanf("%d%d%d%d", &n, &A, &R, &M)) {
        m = 0;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        LL s = 0;
        for (int i = 0; i < n; ++i) s += a[i];
        int avg = s / n;
        for (int i = 0; i < n; ++i) {
            add(a[i], 1);
            add(a[i], 0);
            if (a[i] > 0) add(a[i] - 1, 0);
            add(a[i] + 1, 0);
        }
        if (avg > 0) add(avg - 1, 0);
        add(avg, 0);
        add(avg + 1, 0);
        sort(e, e + m, cmp);
        LL ans = s * R;
        LL up = s;
        LL lo = 0;
        int un = n;
        int ln = 0;
        for (int i = 0; i < m; ++i) {
            if (e[i].type == 1) {
                up -= e[i].v;
                --un;
                lo += e[i].v;
                ++ln;
            } else {
                LL x = up - (LL) un * e[i].v;
                LL y = (LL) ln * e[i].v - lo;
                LL tmp = (LL) min(x, y) * min(A + R, M);
                if (x > y) tmp += (LL) (x - y) * R;
                else tmp += (LL) (y - x) * A;
                //printf("cost %d %I64d %d %I64d %d %I64d\n", e[i].v, up, un, lo, ln, tmp);
                ans = min(ans, tmp);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
3 1 100 100
1 3 8
3 100 1 100
1 3 8
3 100 100 1
1 3 8
5 1 2 4
5 5 3 6 5
5 1 2 2
5 5 3 6 5
*/