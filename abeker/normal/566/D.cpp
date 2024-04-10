#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int o = 1 << 18;
const int MAXN = 200005;

int n, q;
int dad[MAXN];

int get(int x) {
    if (dad[x] == x)
       return x;
    return dad[x] = get(dad[x]);
}

void join(int x, int y) {
     int dadx = get(x);
     int dady = get(y);
     dad[dady] = dadx;
}

struct Tournament {
       int t[o * 2];
       void init() {
            memset(t, -1, sizeof t);
            for (int i=0; i<n; i++) {
                dad[i] = i;
                t[o + i] = i;
            }
       }
       void update(int x, int lo, int hi, int a, int b, int y) {
            if (lo >= b || hi <= a)
               return;
            if (lo >= a && hi <= b && t[x] != -1) {
                   join(y, t[x]);
                   t[x] = y;
                   return;
            }
            int mid = (lo + hi) / 2;
            update(x * 2, lo, mid, a, b, y);
            update(x * 2 + 1, mid, hi, a, b, y);
            if (t[x * 2] == t[x * 2 + 1])
               t[x] = t[x * 2];
       }
       int query(int x, int lo, int hi, int y) {
           if (y >= lo && y < hi && t[x] != -1)
              return t[x];           
           int mid = (lo + hi) / 2;
           if (y < mid)
              return query(x * 2, lo, mid, y);
           return query(x * 2 + 1, mid, hi, y);
       }
} T;

int main (void) {
    scanf("%d%d", &n, &q);
    T.init();
    for (int i=0; i<q; i++) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        x--; y--;
        if (t == 1) {
           join(T.query(1, 0, o, x), T.query(1, 0, o, y));
           continue;
        }
        if (t == 2) {
           T.update(1, 0, o, x, y + 1, T.query(1, 0, o, x));
           continue;
        }
        if (get(T.query(1, 0, o, x)) == get(T.query(1, 0, o, y)))
           puts("YES");
        else
            puts("NO");
    }
    return 0;
}