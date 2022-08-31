#include<stdio.h>
int w[5010], Bef[5010][26], cnt;
int n, D[5010][5010], Mod = 1000000007, P[5010];
char p[5010];
int main(){
    int i, j, k;
    scanf("%d",&n);
    scanf("%s",p+1);
    for(i=1;i<=n;i++){
        if(i==1 || p[i]!=p[i-1]){
            w[++cnt] = p[i]-'a';
        }
    }
    for(i=1;i<=cnt;i++){
        for(j=0;j<26;j++){
            Bef[i][j]=Bef[i-1][j];
        }
        Bef[i][w[i]] = i;
    }
    for(i=1;i<=cnt;i++)D[0][i]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=cnt;j++){
            D[i][j] = (D[i][j-1] + D[i-1][j])%Mod;
            int tp = Bef[j-1][w[j]];
            D[i][j] = (D[i][j] + Mod - D[i-1][tp])%Mod;
        }
    }
    printf("%d\n",D[n][cnt]);
}