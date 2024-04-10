#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200500
int T,n,k,v[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&v[i]);
		sort(v+1,v+n+1);
		long long as=0;
		for(int i=n-k;i<=n;i++)as+=v[i];
		printf("%lld\n",as);
	}
}