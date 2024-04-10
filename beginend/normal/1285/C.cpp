#include<bits/stdc++.h>

typedef long long LL;

const int N=105;

LL n,a[N],ans;
int tot;

void dfs(int x,LL p,LL q)
{
	if (x>tot) {ans=std::min(ans,std::max(p,q));return;}
	dfs(x+1,p*a[x],q);
	dfs(x+1,p,q*a[x]);
}

int main()
{
	scanf("%lld",&n);
	ans=n;LL tmp=n;
	for (LL i=2;i*i<=n;i++)
		if (n%i==0)
		{
			a[++tot]=1;
			while (n%i==0) a[tot]*=i,n/=i;
		}
	if (n>1) a[++tot]=n;
	dfs(1,1,1);
	printf("%lld %lld\n",ans,tmp/ans);
	return 0;
}