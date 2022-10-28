#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define int long long
int q,sum,cnt,op,x;double ans;
pair<double,int> Q[520233];int h=1,t;
double calc(const pair<double,int>& p)
{
	return p.first+(double)x/p.second;
}
signed main()
{
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&op);
		if(op&1)
		{
			scanf("%lld",&x);sum+=x;++cnt;
			while(h<t&&calc(Q[h])>calc(Q[h+1]))++h;
			if(h<=t)ans=max(ans,x-calc(Q[h]));
			Q[++t]=make_pair((double)sum/(cnt+1),cnt+1);
		}
		else printf("%.10lf\n",ans);
	}
	return 0;
}