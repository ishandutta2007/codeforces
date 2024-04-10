#include<stdio.h>
bool E[26][26];
int n, deg[26], Q[30];
char p[110][110];
int main()
{
    int i, j, x, y, h = 0, t = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%s", p[i]);
    }
    for (i = 0; i < n - 1; i++){
        for (j = 0; p[i][j] && p[i + 1][j]; j++){
            if (p[i][j] != p[i + 1][j])break;
        }
        if (!p[i + 1][j]){
            printf("Impossible\n");
            return 0;
        }
        else if (!p[i][j]){
            continue;
        }
        x = p[i][j] - 'a', y = p[i + 1][j] - 'a';
        if (!E[x][y]){
            E[x][y] = true;
            deg[y]++;
        }
    }
    for (i = 0; i < 26; i++)if (!deg[i])Q[++t] = i;
    while (h < t){
        x = Q[++h];
        for (i = 0; i < 26; i++){
            if (E[x][i]){
                deg[i]--;
                if (!deg[i])Q[++t] = i;
            }
        }
    }
    if (t == 26){
        for (i = 1; i <= 26; i++)printf("%c", 'a' + Q[i]);
    }
    else printf("Impossible\n");
}