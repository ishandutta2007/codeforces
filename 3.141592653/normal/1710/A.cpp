// Author: 3.141592653 
// Round: Codeforces R#810 [div.1] 
// Header 
#include<stdio.h>
#include<bits/stdc++.h>

using std::min;
using std::max;
using std::abs;
using std::swap;
using std::sort;
using std::next_permutation;

using std::string;
using std::vector;
using std::queue;
using std::deque;
using std::priority_queue;
using std::set;
using std::map;

typedef long long ll;
typedef double db;
typedef unsigned int unt;
typedef unsigned long long ull;

const int mod=998244353;

class pii
{
public:
	int x,y;
	pii():x(0),y(0){}
	pii(int xx,int yy):x(xx),y(yy){};
	void read(){scanf("%d%d",&x,&y);}
	void debug(){fprintf(stderr,"(%d,%d)\n",x,y);}
};

namespace sol
{
	int a[1<<20];
	bool chk(int l,int c,int k)
	{
		if(l==1)
		{
			for(int i=1;i<=k;i++)
			{
				if(a[i]>=c)return 1;
			}return 0;
		}
		else 
		{
			int sum=0,ol2=1;
			for(int i=1;i<=k;i++)
			{
				if(a[i]>=2*c)
				{
					sum+=a[i]/c;
					if(a[i]/c!=2)ol2=0;
				}
				if(sum>=l)
				{
					if(ol2&&(l&1))continue;
					return 1;
				}
			}return 0;
		}
	} 
	int n,m,k;
	void exec()
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;i++)
			scanf("%d",a+i);
		if(chk(n,m,k)||chk(m,n,k))
			puts("yes");
		else puts("no");
	}
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)sol::exec();
}