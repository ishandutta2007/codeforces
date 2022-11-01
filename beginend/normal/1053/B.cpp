#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=300005;

int n,a[N],w[N][2],s[N];

int get(LL x)
{
	int ans=0;
	while (x) ans+=x&1,x>>=1;
	return ans;
}

int main()
{
	scanf("%d",&n);
	w[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		LL x;scanf("%lld",&x);
		a[i]=get(x);s[i]=s[i-1]^(a[i]&1);
		w[i][0]=w[i-1][0];
		w[i][1]=w[i-1][1];
		w[i][s[i]]++;
	}
	LL ans=0;
	for (int i=1;i<=n;i++)
	{
		int mx=0,val=0,lef=i;
		for (int j=1;j<=120&&lef;j++)
		{
			val+=a[lef];mx=std::max(mx,a[lef]);
			lef--;
			if (!(val&1)&&mx*2<=val) ans++;
		}
		if (lef) ans+=(LL)w[lef-1][s[i]];
	}
	printf("%lld\n",ans);
	return 0;
}