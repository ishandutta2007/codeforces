/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
 
void fr(int &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}
 
const int N = 1e2;
 
int n, a[N + 10], idx[N + 10], ans[N + 10];
 
void dfs(int u, int l, int r, int dep) {
    if (u == 0) return;
    ans[idx[a[u]]] = dep;
    int rt = 0;
    for (int i = l; i < u; i++) {
        if (a[i] > a[rt]) rt = i;
    }
    dfs(rt, l, u - 1, dep + 1);
    rt = 0;
    for (int i = u + 1; i <= r; i++) {
        if (a[i] > a[rt]) rt = i;
    }
    dfs(rt, u + 1, r, dep + 1);
}
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        n = fr();
        int rt = 0;
        for (int i = 1; i <= n; i++) fr(a[i]), idx[a[i]] = i;
        for (int i = 1; i <= n; i++) {
            if (a[i] > a[rt]) rt = i;
        }
        dfs(rt, 1, n, 0);
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}