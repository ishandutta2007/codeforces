#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int ans=0,x;
		while (n--)
		{
			scanf("%d",&x);
			ans|=x;
		}
		cout<<ans<<endl;
	}
}