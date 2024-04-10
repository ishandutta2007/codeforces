#include<bits/stdc++.h>
using namespace std;
const int N=1500005,E=262144;
const int M=998244353;
int n,t,i,l,r,p,k,a[66],j;
char c[18][18];
long long as[6666666],dp[262144],f[18][262144];
long long tmp[19][262144],ls[19][262144];
vector<int> g[666666];
void dfs(int i,int l,int p)
{
	int j,k;
	if(p==0)
	{
		int m=0;
		long long s=0;
		--i;
		for(j=i;j>=1;--j)
			m=(m<<(a[j]-a[j-1]+1))|1;
		for(j=0;j<(1<<n);++j)
			s+=((n-__builtin_popcount(j)&1)?-ls[i][j]:ls[i][j]);
		as[m]=s;
		return;
	}
	for(j=l;j<=p;++j)
		if(p-j==0||p-j>=j)
		{
			a[i]=j;
			for(k=0;k<(1<<n);++k)
				ls[i][k]=ls[i-1][k]*tmp[j][k];
			dfs(i+1,j,p-j);
		}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=0;i<n;++i)
		scanf("%s",c[i]);
	for(i=1;i<(1<<n);++i)
	{
		int s=0;
		for(j=0;j<n;++j)
			s+=(i>>j)&1;
		g[s].push_back(j);
	}
	for(i=1;i<(1<<n);++i)
	{
		int s=0,pos=0;
		for(j=0;j<n;++j)
			if(i>>j&1)
			{
				++s;
				pos=j;
			}
		if(s==1)
			f[pos][i]=1;
		else
		{
			for(j=0;j<n;++j)
				if(i>>j&1)
					for(k=0;k<n;++k)
						if((i>>k&1)&&c[j][k]=='1')
							f[j][i]+=f[k][i^(1<<j)];
		}
		for(j=0;j<n;++j)
			tmp[s][i]+=f[j][i];
	}
	/*for(i=1;i<=n;++i)
	{
		for(j=0;j<(1<<n);++j)
			cout<<tmp[i][j]<<' ';
		cout<<endl;
	}*/
	for(i=1;i<=n;++i)
		for(k=0;k<n;++k)
			for(j=0;j<(1<<n);++j)
				if((j>>k)&1)
					tmp[i][j]+=tmp[i][j^(1<<k)];
	for(i=0;i<(1<<n);++i)
		ls[0][i]=1;
	dfs(1,1,n);
	for(i=0;i<(1<<n-1);++i)
	{
		int s=1,t=0;
		k=0;
		for(j=0;j<n-1;++j)
			if((i>>j)&1)
			{
				++s;
				++t;
			}
			else
			{
				a[++k]=s;
				s=1;
			}
		a[++k]=s;
		a[0]=0;
		sort(a+1,a+1+k);
		int m=0;
		for(j=k;j>=1;--j)
			m=(m<<(a[j]-a[j-1]+1))|1;
		dp[i]=(t&1?-as[m]:as[m]);
	}
	for(j=0;j<n-1;++j)
		for(i=0;i<(1<<n-1);++i)
			if((i>>j)&1)
				dp[i^(1<<j)]+=dp[i];
	for(i=0;i<(1<<n-1);++i)
		printf("%lld ",abs(dp[i]));
}