#include <cstdio>
#include <cstring>
char s[105], t[105], p[105];
int T, a[26], n, m, k;
int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%s%s%s", s, t, p);
        memset(a, 0, sizeof a);
        n = strlen(s), m = strlen(t), k = strlen(p);
        for (register int i = 0; i < k; ++i) ++a[p[i] - 'a'];
        int flag = 1, j = 0;
        for (register int i = 0; i < n; ++i, ++j){
            while (j < m && s[i] != t[j]) --a[t[j] - 'a'], ++j;
            if (j == m){ flag = 0; break; }
        }
        for (register int i = j; i < m; ++i) --a[t[i] - 'a'];
        for (register int i = 0; i < 26; ++i)
            if (a[i] < 0){ flag = 0; break; }
        if (flag) printf("YES\n"); else printf("NO\n");
    }
}