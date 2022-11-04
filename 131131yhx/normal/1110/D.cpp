#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1000010

using namespace std;

int n, m, A[M], F[M][3][7];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        A[x]++;
    }
    m++;
    memset(F, 200, sizeof F);
    for(int a = A[1] % 3; a <= 2 && a <= A[1]; a += 3)
        for(int b = A[2] % 3; b <= 6 && b <= A[2]; b += 3)
            F[3][a][b] = (A[1] - a) / 3 + (A[2] - b) / 3;
    for(int i = 3; i < m; i++)
        for(int j = 0; j <= 2; j++)
            for(int k = 0; k <= 6; k++)
                for(int s = A[i] % 3; s <= 9 && s <= A[i]; s += 3) { //!!!
                    int v = F[i][j][k] + (A[i] - s) / 3;
                    int a = j, b = k, c = s;
                    for(; ;) {
                        F[i + 1][min(b, 2)][min(c, 6)] = max(F[i + 1][min(b, 2)][min(c, 6)], v);
                        if(a && b && c) a--, b--, c--, v++; else break;
                    }
                }
    int ans = 0;
    for(int i = 0; i <= 2; i++)
        for(int j = 0; j <= 6; j++)
            ans = max(ans, F[m][i][j]);
    printf("%d\n", ans);
    return 0;
}