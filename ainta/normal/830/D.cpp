#include<cstdio>
#include<algorithm>
using namespace std;
int D[410][410], Mod = 1000000007, Comb[410][410], n;
int main(){
    int i, j, k;
    for(i=0;i<=400;i++){
        Comb[i][0]=1;
        for(j=1;j<=i;j++)Comb[i][j]=(Comb[i-1][j-1]+Comb[i-1][j])%Mod;
    }
    D[1][1] = 1;
    for(i=1;i<400;i++){
        D[i][0]=1;
        for(j=1;j<=400-i;j++){
            long long s = 0;
            for(k=0;k<=j+1;k++){
                if(k>=2)s = (s + 2ll * Comb[j-1][k-2] * D[i][k] % Mod * D[i][j+1-k])%Mod;
                if(k==j+1)continue;
                if(k)s = (s + 4ll * Comb[j-1][k-1] * D[i][k] % Mod * D[i][j-k])%Mod;
                D[i+1][j] = (D[i+1][j] + 1ll * Comb[j][k] * D[i][k] % Mod * D[i][j-k])%Mod;
                if(k)s = (s + 2ll * Comb[j-1][k-1] * D[i][k] % Mod * D[i][j+1-k])%Mod;
                if(k!=j)s = (s + 1ll * Comb[j-1][k] * D[i][k] % Mod * D[i][j-1-k])%Mod;
            }
            D[i+1][j] = (D[i+1][j] + s * j)%Mod;
        }
    }
    scanf("%d",&n);
    printf("%d\n",D[n][1]);
}