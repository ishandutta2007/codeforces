#include<stdio.h>
int n;
char p[60][60];
int main(){
    int i, bx = -1, ex, by = -1, ey, ck = 0, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(p[i][j] == '4'){
                if(bx==-1)bx=i;
                if(by==-1)by=j;
                ex=i,ey=j;
            }
        }
    }
    if(bx==-1||by==-1){
        printf("No\n");
        return 0;
    }
    for(i=bx;i<=ex;i++){
        for(j=by;j<=ey;j++){
            if(p[i][j]!='4')ck = 1;
        }
    }
    for(i=bx;i<=ex;i++){
        if(by!=1 && p[i][by-1]!='2')ck=1;
        if(ey!=n && p[i][ey+1]!='2')ck=1;
    }
    for(i=by;i<=ey;i++){
        if(bx!=1 && p[bx-1][i]!='2')ck=1;
        if(ex!=n && p[ex+1][i]!='2')ck=1;
    }
    if(bx!=1 && by!=1 && p[bx-1][by-1] != '1')ck = 1;
    if(bx!=1 && ey!=n && p[bx-1][ey+1] != '1')ck = 1;
    if(ex!=n && by!=1 && p[ex+1][by-1] != '1')ck = 1;
    if(ex!=n && ey!=n && p[ex+1][ey+1] != '1')ck = 1;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i<bx-1||i>ex+1||j<by-1||j>ey+1){
                if(p[i][j]!='0')ck=1;
            }
        }
    }
    printf(ck?"No\n":"Yes\n");
}