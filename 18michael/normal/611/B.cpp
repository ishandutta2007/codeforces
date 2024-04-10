#include<cstdio>
#define LL long long
int t=0;LL A,B;
LL num[3602];
inline int binary_search(LL x)
{
	int l=1,r=t,mid;
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(num[mid]>x)r=mid-1;
		else l=mid+1;
	}
	return r;
}
int main()
{
	for(int i=2;i<=60;++i)
		for(int j=i-2;~j;--j)
			num[++t]=(1LL<<i)-(1LL<<j)-1;
	scanf("%lld%lld",&A,&B),printf("%d",binary_search(B)-binary_search(A-1));
	return 0;
}