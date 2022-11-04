#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, A[1010], B[1010], vis[1010], cnt = 1, ans = 0;

char Ans[1010][1010];

void Do(int cnt, int x, int y) {
    Ans[cnt][x] = Ans[cnt][y] = x < y ? '/' : '\\';
}

int main() {
    scanf("%d", &n), ans = n;
    for(int i = 1; i <= n; i++) scanf("%d", &A[i]), B[A[i]] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) Ans[i][j] = '.';
    for(int i = 1; i <= n; i++) if(A[i] != i) {
        ans--;
        break;
    }
    if(ans == n) {
        printf("%d\n", n);
        for(int i = n; i >= 1; i--) puts(Ans[i] + 1);
        return 0;
    }
    vis[B[1]] = 1;
    Ans[cnt++][B[1]] = '/';
    for(int i = B[B[1]]; i != B[1]; i = B[i]) {
        vis[i] = 1;
        Do(cnt++, i, A[i]);
    }
    int emp = 1;
    for(int i = 1; i <= n; i++) if(!vis[i] && A[i] != i) {
        Do(cnt, i, emp);
        vis[i] = 1;
        for(i = B[i]; !vis[i]; i = B[i]) {
            vis[i] = 1;
            Do(cnt++, i, A[i]);
        }
        Do(cnt++, emp, A[i]);
    }
    printf("%d\n", ans);
    for(int i = n; i >= 1; i--) puts(Ans[i] + 1);
    return 0;
}