#include <cstdio>
#include <algorithm>
int n, a[2005], b[2005], ans;
int main(){
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i) scanf("%d", a + i), b[i] = a[i];
    std :: sort(b + 1, b + 1 + n);
    int m = std :: unique(b + 1, b + 1 + n) - b - 1;
    for (register int i = 1; i <= n; ++i)
        a[i] = std :: lower_bound(b + 1, b + 1 + m, a[i]) - b;
    ans = n;
    for (register int i = 1; i <= n; ++i){
        bool flag = 1;
        for (register int j = 1; j <= m; ++j) b[j] = 0;
        for (register int j = 1; j < i; ++j){
            ++b[a[j]];
            if (b[a[j]] > 1){ flag = 0; break; }
        }
        if (!flag) break;
        for (register int j = n; j >= i; --j){
            ++b[a[j]];
            if (b[a[j]] > 1){ flag = 0, ans = std :: min(ans, j - i + 1); break; }
        }
        if (flag) return printf("0\n"), 0;
    }
    printf("%d\n", ans);
}