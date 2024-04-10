#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
int t,n;
int a[200005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int ans=0;
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		a[n+1]=0;
		for (int i=2;i<n;++i)
			if (a[i]>a[i-1]&&a[i]>a[i+1])
			{
				++ans;
				a[i+1]=max(a[i],a[i+2]);
			}
		cout<<ans<<endl;
		for (int i=1;i<=n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}