#include <cstdio>
#include <algorithm>
int T, n, m, sr[50005], sc[50005], ans;
char a[400005];
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m), ans = n * m;
        for (register int i = 0; i < n; ++i) sr[i] = 0;
        for (register int i = 0; i < m; ++i) sc[i] = 0;
        for (register int i = 0; i < n; ++i){
            scanf("%s", a + i * m);
            for (register int j = 0; j < m; ++j)
                if (a[i * m + j] == '.') ++sr[i], ++sc[j];
        }
        for (register int i = 0; i < n; ++i)
            for (register int j = 0; j < m; ++j)
                ans = std :: min(ans, sr[i] + sc[j] - (a[i * m + j] == '.'));
        printf("%d\n", ans);
    }
}