//MAXV 20
#include<cstdio>
int N;
int a[75];
int dp[1048576][76];
const int MOD = 1e9+7;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%1d",a+i);
    for(int i=0; i<=N; i++)
        dp[0][i]=1;
    for(int i=0; i<1048576; i++)
        for(int j=0; j<=N; j++)
        {
            int nowv = 0;
            for(int k=j+1; k<=N; k++)
            {
                nowv *= 2;
                nowv += a[k-1];
                if(nowv>20) break;
                if(nowv==0) continue;
                int bm = i|(1<<(nowv-1));
                dp[bm][k] += dp[i][j];
                if(dp[bm][k] >= MOD)
                    dp[bm][k] -= MOD;
            }
        }
    int ans = 0;
    for(int i=1; i<=20; i++)
    {
        for(int j=0; j<=N; j++)
        {
            ans += dp[(1<<i)-1][j];
            if(ans>=MOD) ans -= MOD;
        }
    }
    printf("%d\n",ans);
}