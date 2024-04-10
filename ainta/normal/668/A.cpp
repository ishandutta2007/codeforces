#include<stdio.h>
int n, m, Q, w[110][110];
struct Query{
    int ck,a,b,c;
}QQ[10100];
int main(){
    int ck, a, b, c, i, j;
    scanf("%d%d%d",&n,&m,&Q);
    for(i=1;i<=Q;i++){
        scanf("%d%d",&ck,&a);
        QQ[i].ck=ck,QQ[i].a=a;
        if(ck==1){
            b = w[a][1];
            for(j=1;j<m;j++)w[a][j]=w[a][j+1];
            w[a][m] = b;
        }
        if(ck==2){
            b = w[1][a];
            for(j=1;j<n;j++)w[j][a]=w[j+1][a];
            w[n][a] = b;
        }
        if(ck==3){
            scanf("%d%d",&b,&c);
            w[a][b] = c;
            QQ[i].b=b,QQ[i].c=c;
        }
    }
    for(i=Q;i>=1;i--){
        ck = QQ[i].ck;
        a = QQ[i].a;
        b = QQ[i].b;
        c = QQ[i].c;
        if(ck==1){
            b = w[a][m];
            for(j=m;j>1;j--)w[a][j]=w[a][j-1];
            w[a][1] = b;
        }
        if(ck==2){
            b = w[n][a];
            for(j=n;j>1;j--)w[j][a]=w[j-1][a];
            w[1][a] = b;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            printf("%d ",w[i][j]);
        }
        printf("\n");
    }
}