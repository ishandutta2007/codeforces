#include<cstdio>
#define Mx 29
#define LL long long
int n;LL sum=0;
int a[200002],b[200002],c[200002],cnt[32]={};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=n;++i)scanf("%d",&b[i]),sum+=b[i];
	if(sum%(n<<1))return 0&puts("-1");sum/=(n<<1);
	for(int i=1;i<=n;++i)
	{
		if((c[i]=a[i]+b[i]-sum)%n)return 0&puts("-1");
		c[i]/=n;for(int j=0;j<=Mx;++j)cnt[j]+=((c[i]>>j)&1);
	}
	for(int i=1;i<=n;++i)
	{
		sum=0;
		for(int j=0;j<=Mx;++j)if((c[i]>>j)&1)sum+=(cnt[j]<<j);
		if(sum!=a[i])return 0&puts("-1");
	}
	for(int i=1;i<=n;++i)printf("%d ",c[i]);
	return 0;
}