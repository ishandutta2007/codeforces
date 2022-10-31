#include<bits/stdc++.h>
using namespace std; 
const int N=300005,M=998244353;
const long double PI=3.1415926535897932384626;
int n,p,i,t,x[1005],f[1005],j;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&x[i]);
		for(i=1;i<=100;++i)
			f[i]=0;
		for(i=1;i<=n;++i)
			for(j=i+1;j<=n;++j)
				f[x[j]-x[i]]=1;
		int ans=0;
		for(i=1;i<=100;++i)
			ans+=f[i];
		printf("%d\n",ans);
	}
}