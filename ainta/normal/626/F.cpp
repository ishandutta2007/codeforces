#include<stdio.h>
#include<algorithm>
using namespace std;
int Mod = 1000000007, res, D[201][201][1010];
int n, w[201],K;
int main(){
    int i, j, k, t;
    scanf("%d%d",&n,&K);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1);
    D[1][1][0]=D[1][0][0]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=i;j++){
            for(k=0;k<=K;k++){
                t = (w[i+1]-w[i])*j + k;
                if(t<=K){
                    D[i+1][j+1][t] = (D[i+1][j+1][t]+D[i][j][k])%Mod;
                    D[i+1][j][t] = (D[i+1][j][t]+(long long)(j+1)*D[i][j][k])%Mod;
                    if(j)D[i+1][j-1][t] = (D[i+1][j-1][t]+(long long)j*D[i][j][k])%Mod;
                }
            }
        }
    }
    for(i=0;i<=K;i++)res=(res+D[n][0][i])%Mod;
    printf("%d\n",res);
}