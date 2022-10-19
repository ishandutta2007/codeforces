#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int t,n,m,k,q;
int x[N],y[N];
set<int> sx,sy;
const int mod=998244353;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d",&n,&m,&k,&q);
		sx.clear();
		sy.clear();
		for (int i=1;i<=q;++i)
			scanf("%d%d",&x[i],&y[i]);
		int ans=1;
		for (int i=q;i;--i)
		{
			if (sx.size()!=n&&sy.size()!=m&&(!sx.count(x[i])||!sy.count(y[i])))
			{
				ans=(ll)ans*k%mod;
				sx.insert(x[i]);
				sy.insert(y[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}