#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int arr[400005];
map<int,int> cnt;
int main()
{
	int n,b;
	scanf("%d%d",&n,&b);
	b=(b*8)/n;
	if (b>30)
	{
		printf("0");
		return 0;
	}
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=n,r=0,cur=0;
	for (int l=0;l<n;l++)
	{
		while (r<n && cur<=(1<<b))
		{
			if (!cnt[arr[r]])
			cur++;
			cnt[arr[r]]++;
			r++;
		}
		if (cur>(1<<b))
		{
			r--;
			cnt[arr[r]]--;
			cur--;
		}
		ans=min(ans,n-(r-l));
		cnt[arr[l]]--;
		if (!cnt[arr[l]])
		cur--;
	}
	printf("%d",ans);
}