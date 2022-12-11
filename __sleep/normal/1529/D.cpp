#include<cstdio>
const int P= 998244353;
long long dp[1000005],t[1000005];
int main(){
    int n;
    scanf("%d",&n);
    dp[1]=1;
    for(int i=1;i*i<=n;i++)
        for(int j=i;i*j<=n;j++)
            t[i*j]+=2;
    for(int i=1;i*i<=n;i++)
        t[i*i]-=1;
    for(int i=2;i<=n;i++)
        dp[i]=(2*dp[i-1]+t[i])%P;
    printf("%lld\n",((dp[n]-dp[n-1])+P)%P);
    return 0;
}