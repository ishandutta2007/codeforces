#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map> 
using namespace std;
typedef long long LL;
map<int,int> mp;
int main()
{
	int n,p,k;
	scanf("%d%d%d",&n,&p,&k);
	LL ans=0;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		x=(LL)x*x%p*x%p*x%p-(LL)k*x%p;
		x=(x%p+p)%p;
		ans=ans+mp[x];
		mp[x]++;
	}
	printf("%lld\n",ans);
	return 0;
}