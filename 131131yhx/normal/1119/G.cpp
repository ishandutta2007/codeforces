#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, A[1000010], B[1000010], tot = 0;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d", &A[i]), tot += A[i], B[i] = (B[i - 1] + A[i]) % n;
    printf("%d\n", (tot - 1) / n + 1), B[m] = n, sort(B + 1, B + m + 1);
    for(int i = m; i >= 1; i--) B[i] -= B[i - 1];
    for(int i = 1; i <= m; i++) printf("%d%c", B[i], " \n"[i == m]);
    for(int i = 1, t = 1; i <= m; i++)
        while(A[i] > 0 || i == m && t != 1)
            printf("%d ", i), A[i] -= B[t], t = (t == m ? putchar('\n'), 1 : t + 1);
    return 0;
}