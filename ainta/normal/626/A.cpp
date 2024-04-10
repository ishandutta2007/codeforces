#include<stdio.h>
int n, C[600][600], x = 300, y = 300, Res;
char p[1010];
int main(){
    int i;
    scanf("%d",&n);
    C[x][y] = 1;
    scanf("%s",p);
    for(i=0;i<n;i++){
        if(p[i]=='L')x--;
        if(p[i]=='R')x++;
        if(p[i]=='U')y++;
        if(p[i]=='D')y--;
        Res += C[x][y];
        C[x][y]++;
    }
    printf("%d\n",Res);
}