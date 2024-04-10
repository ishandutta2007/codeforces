#include<bits/stdc++.h>
using namespace std;
const int N=1100005,M=1000000007;
long long inv2=500000004;
int n,m,i,j,a[N];
long long f[N],g[N],ans=M;
char c[100005];
void FWT(long long a[],int l,int f)
{
	int i,j;
	for(i=0;i<l;++i)
		for(j=0;j<(1<<l);++j)
			if(((j>>i)&1)^1)
			{
				long long x=a[j],y=a[j+(1<<i)];
				a[j]=(x+y)*(f?inv2:1)%M;
				a[j+(1<<i)]=(x-y)*(f?inv2:1)%M;
			}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=0;i<n;++i)
	{
		scanf("%s",c+1);
		for(j=1;c[j];++j)
			if(c[j]=='1')
				a[j]|=(1<<i);
	}
	for(i=1;i<=m;++i)
		++f[a[i]];
	for(i=0;i<(1<<n);++i)
	{
		int t=__builtin_popcount(i);
		g[i]=min(n-t,t);
	}
	FWT(f,n,0);
	FWT(g,n,0);
	for(i=0;i<(1<<n);++i)
		f[i]=f[i]*g[i]%M;
	FWT(f,n,1);
	for(i=0;i<(1<<n);++i)
		ans=min(ans,(f[i]%M+M)%M);
	cout<<ans;
}