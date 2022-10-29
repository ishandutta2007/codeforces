#include <iostream>
using namespace std;
int a[200005],b[200005];
int main()
{
	int n,m,ta,tb,k,ans=0;
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]),a[i]+=ta;
	for (int i=0;i<m;i++)
	scanf("%d",&b[i]);
	if (k>=min(n,m))
	{
		printf("-1");
		return 0;
	}
	for (int i=0;i<min(n,k+1);i++)
	{
		int idx=lower_bound(b,b+m,a[i])-b;
		if (i+m-idx<=k)
		{
			printf("-1");
			return 0;
		}
		ans=max(ans,b[idx+k-i]+tb);
	}
	printf("%d",ans);
}