#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
int cum[200005];
long long f(long long x)
{
	return x*(x-1)/2;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int p=(1<<k)-1;
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		cum[i]=(cum[i-1]^a);
	}
	for (int i=0;i<=n;i++)
	{
		if (m.count(cum[i]^p))
		m[cum[i]^p]++;
		else
		m[cum[i]]++;
	}
	long long ans=f(n+1);
	for (auto p:m)
	{
		long long tmp=p.second;
		ans-=f(tmp/2)+f((tmp+1)/2);
	}
	printf("%I64d",ans);
}