#include<cstdio>
#define LL long long
int n,m;LL q;
LL a[200002];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1,l,r,mid;i<=m;++i)
	{
		scanf("%lld",&q),l=1,r=n-1;
		while(l<=r)
		{
			mid=((l+r)>>1);
			if(a[mid]<q)l=mid+1;
			else r=mid-1;
		}
		printf("%d %lld\n",l,q-a[r]);
	}
	return 0;
}