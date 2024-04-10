#include<cstdio>
#include<cstring>
int dp[1000001][20];
bool isPrime[1101];
int prime[1101];
int tp = 0;
const int MOD = 1e9+7;
void init()
{
    dp[0][0]=1;
    for(int i=1; i<20; i++)
        dp[0][i]=2;
    for(int i=1; i<=1000000;i++)
    {
        int sum = 0;
        for(int j=0; j<20; j++)
        {
            sum += dp[i-1][j];
            sum %= MOD;
            dp[i][j] = sum;
        }
    }
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=1100; i++)
    {
        if(!isPrime[i]) continue;
        prime[tp++] = i;
        for(int j=2*i; j<=1100; j+=i)
            isPrime[j] = false;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int r, n;
        scanf("%d%d",&r,&n);
        int ans = 1;
        for(int i=0; prime[i]*prime[i]<=n;i++)
        {
            if(n%prime[i]==0)
            {
                int cnt = 0;
                while(n%prime[i]==0)
                {
                    n /= prime[i];
                    cnt ++;
                }
                //printf("%d %d %d\n",r,cnt,dp[r][cnt]);
                ans = 1LL*ans*dp[r][cnt]%MOD;
            }
        }
        if(n!=1)
            ans = 1LL*ans*dp[r][1]%MOD;
        printf("%d\n",ans);
    }
}