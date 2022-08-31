#include<stdio.h>
int n, m;
char p[110][110];
int main(){
    int i, res = 0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%s",p[i]+1);
    }
    for(i=1;i<=m;i++){
        if(p[n][i]=='B'){
            if(i == 1 || p[n][i-1] == '.')res++;
        }
    }
    printf("%d\n",res);
}