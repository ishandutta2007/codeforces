#include<stdio.h>
#define INF 999999999
int w[410][410];
int n, m;
int main(){
    int i, j, a, b, k;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        w[a][b]=w[b][a]=1;
    }
    if(w[1][n]){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(i==j)continue;
                w[i][j]=1-w[i][j];
            }
        }
    }
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(!w[i][j]&&i!=j)w[i][j]=INF;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(w[i][j]>w[i][k]+w[k][j])w[i][j]=w[i][k]+w[k][j];
            }
        }
    }
    if(w[1][n] == INF)printf("-1\n");
    else printf("%d\n",w[1][n]);
}