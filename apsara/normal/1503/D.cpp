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
const int V = 400100;
int pos[V], QL[V], QR[V], vis[V];
int n, a[V];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i * 2], &a[i * 2 + 1]);
            pos[a[i * 2]] = i * 2;
            pos[a[i * 2 + 1]] = i * 2 + 1;
        }
        for (int i = 0; i <= 2 * n; ++i) vis[i] = 0;
        int L = 0, R = 2 * n + 1;
        bool ok = true;
        int ans = 0;
        while (L + 1 < R && ok) {
            int use = 0, total = 0;
            L++;
            R--;
            int pl = pos[L];
            int pr = pos[R];
            if (pl / 2 == pr / 2) {
                vis[pl / 2] = 1;
                continue;
            }
            vis[pl / 2] = 1;
            vis[pr / 2] = 1;
            total += 2;
            if (pl %2 != 0) ++use;
            if (pr %2 != 0) ++use;
            int topL = 0, tailL = 0;
            int topR = 0, tailR = 0;
            //printf("P %d %d %d %d %d %d\n", L, R, pl, pr, a[pl ^ 1], a[pr ^ 1]);
            for (int j = L + 1; j < a[pr ^ 1]; ++j) {
                if(!vis[pos[j] / 2]) QL[++tailL] = pos[j];
            }
            for (int j = R - 1; j > a[pl ^ 1]; --j) {
                if(!vis[pos[j] / 2]) QR[++tailR] = pos[j];
            }
            L = a[pr ^ 1];
            R = a[pl ^ 1];
            //printf("Q %d %d\n", tailL, tailR);
            while ((topL != tailL || topR != tailR) && ok) {
                while (topL != tailL && ok) {
                    pl = QL[++topL];
                    //printf("QL %d %d\n", pl, a[pl]);
                    if (a[pl ^ 1] > R) {ok = false; break;}
                    for (int j = R - 1; j > a[pl ^ 1]; --j) {
                        if(!vis[pos[j] / 2]) QR[++tailR] = pos[j];
                    }
                    R = a[pl ^ 1];
                    ++total;
                    if (pl % 2 != 0) ++use;
                }
                while (topR != tailR && ok) {
                    pr = QR[++topR];
                    //printf("QR %d %d\n", pr, a[pr]);
                    if (a[pr ^ 1] < L) {ok = false; break;}
                    for (int j = L + 1; j < a[pr ^ 1]; ++j) {
                        if(!vis[pos[j] / 2]) QL[++tailL] = pos[j];
                    }
                    L = a[pr ^ 1];
                    ++total;
                    if (pr % 2 != 0) ++use;
                }
            }
            //printf("LOOP %d %d %d %d\n", L, R, use, total);
            ans += min(use, total - use);
        }
        if (L + 1 != R) ok = false;
        if (ok) printf("%d\n", ans);
        else puts("-1");
    }
    return 0;
}

/*
5
3 10
6 4
1 9
5 8
2 7

2
1 2
3 4

3
1 2
3 6
4 5
*/