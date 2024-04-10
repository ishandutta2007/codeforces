#include <bits/stdc++.h>

using namespace std;

int main()
{
    const long long mod=998244353;
    int n,m;
	scanf("%d%d",&n,&m);
	int a[n+1];
	int p[n+1];
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        p[a[i]]=i;
    }
    int id[n+1][n+1];
    for(int i=0;i<=n;i++) id[i][i]=n+1;
    for(int o=0;o<=n;o++)
    {
        for(int i=o+1;i<=n;i++)
        {
            id[o][i]=min(id[o][i-1],a[i]);
        }
    }
    long long dp[n+1][n+1];
    for(int i=0;i<=n;i++) dp[i][i]=1;
    for(int o=1;o<=n;o++)
    {
        for(int i=0;i+o<=n;i++)
        {
            int l=i,r=i+o;
            int pos=p[id[l][r]];
            long long one=0,two=0;
            for(int j=l;j<pos;j++) one=(one+dp[l][j]*dp[j][pos-1])%mod;
            for(int j=pos;j<=r;j++) two=(two+dp[pos][j]*dp[j][r])%mod;
            dp[l][r]=(one*two)%mod;
        }
    }
    printf("%I64d\n",dp[0][n]);
	return 0;
}