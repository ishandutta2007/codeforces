#include<bits/stdc++.h>
using namespace std;
int n,m,i,f[105][10005],j,k,s,sb,a,b;
int main()
{
	scanf("%d",&n);
	for(i=0;i<=100;++i)
		for(j=1;j<=10000;++j)
			f[i][j]=-100000000;
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&a,&b);
		s+=a;
		sb+=b;
		for(j=i;j>=1;--j)
			for(k=s;k>=a;--k)
				f[j][k]=max(f[j][k],f[j-1][k-a]+b);
	}
	for(i=1;i<=n;++i)
	{
		int ans=0;
		for(j=1;j<=s;++j)
			ans=max(ans,min(j*2,f[i][j]+sb));
		printf("%.2lf ",ans/2.0);
	}
}