#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,a[N],b[N];
bool mat[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int p=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		if (mat[i]) continue;
		while (p<=n&&(p<=i||a[p]-a[i]<m||mat[p])) p++;
		b[i]=p;
	}
	int mn=n*3;
	for (int i=1;i<=n/2;i++) mn=std::min(mn,n+i-b[i]),ans=std::max(ans,std::min(mn,i));
	printf("%d\n",ans);
	return 0;
}