#include<bits/stdc++.h>
using std::min;
using std::max;

using std::swap;

using std::sort;

using std::vector;
using std::set;
using std::map;
//using std::unordered_map;
// unordered_map is disgusting and not used as default 
using std::multiset;
using std::set;
using std::priority_queue;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef unsigned unt;

struct pii
{
	int x,y;
	pii():x(0),y(0){}
	pii(int x0,int y0):x(x0),y(y0){}
};

namespace sol
{
	int n,m;
	int a[1<<20];
	bool dp[5050][5055];
	void clear()
	{
		for(int i=0;i<=n+1;i++)
			for(int ii=0;ii<=n+1;ii++)
				dp[i][ii]=0;
	}
	const int mod=1e9+7;
	int cnt[1<<20];
	void initdp()
	{
		for(int i=1;i<=n;i++)
		{
			for(int ii=1;ii<=n;ii++)cnt[ii]=0;
			int maxcnt = 0;
			for(int ii=i;ii<=n;ii++)
			{
				cnt[a[ii]]++;
				if(cnt[a[ii]]>maxcnt)maxcnt=cnt[a[ii]];
				if((ii-i+1)&1)continue;
				dp[i][ii] = (ii-i+1)/2 >= maxcnt;
			}
		}
			
	}
	int f[5055];
	void exec()
	{
		scanf("%d",&n);
		clear();
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		initdp();
		for(int i=1;i<=n;i++)
		{
			f[i]=-1e9;
			if(a[i]==a[i-1]||(i==1))f[i]=f[i-1]+1;
			for(int ii=i-2;ii>=1;ii-=2)
				if((ii==1)||(a[ii-1]==a[i]))
					if(dp[ii][i-1])f[i]=max(f[i],f[ii-1]+1);
			//printf("%d %d\n",i,f[i]);
		}
		int ans=std::max(0,f[n]);
		for(int i=n-2;i>0;i-=2)
			if(f[i]>ans)
				if(dp[i+1][n])
					ans=f[i];
		printf("%d\n",ans);
	}
	
}

int main()
{
	int __T=1;
	scanf("%d",&__T);
	while(__T--)sol::exec();
}