#pragma GCC optimize "O3"
#include <bits/stdc++.h>

using namespace std;

int n, m, a, c;
int dp[1048576];
long long sum;
long long t[20];
vector <long long> act;

int mitm(long long a, long long b)
{
	if(act.size()&1) 
	{
		act.push_back(0);
	}
	int n=(c+1)>>1;
	int m=1<<n;
	vector <long long> le(m), ri(m+1);
	for(int i=0; i<n; ++i)
	{
		le[1<<i]=act[i];
		ri[1<<i]=act[i+n];
	}
	for(int i=1; i<m; ++i)
	{
		le[i]=le[-i&i]+le[i^(-i&i)];
		ri[i]=ri[-i&i]+ri[i^(-i&i)];
	}
	ri[m]=-2e18;
	sort(le.begin(), le.end());
	sort(ri.begin(), ri.end());
	int x=m;
	int y=m;
	int res=0;
	for(int i=0; i<m; ++i)
	{
		while(le[i]+ri[x]>b) 
		{
			--x;
		}
		while(le[i]+ri[y]>=a)
		{
			--y;
		}
		res+=x-y;
	}
	return res;
}
 
int main()
{
	scanf("%d", &n);
	m=1<<n;
	for(int i=0; i<n; ++i)
	{
		scanf("%lld", &t[i]);
	}
	for(int i=1; i<m; ++i)
	{
		sum^=sum;
		for(int j=0; j<n; ++j)
		{
			if(i&(1<<j))
			{
				act.push_back(t[j]<<1);
				sum+=t[j];
			}
		}
		c=__builtin_popcount(i);
		dp[i]=c;
		if((sum^c)&1)
		{
			a=mitm(sum-c+1, sum+c-1);
			if(abs(sum)<c)
			{
				a-=2;
			}
			if(a)
			{
				--dp[i];
			}
		}
		act.clear();
	}
	for(int i=1; i<m; ++i)
	{
		for(int j=i^(1<<(31^__builtin_clz(i))); j; j=(j-1)&i)
		{
			dp[i]=min(dp[i], dp[j]+dp[i^j]);
		}
	}
	printf("%d\n", dp[m-1]);
}