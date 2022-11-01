#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=25;
const int MOD=1000000007;

int n,ans,ny[N];
LL s,f[N];

int C(LL n,int m)
{
	int ans=1;
	for (int i=0;i<m;i++) ans=(LL)(n-i)%MOD*ans%MOD;
	ans=(LL)ans*ny[m]%MOD;
	return ans;
}

void dfs(int x,LL ret,int c)
{
	if (x>n) {(ans+=c*C(ret+n-1,n-1))%=MOD;return;}
	dfs(x+1,ret,c);
	if (ret>=f[x]+1) dfs(x+1,ret-f[x]-1,-c);
}

int main()
{
	scanf("%d%lld",&n,&s);
	ny[0]=ny[1]=1;
	for (int i=2;i<=n;i++) ny[i]=(LL)(MOD-MOD/i)*ny[MOD%i]%MOD;
	for (int i=2;i<=n;i++) ny[i]=(LL)ny[i]*ny[i-1]%MOD;
	for (int i=1;i<=n;i++) scanf("%lld",&f[i]);
	dfs(1,s,1);
	ans+=ans<0?MOD:0;
	printf("%d\n",ans);
	return 0;
}