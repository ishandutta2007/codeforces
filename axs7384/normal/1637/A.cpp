#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		bool b=true;
		for (int i=1;i<n;++i)
			if (a[i]>a[i+1])
				b=false;
		puts(b?"NO":"YES");
	}
	return 0;
}