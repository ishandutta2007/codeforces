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
int a[1111111],c[1111111],loc[1111111];
ll v[1111111];
char s[1111111];
pii P[1111111];
void exec()
{
	scanf("%d",&n);
	register int i,ii;
	for(i=1;i<=n;i++)scanf("%d",a+i),loc[a[i]]=i;
	int curmin=n;
	for(i=n;i;i--)
	{
		for(ii=loc[i];ii<=curmin;ii++)printf("%d ",a[ii]);
		curmin=min(curmin,loc[i]-1);
	}puts("");
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}