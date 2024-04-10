#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N, M;
char s[MAXN];
int sum[MAXN][5];

int main() {
    scanf("%s%d", s + 1, &M);
    N = strlen(s + 1);
    for (int i = 1; i <= N; i++) 
        for (int j = 0; j < 3; j++)
            sum[i][j] = sum[i - 1][j] + (s[i] == 'x' + j);
    
    while (M--) {
        int l, r;
        scanf("%d%d", &l, &r);
        int a[5];
        for (int i = 0; i < 3; i++)
            a[i] = sum[r][i] - sum[l - 1][i];
        sort(a, a + 3);
        puts(r - l > 1 && a[2] - a[0] > 1 ? "NO" : "YES");
    }
    return 0;
}