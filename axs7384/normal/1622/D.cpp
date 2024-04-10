#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,k;
int f[N],C[N][N];
char s[N];
const int mod=998244353;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for (int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	scanf("%s",s+1);
	for (int i=1;i<=n;++i)
		f[i]=f[i-1]+s[i]-'0';
	if (f[n]<k)
	{
		puts("1");
		return 0;
	}
	int ans=1;
	for (int i=1;i<=n;++i)
		for (int j=i+1;j<=n;++j)
		{
			int cnt1=f[j]-f[i-1];
			if (cnt1>k)
				continue;
			if (s[i]=='0')
				--cnt1;
			if (s[j]=='0')
				--cnt1;
			// cout<<i<<' '<<j<<' '<<C[j-i-1][cnt1]<<endl;
			(ans+=C[j-i-1][cnt1])%=mod;
		}
	cout<<ans<<endl;
	return 0;
}