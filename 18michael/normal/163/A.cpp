#include<cstdio>
#include<cstring>
#define LL long long
#define mod 1000000007
int n,m;LL ans=0;
char s[5002],t[5002];
LL f[5002][5002];
int main()
{
	scanf("%s",s+1),scanf("%s",t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			f[i][j]=(f[i][j-1]+(s[i]==t[j])*(f[i-1][j-1]+1))%mod;
	for(int i=1;i<=n;++i)ans=(ans+f[i][m])%mod;
	printf("%lld",ans);
	return 0;
}