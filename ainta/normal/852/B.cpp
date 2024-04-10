#include<cstdio>
#include<algorithm>
using namespace std;
int n, L, M, C[110], S[110], w[110][110], P[110], R[110][110], Mod = 1000000007, TP[110][110];
int A[1010000];
int main(){
    int i, j, a, k;
    scanf("%d%d%d",&n,&L,&M);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        C[a%M]++;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        A[i] = a;
        P[a%M]++;
    }
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            w[i][j] = P[(j-i+M)%M];
        }
        R[i][i] = 1;
    }
    L-=2;
    while(L){
        if(L&1){
            for(i=0;i<M;i++)for(j=0;j<M;j++)TP[i][j] = 0;
            for(i=0;i<M;i++)for(j=0;j<M;j++)for(k=0;k<M;k++)TP[i][j]=(TP[i][j]+1ll*R[i][k]*w[k][j])%Mod;
            for(i=0;i<M;i++)for(j=0;j<M;j++)R[i][j]=TP[i][j];
        }
        L>>=1;
        for(i=0;i<M;i++)for(j=0;j<M;j++)TP[i][j] = 0;
        for(i=0;i<M;i++)for(j=0;j<M;j++)for(k=0;k<M;k++)TP[i][j]=(TP[i][j]+1ll*w[i][k]*w[k][j])%Mod;
        for(i=0;i<M;i++)for(j=0;j<M;j++)w[i][j]=TP[i][j];
    }
    for(i=0;i<M;i++){
        for(j=0;j<M;j++){
            S[j] = (S[j] + 1ll*R[i][j]*C[i])%Mod;
        }
    }
    int res = 0;
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        res = (res + S[(M+M-A[i]-a)%M])%Mod;
    }
    printf("%d\n",res);
}