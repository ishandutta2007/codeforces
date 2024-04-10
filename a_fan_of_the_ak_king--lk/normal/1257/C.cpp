#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=1000000007;
int n,x,b,t,y,vis[200005],a[200005],ans,i;
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
			scanf("%d",&a[i]);
		ans=1<<30;
		for(i=1;i<=n;++i)
		{
			if(vis[a[i]]!=0)
				ans=min(ans,i-vis[a[i]]+1);
			vis[a[i]]=i;
		}
		for(i=1;i<=n;++i)
			vis[a[i]]=0;
		if(ans<(1<<30))
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
}