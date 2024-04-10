#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,i,t,j,m,a[6],q,vis[7][1000005];
long long f[7][1000005];
long long dfs(int i,int n)
{
	if(f[i][n]!=-1)
		return f[i][n];
	if(i==6)
		return f[i][n]=0;
	vis[i][n]=1;
	f[i][n]=-10000000000000000ll;
	int j;
	int u=100;
	for(j=n%10;j<=n&&j<=k*9&&u>=0;j+=10,--u)
	{
		long long w=1ll*j/9*3*a[i];
		if(j%9==3||j%9==6||j/9<k-1)
			w+=j%9/3*a[i];
		f[i][n]=max(f[i][n],dfs(i+1,(n-j)/10)+w);
	}
	u=100;
	for(j=(min(k*9,n)-n%10)/10*10+n%10;j>=0&&u>=0;j-=10,--u)
	{
		long long w=1ll*j/9*3*a[i];
		if(j%9==3||j%9==6||j/9<k-1)
			w+=j%9/3*a[i];
		f[i][n]=max(f[i][n],dfs(i+1,(n-j)/10)+w);
	}
	return f[i][n];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&k);
	for(i=0;i<6;++i)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	memset(f,-1,sizeof(f));
	while(q--)
	{
		scanf("%d",&n);
		printf("%lld\n",dfs(0,n));
	}
}