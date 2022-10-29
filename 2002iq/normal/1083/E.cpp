#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
#define X first.first
#define Y first.second
pair<pair<int,int>,long long> arr[1000005];
long long dp[1000005];
bool qu=0;
struct line
{
	long long m,b;
	mutable function<const line*()> succ;
	bool operator<(const line& rhs) const
	{
		if (!qu)
		return (m<rhs.m);
		const line* s=succ();
		if (!s)
		return 0;
		return b-s->b<rhs.m*(s->m-m);
	}
};
struct hull:public multiset<line>
{
	bool bad(iterator y)
	{
		auto z=next(y);
		if (y==begin())
		{
			if (z==end())
			return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if (z==end())
		return (y->m==x->m && y->b<=x->b);
		return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
	}
	void add(long long m,long long b)
	{
		auto it=insert({m,b});
		it->succ=[=] { return (next(it)==end())? 0:&*next(it); };
		if (bad(it))
		{
			erase(it);
			return;
		}
		while (next(it)!=end() && bad(next(it)))
		erase(next(it));
		while (it!=begin() && bad(prev(it)))
		erase(prev(it));
	}
	long long eval(long long x)
	{
		qu=1;
		line l=*lower_bound((line){x,0});
		qu=0;
		return l.m*x+l.b;
	}
};
hull h;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d%d%I64d",&arr[i].X,&arr[i].Y,&arr[i].second);
	sort(arr+1,arr+n+1);
	long long ans=0;
	h.add(0,0);
	for (int i=1;i<=n;i++)
	{
		/*for (int j=0;j<i;j++)
		dp[i]=max(dp[i],dp[j]+(arr[i].x-arr[j].x)*arr[i].y);*/
		dp[i]=h.eval(arr[i].Y)+1LL*arr[i].X*arr[i].Y-arr[i].second;
		ans=max(ans,dp[i]);
		h.add(-arr[i].X,dp[i]);
	}
	printf("%I64d",ans);
}