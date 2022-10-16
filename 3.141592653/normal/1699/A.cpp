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
	int n,m;
	void clear()
	{
		
	}
	const int mod=1e9+7;
	void exec()
	{
		scanf("%d",&n);
		if(n&1)puts("-1");
		else printf("%d %d %d\n",0,0,n/2);
	}
}

int main()
{
	int __T=1;
	scanf("%d",&__T);
	while(__T--)sol::exec();
}