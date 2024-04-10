#include<cstdio>
using namespace std;
#define maxn 2005
int n,m,a[maxn],cnt[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]<=m)cnt[a[i]]++;
	}
	int now=1,ans=0,tot=n/m;
	for (int i=1;i<=m;i++)
		if (cnt[i]<tot)
			for (;now<=n;now++)
			{
				if (a[now]<=m){if (cnt[a[now]]>tot){cnt[a[now]]--;a[now]=i;cnt[i]++;ans++;}}
				else {a[now]=i;cnt[i]++;ans++;}
				if (cnt[i]==tot)break;
			}
	printf("%d %d\n",tot,ans);
	for (int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
		if (i==n)putchar('\n');else putchar(' ');
	}
	return 0;
}