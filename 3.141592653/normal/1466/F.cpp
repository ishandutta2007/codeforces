#include<bits/stdc++.h>
// Basic typedefs 
typedef long long ll;
typedef double db;
typedef unsigned unt;
typedef unsigned long long ull;
// STL function usage
using std::min;
using std::max;
using std::swap;
using std::reverse;
using std::sort;
// STL container usage
using std::vector;
using std::set;
using std::multiset;
using std::map;
using std::deque;
using std::queue;
// Basic pair
struct pii
{
	int x,y;
	pii(){}
	pii(int xx,int yy){x=xx,y=yy;}
};
bool operator<(const pii x,const pii y)
{if(x.x^y.x)return x.x<y.x;return x.y<y.y;}
// Main

int n,m,k[1111111];
int x[1111111][4];
ll v[1111111];
char s[1111111];
pii P[1111111];
int fa[1111111],cs[1111111];
int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
int As[1111111],tt,ts=1;
const int mod=1e9+7;
void exec()
{
	scanf("%d%d",&n,&m);
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		scanf("%d",k+i);
		for(ii=1;ii<=k[i];ii++)
			scanf("%d",x[i]+ii);
		bool _OK=0;
		if(k[i]==1)
		{
			int e=rt(x[i][1]);
			if(!cs[e])_OK=1,cs[e]=1;
		}else
		{
			int e=rt(x[i][1]),f=rt(x[i][2]);
			if(e!=f)
			{
				fa[e]=f;
				if(cs[e]&&cs[f]);
				else
				{
					_OK=1;
					cs[f]|=cs[e];
				}
			}
		}if(_OK)
		{
			ts=(ts<<1)%mod;
			As[++tt]=i;
		}
	}printf("%d %d\n",ts,tt);
	for(register int i=1;i<=tt;i++)
		printf("%d ",As[i]);
	puts("");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Good bye 2020!
Never forget your days as an OIer, 3.141592653.
Always continue and never break...
*/