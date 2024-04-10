#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=100005,M=998244353;
int n,m,s[N],s2[N],vis[N*2],t;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	for(ri i=0;i<N*2;++i)
		vis[i]=-100000000;
	while(t--)
	{
		scanf("%d",&n);
		ri i;
		for(i=1;i<=n;++i)
			scanf("%d",&s[i]);
		for(i=n;i>=1;--i)
			scanf("%d",&s2[i]);
		for(i=1;i<=n;++i)
		{
			s[i]=s[i-1]+s[i]*2-3;
			s2[i]=s2[i-1]+s2[i]*2-3;
		}
		for(i=0;i<=n;++i)
			vis[s2[i]+n]=i;
		int ans=0;
		for(i=0;i<=n;++i)
			ans=max(ans,vis[-s[i]+n]+i);
		cout<<2*n-ans<<endl;
		for(i=0;i<=n;++i)
			vis[s2[i]+n]=-100000000;
	}
}