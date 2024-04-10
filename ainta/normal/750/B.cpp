#include<stdio.h>
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct A{
    int c, dir;
}w[60];
int n, x, y;
char p[20];
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i].c);
        scanf("%s",p);
        if(p[0]=='N')w[i].dir = 1;
        if(p[0]=='S')w[i].dir = 3;
        if(p[0]=='E')w[i].dir = 0;
        if(p[0]=='W')w[i].dir = 2;
    }
    x = 0, y = 20000;
    for(i=n;i>=1;i--){
        if(y == 20000){
            if(w[i].dir != 1){
                printf("NO\n");
                return 0;
            }
            y -= w[i].c;
        }
        else if(y == 0){
            if(w[i].dir != 3){
                printf("NO\n");
                return 0;
            }
            y += w[i].c;
        }
        else{
            if(w[i].dir == 1)y -= w[i].c;
            if(w[i].dir == 3)y += w[i].c;
        }
        if(y<0 || y>20000){
            printf("NO\n");
            return 0;
        }
    }
    if(y!=20000){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
}