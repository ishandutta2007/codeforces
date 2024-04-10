#include<stdio.h>
long long D[101000], D2[101000], D3[101000][26], D4[101000][26], D5[101000][26], Res;
int m, n;
char p[101000];
int main(){
    int i, j, k;
    scanf("%d%d",&n,&m);
    scanf("%s",p+1);
    for(i=1;i<=n;i++)p[i]-='a';
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++)if(p[i] != j)D4[i][j] = 1;
        D[i] += D[i-1];
        D2[i] += D2[i-1];
        if(p[i]!=p[i-1])D[i] += D2[i-1];
        for(j=0;j<m;j++){
            if(j == p[i]){
                for(k=0;k<m;k++)D3[i][k] += D3[i-1][j];
            }
            else{
                D[i] += D3[i-1][j];
            }
        }
        for(j=0;j<m;j++){
            if(j == p[i]){
                for(k=0;k<m;k++){
                    if(k==p[i-1])D5[i][k] += D4[i-1][j];
                    else D3[i][k] += D4[i-1][j];
                }
                continue;
            }
            D2[i] += D4[i-1][j];
            if(p[i]!=p[i-1])D[i] += D4[i-1][j];
        }
        for(j=0;j<m;j++){
            if(j == p[i]){
                for(k=0;k<m;k++){
                    if(k==p[i-1])D5[i][k] += D5[i-1][j];
                    else D3[i][k] += D5[i-1][j];
                }
                continue;
            }
            D2[i] += D5[i-1][j];
            if(p[i]!=p[i-1])D[i] += D5[i-1][j];
        }
    }
    for(i=0;i<m;i++)Res +=D3[n][i]+D4[n][i]+D5[n][i];
    Res+=D[n]+D2[n];
    printf("%lld\n",Res);
}