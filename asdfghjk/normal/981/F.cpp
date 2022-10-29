#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2000005;
ll n,L,a[N],b[N],lt,rt,mid,i,j,k,mn;
int main()
{
	scanf("%lld%lld",&n,&L);
	for(i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(i=1;i<=n;++i)
		scanf("%lld",b+i);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(i=1;i<=n;++i)
	{
		a[i]+=L;
		a[n+i]=a[i]+L;
		b[n+i]=b[i]+L;
		b[2*n+i]=b[i]+2*L;
		b[3*n+i]=b[i]+3*L;
	}
	lt=0,rt=L;
	while(lt<rt)
	{
		mid=lt+rt>>1;
		mn=1<<30;
		for(i=1,j=k=1;i<=2*n;++i)
		{
			while(k<=4*n&&b[k]<=a[i]+mid)
				++k;
			while(j<=4*n&&b[j]<a[i]-mid)
				++j;
			mn=min(mn,i-j);
			if(i-(k-1)>mn)
				break;
		}
		if(i<=2*n)
			lt=mid+1;
		else
			rt=mid;
	}
	printf("%lld",lt);
	return 0;
}