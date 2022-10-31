#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;
const int MOD=998244353;

int n,s[N];

int main()
{
	scanf("%d",&n);
	s[0]=1;
	for (int i=1;i<=n;i++) s[i]=(LL)s[i-1]*10%MOD;
	for (int i=1;i<n;i++)
	{
		int ans=(LL)2*10*9*s[n-i-1]%MOD;
		if (i<n-1) (ans+=(LL)(n-i-1)*10*9*9%MOD*s[n-i-2]%MOD)%=MOD;
		printf("%d ",ans);
	}
	printf("%d\n",10);
	return 0;
}