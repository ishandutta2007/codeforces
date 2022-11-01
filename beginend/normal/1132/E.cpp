#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

LL w,cnt[10];
bool dp[20005];

void solve()
{
	dp[0]=1;
	for (int i=1;i<=8;i++)
		for (int j=840*16;j>=0;j--)
		{
			if (dp[j]) continue;
			for (int k=1;k<=cnt[i]&&i*k<=j;k++) dp[j]|=dp[j-i*k];
		}
}

int main()
{
	scanf("%lld",&w);
	LL s=0;
	for (int i=1;i<=8;i++) scanf("%lld",&cnt[i]),s+=(LL)cnt[i]*i;
	if (s<=w) {printf("%lld\n",s);return 0;}
	LL tot=0;
	for (int i=1;i<=8;i++)
		if ((LL)cnt[i]*i>=840*2)
		{
			LL k=cnt[i]*i/840-1;
			tot+=k;
			cnt[i]-=(LL)k*840/i;
		}
	solve();
	LL mx=0;
	for (int i=0;i<=std::min((LL)840*16,w);i++)
		if (dp[i]) mx=std::max(mx,(LL)i+(tot?(LL)840*std::min(tot,(w-i)/840):0));
	printf("%lld\n",mx);
	return 0;
	return 0;
}