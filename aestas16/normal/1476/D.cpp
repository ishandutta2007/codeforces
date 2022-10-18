/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstring>
 
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
 
char str[N + 10];
int e[N + 10], ans[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        memset(ans, 0, sizeof(ans)), memset(e, -1, sizeof(e));
        int n = fr();
        scanf("%s", str + 1);
        for (int i = 1; i <= n; i++) e[i] = str[i] == 'R';
        for (int i = 0; i <= n; i++) {
            if (ans[i]) continue;
            int r = i, j = i, lst = 1, tmp = 1;
            while (e[j + 1] == lst) j++, tmp++, lst ^= 1;
            r = j, j = i, lst = 0;
            while (e[j] == lst) j--, tmp++, lst ^= 1;
            for (int k = i; k <= r; k += 2) ans[k] = tmp;
        }
        for (int i = 0; i <= n; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}