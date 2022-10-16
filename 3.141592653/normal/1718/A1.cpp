#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;

struct pii
{
	int a,b;
	pii():a(0),b(0){}
	pii(int aa,int bb):a(aa),b(bb){}
};

namespace __sol
{
	int n,m;
	int a[1<<20];
	int dp[1<<20];
	void solve()
	{
		dp[(1<<20)-2]=-1e9;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++)
			a[i]^=a[i-1];
		std::map<int,int>last;
		last[0]=0;
		for(int i=1;i<=n;i++)
		{
			int t=(1<<20)-2;
			if(last.find(a[i])!=last.end())t=last[a[i]];
			dp[i]=std::max(dp[i-1],dp[t]+1);
			last[a[i]]=i;
		}
		printf("%d\n",n-dp[n]);
		//a[n+1]=0;
		//for(int i=n+1;i>=1;i--)
		//	a[i]^=a[i-1];
		
	}
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)
	{
		__sol::solve();
	}
}