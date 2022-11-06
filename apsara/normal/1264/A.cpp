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

const int V = 1001000;
int a[V];
int b[V];
int s[V];
int _, n;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int m = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || a[i] != a[i + 1]) {
                b[++m] = 1;
            } else {
                b[m]++;
            }
        }
        //for (int i = 1; i <= m; ++i) printf("%d ", b[i]);puts("B");
        s[0] = 0;
        for (int i = 1; i <= m; ++i) s[i] = s[i - 1] + b[i];
        int ag = 0, as = 0, ab =0;
        int ps = 1, pb = 1;
        while (pb != m && s[pb + 1] * 2 <= n) ++pb;
        for (int i = 1; i <= m; ++i) {
            while (ps <= m && s[ps] - s[i] <= s[i]) ++ps;
            if (ps == m + 1) break;
            if (s[pb] - s[ps] <= s[i]) break;
            //printf("I %d %d %d\n", i, ps, pb);

            ag = s[i];
            as = s[ps] - s[i];
            ab = s[pb] - s[ps];
        }
        printf("%d %d %d\n", ag, as, ab);
    }
    return 0;
}

/*
5
12
5 4 4 3 2 2 1 1 1 1 1 1
4
4 3 2 1
1
1000000
20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
32
64 64 63 58 58 58 58 58 37 37 37 37 34 34 28 28 28 28 28 28 24 24 19 17 17 17 17 16 16 16 16 11

*/