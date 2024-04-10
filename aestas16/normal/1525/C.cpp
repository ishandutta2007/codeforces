/*
    I will never forget it.
*/

// 392699

#include <bits/stdc++.h>

using namespace std;

void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 3e5;

int top[2], ans[N + 10], stk[2][N + 10];
char ch[5];

struct robot {
    int id, x;
    bool d;
    bool operator < (const robot &rhs) const { return x < rhs.x; }
} a[N + 10];

struct OI {
    int RP, score;
} CSPS2021, NOIP2021;

int main() {
    CSPS2021.RP++, CSPS2021.score++, NOIP2021.RP++, NOIP2021.score++, 392699;
    for (int T = fr(); T--;) {
        int n = fr(), m = fr();
        top[0] = top[1] = 0;
        for (int i = 1; i <= n; i++) fr(a[i].x), ans[i] = -1, a[i].id = i;
        for (int i = 1; i <= n; i++) {
            scanf("%s", ch);
            a[i].d = (ch[0] == 'R');
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            // printf("%d\n", a[i].x);
            int p = a[i].x & 1;
            // printf("%d %d\n", a[i].x, a[i].d);
            if (a[i].d == 0) {
                if (top[p]) {
                    int j = stk[p][top[p]--];
                    // printf("qwq: %d\n", j);
                    // j = a[j].id;
                    ans[a[i].id] = ans[a[j].id] = (a[i].x - (a[j].d ? a[j].x : -a[j].x)) / 2;
                } else stk[p][++top[p]] = i;
            } else stk[p][++top[p]] = i;
        }
        for (int p = 0; p < 2; p++)
            while (top[p] > 1) {
                int i = stk[p][top[p]--];
                int j = stk[p][top[p]--];
                // printf("%d %d\n", i, j);
                ans[a[i].id] = ans[a[j].id] = (m * 2 - a[i].x - (a[j].d ? a[j].x : -a[j].x)) / 2;
            }
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}