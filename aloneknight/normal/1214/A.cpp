#include<bits/stdc++.h>
using namespace std;
int n,d,e;
int main()
{
	scanf("%d%d%d",&n,&d,&e);int ans=n;
	for(int i=0;i<=n;i+=5)
	{
		int t=n-i*e;
		if(t<0)break;
		ans=min(ans,t%d);
	}
	printf("%d\n",ans);
	return 0;
}