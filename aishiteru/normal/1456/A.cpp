#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,k,x,y,i,p;
long long f[N];
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&p,&k);
		scanf("%s",c+1);
		scanf("%d %d",&x,&y);
		for(i=n+1;i<=n+k+1;++i)
			f[i]=0;
		for(i=n;i>=1;--i)
			f[i]=f[i+k]+(c[i]=='0')*x;
		long long ans=10000000000000000ll;
		for(i=0;i<=n-p;++i)
			ans=min(ans,1ll*i*y+f[i+p]);
		printf("%lld\n",ans);
	}
}