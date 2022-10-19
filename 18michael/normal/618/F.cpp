#include<cstdio>
#define LL long long
int n;bool ok;
int c[1000002],d[1000002];
LL a[1000002],b[1000002];
inline void swap(LL &x,LL &y)
{
	LL z=x;x=y,y=z;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]),b[i]+=b[i-1];
	if(ok=(b[n]<a[n]))for(int i=1;i<=n;++i)swap(a[i],b[i]);
	for(int i=0;i<=n;++i)d[i]=-1;
	for(int i=0;i<=n;++i)
	{
		for(c[i]=c[i-1];b[c[i]+1]<=a[i];++c[i]);
		if(~d[a[i]-b[c[i]]])
		{
			if(ok)
			{
				printf("%d\n",c[i]-c[d[a[i]-b[c[i]]]]);
				for(int j=c[d[a[i]-b[c[i]]]]+1;j<=c[i];++j)printf("%d ",j);
				printf("\n%d\n",i-d[a[i]-b[c[i]]]);
				for(int j=d[a[i]-b[c[i]]]+1;j<=i;++j)printf("%d ",j);
			}
			else
			{
				printf("%d\n",i-d[a[i]-b[c[i]]]);
				for(int j=d[a[i]-b[c[i]]]+1;j<=i;++j)printf("%d ",j);
				printf("\n%d\n",c[i]-c[d[a[i]-b[c[i]]]]);
				for(int j=c[d[a[i]-b[c[i]]]]+1;j<=c[i];++j)printf("%d ",j);
			}
			break;
		}
		d[a[i]-b[c[i]]]=i;
	}
	return 0;
}