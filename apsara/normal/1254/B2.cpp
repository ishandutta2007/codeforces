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
int a[V], n, m;
LL p[120];
LL s[V], r[V], ps[V]
;

LL Cal(int L, int R) {
    if (L == R) return 0;
    LL res = (LL) V * V * V;
    for (int i = L; i <= R; ++i) {
        LL t = 0;
        t += (i - L) * r[L];
        t += (R - i) * r[R];
        if (i != L) t += (i + 1) * (ps[i - 1] - ps[L]) - (s[i - 1] - s[L]);
        if (i != R) t += (s[R - 1] - s[i]) - (i + 1) * (ps[R - 1] - ps[i]);
        res = min(res, t);
        //printf("Cal %d %d %d %I64d %I64d %I64d\n", i, L, R, t, r[L], r[R]);
    }
    return res;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        LL S = 0;
        for (int i = 0; i < n; ++i) S += a[i];
        if (S == 1) {
            puts("-1");
            continue;
        }
        m = 0;
        for (int i = 2; (LL) i * i <= S; ++i) {
            if (S % i == 0) {
                p[m++] = i;
                while (S % i == 0) S /= i;
            }
        }
        if (S != 1) p[m++] = S;
        LL ans = (LL) V * V * V;
        //LL ans = S;
        for (int i = 0; i < m; ++i) {
            LL res = 0;
            for (int j = 0; j < n; ++j) r[j] = a[j] % p[i];
            ps[0] = s[0] = r[0];
            for (int j = 1; j < n; ++j) {
                s[j] = s[j - 1] + r[j] * (j + 1);
                ps[j] = ps[j - 1] + r[j];
            }
            LL pre = r[0];
            int L = 0;
            for (int j = 1; j < n; ++j) {
                pre += r[j];
                if (pre >= p[i]) {
                    int R = j;
                    LL re = pre - p[i];
                    r[j] -= re;
                    res += Cal(L, R);
                    pre -= p[i];
                    r[j] = re;
                    L = j;
                }
            }
            //printf("P %d %I64d %I64d\n", i, p[i], res);
            ans = min(ans, res);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
4 0 0 0 9
3
1 2 3
3
1 3 2

4
1 2 3 4

1
2

4
2 1 3 4

3
1 0 1

1
1

3
4 8 5

5
3 10 2 1 5

4
0 5 15 10

1
1



2
-1
9
2
0
-1
*/