#include<bits/stdc++.h>
using std::min;
using std::max;

using std::swap;

using std::sort;

using std::vector;
using std::set;
using std::map;
//using std::unordered_map;
// unordered_map is disgusting and not used as default 
using std::multiset;
using std::set;
using std::priority_queue;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef unsigned unt;

struct pii
{
	int x,y;
	pii():x(0),y(0){}
	pii(int x0,int y0):x(x0),y(y0){}
};

namespace sol
{
	int n;
	int p[1<<20],q[1<<20];
	void clear()
	{
		
	}
	const int mod=1e9+7;
	void exec()
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i),q[p[i]]=i;
		int l=1e9,r=-1e9;
		int ans=1;
		for(int i=0;i<n;i++)
		{
			int l0=min(l,q[i]);
			int r0=max(r,q[i]);
			int d=r0-l0;
			if(l0==l&&r0==r)ans=ans*1ll*(d-i+1)%mod;
			l=l0,r=r0;
		}
		printf("%d\n",ans);
	}
}

int main()
{
	int __T=1;
	scanf("%d",&__T);
	while(__T--)sol::exec();
}