#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=0;i<=n&&i*2<=m;i++)
	{
		int t=n-i,tt=m-i-i;
		ans=max(ans,i+min(t/2,tt));
	}
	printf("%d\n",ans);
	return 0;
}