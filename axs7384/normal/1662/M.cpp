#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int T; scanf("%d", &T);
    while (T--) {
        int n, m; scanf("%d %d", &n, &m);
        int rm = 0, wm = 0;
        while (m--) {
            int r, w;
            scanf("%d %d", &r, &w);
            rm = max(rm, r);
            wm = max(wm, w);
        }
        if (rm + wm > n)
            printf("IMPOSSIBLE\n");
        else {
            for (int i = 0; i < rm; ++i)
                printf("R");
            for (int i = 0; i < n - rm; ++i)
                printf("W");
            printf("\n");
        }
    }
    return 0;
}