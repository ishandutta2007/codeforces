#include<cstdio>
#define K 510
#define N 510
#define Q 1000000007
using namespace std;
long long dp[K][N]={0};
long long p2[N*N];
int main(){
    int i,j,l,n,k,coe;
    long long ans=0;
    scanf("%d%d",&n,&k);
    p2[0]=1;
    dp[0][0]=1;
    for(i=1;i<N*N;i++) p2[i]=p2[i-1]*2%Q;
    for(i=0;i<n;i++){
        for(l=i+1;l<=n;l++){
            for(j=0;j<k;j++){
                coe=p2[i*(l-i)];
                coe=1LL*coe*((p2[l-i]+Q-1)%Q)%Q;
                coe%=Q;
                dp[j+1][l]+=1LL*dp[j][i]*coe%Q;
                dp[j+1][l]%=Q;
            }
        }
    }
    for(i=0;i<=n;i++){
        ans+=1LL*dp[k][i]*p2[i*(n-i)]%Q;
        ans%=Q;
    }
    printf("%I64d\n",ans);
    return 0;
}