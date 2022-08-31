#include<stdio.h>
int i, n, m, j, w[110][110];
char p[110][110];
void Add(int x, int y, int d){
    int i, j;
    for (i = 1; i <= x; i++)for (j = 1; j <= y; j++)w[i][j] += d;
}
void Do(int x, int y){
    if (p[x][y] == 'W'){
        Add(x, y, 1 - w[x][y]);
    }
    else{
        Add(x, y, -1 - w[x][y]);
    }
}
int main(){
    int x, y, c = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++){
        scanf("%s", p[i] + 1);
    }
    while (1){
        x = 0, y = 0;
        for (i = 1; i <= n; i++){
            for (j = 1; j <= m; j++){
                if (p[i][j] == 'W' && w[i][j] != 1)x = i, y = j;
                if (p[i][j] == 'B' && w[i][j] != -1)x = i, y = j;
            }
        }
        if (x == 0)break;
        c++;
        Do(x, y);
    }
    printf("%d\n", c);
}