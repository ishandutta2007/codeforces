#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int ans=0;
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			x=(!x)+1;
			ans+=x*i*(n-i+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}