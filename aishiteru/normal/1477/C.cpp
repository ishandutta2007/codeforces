#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long M=3799912185593857ll;
int n,t,i,x[N],y[N],vis[N],las=1,j;
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d %d",&x[i],&y[i]);
	printf("1 ");
	vis[1]=1;
	for(i=2;i<=n;++i)
	{
		long long ans=0;
		int xx=0;
		for(j=1;j<=n;++j)
			if(!vis[j])
				if(1ll*(x[j]-x[las])*(x[j]-x[las])+1ll*(y[j]-y[las])*(y[j]-y[las])>ans)
				{
					ans=1ll*(x[j]-x[las])*(x[j]-x[las])+1ll*(y[j]-y[las])*(y[j]-y[las]);
					xx=j;
				}
		las=xx;
		vis[xx]=1;
		printf("%d ",xx);
	}
}