#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;
const LL inf=(LL)2e18;

int n,now,s[N];
LL a[N],f[65][N],bin[65],b[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) a[i]=a[n]-a[i];
	for (int i=0;i<=60;i++)
		for (int j=0;j<=n;j++)
			f[i][j]=inf;
	f[0][0]=0;
	bin[0]=1;
	for (int i=1;i<=60;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=60;i++)
	{
		for (int j=1;j<=n;j++) s[j]=s[j-1]+((a[j]&bin[i-1])?1:0);
		for (int j=0;j<=n;j++)
		{
			if (f[i-1][j]==inf) continue;
			int was=j-s[j]+s[n]-s[j],cnt=s[j];
			f[i][cnt]=std::min(f[i][cnt],f[i-1][j]+was);
			was=s[j]+(n-j)-(s[n]-s[j]);cnt=j+s[n]-s[j];
			f[i][cnt]=std::min(f[i][cnt],f[i-1][j]+was);
		}
		int k=0;
		for (int j=1;j<=n;j++) if (a[j]&bin[i-1]) b[++k]=a[j];
		for (int j=1;j<=n;j++) if (!(a[j]&bin[i-1])) b[++k]=a[j];
		for (int j=1;j<=n;j++) a[j]=b[j];
	}
	printf("%lld\n",f[60][0]);
	return 0;
}