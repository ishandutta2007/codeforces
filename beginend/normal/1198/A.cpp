#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=400005;

int n,m,a[N],b[N],c[N],s[N],lg[N*10];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int tmp=0;
	for (int i=1;i<=n;i++)
		if (!tmp||a[i]!=b[tmp]) b[++tmp]=a[i],c[tmp]=1;
		else c[tmp]++;
	lg[1]=0;
	int j=1;
	for (int i=0;j<=n*2;i++,j<<=1) lg[j]=i;
	for (int i=j-1;i>1;i--) if (!lg[i]) lg[i]=lg[i+1];
	int L=n;n=tmp;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+c[i];
	int ans=L;
	for (int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (lg[mid-i+1]*L<=m*8) l=mid+1;
			else r=mid-1;
		}
		ans=std::min(ans,s[i-1]+s[n]-s[l-1]);
	}
	printf("%d\n",ans);
	return 0;
}