#include <iostream>
#include <algorithm>
using namespace std;
int l[1005],r[1005],ans[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&l[i]);
		ans[i]+=l[i];
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d",&r[i]);
		ans[i]+=r[i];
	}
	int mx=*max_element(ans,ans+n);
	for (int i=0;i<n;i++)
	ans[i]=mx-ans[i]+1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<i;j++)
		l[i]-=(ans[i]<ans[j]);
		for (int j=i+1;j<n;j++)
		r[i]-=(ans[i]<ans[j]);
		if (l[i] || r[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES\n");
	for (int i=0;i<n;i++)
	printf("%d ",ans[i]);
}