#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,arr+n);
	for (int i=0;i<n;i++)
	{
		bool ok=1;
		for (int j=0;j<i;j++)
		ok&=(arr[i]%arr[j]!=0);
		ans+=ok;
	}
	printf("%d",ans);
}