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

int n,m,k;
int a[1111111];
ll v[1111111];
char s[1111111];
pii P[1111111];
int d[1111111];
std::priority_queue<int>Q;
void exec()
{
	scanf("%d",&n);
	register int i;
	ll S=0;
	for(i=1;i<=n;i++)
		scanf("%lld",v+i),S+=v[i],d[i]=0;
	for(i=2;i<=n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++,d[v]++;
	}for(i=1;i<=n;i++)
	{
		for(int ii=2;ii<=d[i];ii++)
		{
			Q.push(v[i]);
		}
	}printf("%lld ",S);
	for(i=2;i<n;i++)
	{
		int t=Q.top();Q.pop();
		S+=t;
		printf("%lld ",S);
	}puts("");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Good bye 2020!
Never forget your days as an OIer, 3.141592653.
Always continue and never break...
*/