#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,k,i,t,j,m,a[6],q;
long long f[7][1000005];
long long dfs(int i,int n)
{
	if(f[i][n]!=-1)
		return f[i][n];
	if(i==6)
		return f[i][n]=0;
	f[i][n]=-10000000000000000ll;
	int j;
	for(j=n%10;j<=n&&j<=k*9;j+=10)
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
	while(q--)
	{
		scanf("%d",&n);
		memset(f,-1,sizeof(f));
		printf("%lld\n",dfs(0,n));
	}
}