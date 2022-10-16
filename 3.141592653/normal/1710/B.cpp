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
	int n,m,x[1<<20],y[1<<20];
	pii p[1<<20];
	void exec()
	{
		scanf("%d%d",&n,&m);
		int tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",x+i,y+i);
			p[++tot]=pii(x[i]-y[i],1);
			p[++tot]=pii(x[i],-2);
			p[++tot]=pii(x[i]+y[i],1);
		}
		std::sort(p+1,p+tot+1,[&](const pii&x,const pii&y)
		{
			return x.x<y.x;
		});
		ll posd=-1e18,sy=0;
		ll sum=0;
		int t2=0;
		ll minxpy=-1e18,maxxdy=1e18;
		for(int i=1;i<=tot;i++)
		{
			//p[i].debug();
			sum+=(p[i].x-posd)*1ll*sy;
			sy+=p[i].y;
			posd=p[i].x;
			if(sum>m)
			{
				minxpy=max(minxpy,p[i].x+(sum-m));
				maxxdy=min(maxxdy,p[i].x-(sum-m));
			}
			//printf("%d %d\n",p[i].x,sum);
		}
		//printf("? %lld %lld\n",minxpy,maxxdy);
		for(int i=1;i<=n;i++)
		{
			if(x[i]-y[i]<=maxxdy && x[i]+y[i]>=minxpy)
				putchar('1');
			else putchar('0');
		}
		puts("");
	}
}

int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)sol::exec();
}