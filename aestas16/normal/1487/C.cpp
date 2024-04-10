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
 
const int N = 1e2;
 
int a[N + 10][N + 10];
bool vis[N + 10];
 
struct OI {
    int RP, score;
} FJOI2021;
 
signed main() {
    FJOI2021.RP++, FJOI2021.score++, 392699;
    int t = fr();
    while (t--) {
        int n = fr();
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1, k = 1; j <= n; j++, k++) {
                if (n % 2 == 0 && !vis[i] && !vis[j])
                    a[i][j] = 0, vis[i] = vis[j] = 1;
                else
                    a[i][j] = (k % 2) ? 1 : -1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1, k = 1; j <= n; j++, k++) { printf("%d ", a[i][j]); }
        }
        puts("");
    }
 
    return 0;
}