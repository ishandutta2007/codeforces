/*
    I will never forget it.
*/
 
// 392699
 
#include <cstdio>
#include <cstdlib>
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
 
const int N = 1e3;
 
char e[N + 10][N + 10];
int n, m, to[N + 10][2];
 
void work() {
    if (m % 2) {
        puts("YES");
        for (int i = 0; i <= m; i++) printf("%d ", i % 2 + 1);
        puts("");
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (e[i][j] == e[j][i]) {
                puts("YES");
                for (int k = 0; k <= m; k++) {
                    if (k % 2)
                        printf("%d ", i);
                    else
                        printf("%d ", j);
                }
                puts("");
                return;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (to[j][e[i][j] - 'a'] == -1) continue;
            puts("YES");
            int k = to[j][e[i][j] - 'a'];
            if ((m / 2) % 2) {
                for (int l = 0; l <= m; l++) {
                    if (l % 4 == 0)
                        printf("%d ", i);
                    else if (l % 4 == 2)
                        printf("%d ", k);
                    else
                        printf("%d ", j);
                }
                puts("");
                return;
            }
            for (int l = 0; l <= m; l++) {
                if (l % 4 == 3)
                    printf("%d ", i);
                else if (l % 4 == 1)
                    printf("%d ", k);
                else
                    printf("%d ", j);
            }
            puts("");
            return;
        }
    puts("NO");
}
 
struct OI {
    int RP, score;
} NOIWC2021, FJOI2021;
 
int main() {
    NOIWC2021.RP++, NOIWC2021.score++, FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        n = fr(), m = fr(), memset(to, -1, sizeof(to));
        for (int i = 1; i <= n; i++) {
            scanf("%s", e[i] + 1);
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                to[i][e[i][j] - 'a'] = j;
            }
        }
        work();
    }
    return 0;
}