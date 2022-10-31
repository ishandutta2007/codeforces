#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,t,x,a[N],i,s,u,v;
int main()
{
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&u,&v);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int ans=2100000000;
		for(i=1;i<n;++i)
		{
			if(abs(a[i]-a[i+1])>=2)
				ans=0;
			if(abs(a[i]-a[i+1])==1)
				ans=min({ans,u,v});
			if(abs(a[i]-a[i+1])==0)
				ans=min({ans,u+v,2*v});
		}
		printf("%d\n",ans);
	}
}