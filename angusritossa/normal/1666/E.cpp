#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

int val[MAXN];
int latest[MAXN], l, n;

bool solve1(int len) {
    int pre = l;
    val[n+1] = l;
    for (int i = n; i >= 1; i--) {
        int v = min(pre, val[i+1]) - len;
        if (v >= val[i-1]) {
            pre = latest[i] = v;
        } else {
            return false;
        }
    }
    return true;
}

bool solve2(int len, bool print = false) {
    int pre = 0;
    latest[n+1] = l;
    for (int i = 1; i <= n; i++) {
        int end = min(pre+len, val[i+1]);
        end = min(end, latest[i+1]);
        //printf("%d %d\n", i, end);
        if (print) printf("%d %d\n", pre, end);
        if (end < val[i]) {
            return false;
        } else {
            pre = end;
        }
    }
    return pre == l;
}
int main() {
   scanf("%d%d", &l, &n);
   for (int i = 1; i <= n; i++) {
       scanf("%d", &val[i]);
   }
   int s = 0;
   int e = l;
   while (s != e) {
       int m = (s+e+1)/2;
       if (solve1(m)) s = m;
       else e = m-1;
   }
   int smallest = s;
   solve1(smallest);
   s = 0;
   e = l;
   while (s != e) {
       int m = (s+e)/2;
       if (solve2(m)) e = m;
       else s = m+1;
   }
   int largest = s;
   //fprintf(stderr, "smallest=%d, largest=%d, diff=%d\n", smallest, largest, largest-smallest);
   solve2(largest, 1);
}