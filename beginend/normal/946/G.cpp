#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;
const int inf=2000000000;

int n,a[N],f[2][N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=0;i<=n;i++) f[0][i]=f[1][i]=inf;
	f[0][0]=-inf;
	int ls=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		int s1=std::upper_bound(f[1],f[1]+n+1,a[i]-i+1)-f[1];
		ans=std::max(ans,s1);
		f[1][s1]=a[i]-i+1;
		f[1][ls]=std::min(f[1][ls],f[0][ls]);
		ans=std::max(ans,ls);
		ls=std::upper_bound(f[0],f[0]+n+1,a[i]-i)-f[0];
		f[0][ls]=a[i]-i;
	}
	printf("%d",n-ans-1);
	return 0;
}