#include<cstdio>
#define LL long long
int n;int x[2],y[2];
LL b[4002],c[4002],Mx[2]={-1,-1};
int a[2002][2002];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]),b[j-i+n]+=a[i][j],c[i+j]+=a[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1,j1=(i&1);j<=n;++j,j1^=1)
			if(b[j-i+n]+c[i+j]-a[i][j]>Mx[j1])
				Mx[j1]=b[j-i+n]+c[i+j]-a[i][j],x[j1]=i,y[j1]=j;
	printf("%lld\n%d %d %d %d",Mx[0]+Mx[1],x[0],y[0],x[1],y[1]);
	return 0;
}