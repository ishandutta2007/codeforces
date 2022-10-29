#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int l,r,K,lmt,i,j,p[100005],cnt;
bool v[100005];
ll dfs(int x,int y,int z)
{
	ll rtn=lmt/y*z;
	for(int i=x;1ll*y*p[i]<=lmt&&p[i]<K;++i)
		rtn+=dfs(i+1,y*p[i],-z);
	return rtn;
}
int work(int n)
{
	if(K>n)
		return 0;
	if(1ll*K*K>n)
		return 1;
	lmt=n;
	return dfs(1,K,1);
}
int main()
{
	scanf("%d%d%d",&l,&r,&K);
	for(i=2;i*i<=K;++i)
		if(K%i==0)
		{
			printf("0");
			return 0;
		}
	for(i=2;i<=100000;++i)
	{
		if(!v[i])
			p[++cnt]=i;
		for(j=1;j<=cnt&&p[j]*i<=100000;++j)
		{
			v[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
	printf("%d",work(r)-work(l-1));
	return 0;
}