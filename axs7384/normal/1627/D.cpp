#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		a[x]=1;
	}
	int ans=0;
	for (int i=1000000;i;--i)
	{
		if (a[i])
			continue;
		int p=0;
		for (int j=i;j<=1000000;j+=i)
			if (a[j])
				p=__gcd(p,j);
		if (i==p)
		{
			a[i]=1;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}