#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
int n,b[200005],i;
long long f[200005],ans;
map<int,long long> mp;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",b+i);
		f[i]=b[i];
		if(mp.count(i-b[i]))
			f[i]=b[i]+mp[i-b[i]];
		mp[i-b[i]]=f[i];
		ans=max(ans,f[i]);
	}
	printf("%lld",ans);
	return 0;
}