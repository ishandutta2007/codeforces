#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=2000005;
int a[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int mx=1,mn=1;
		for (int i=2;i<=n;++i)
		{
			if (a[i]>a[mx])
				mx=i;
			if (a[i]<a[mn])
				mn=i;
		}
		cout<<min(mn,mx)<<' '<<max(mn,mx)<<endl;
	}
	return 0;
}