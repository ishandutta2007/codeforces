#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=400005;

int n,a[MAXN],m;
pii c[MAXN];
int res[MAXN];
void solve(int x,int y)
{
	for(int i=1;i<=m;++i)chkmin(c[i].x,x);
	sort(c+1,c+m+1);
	int tx=1,ty=1;
	for(int i=m;i;--i)
	{
		while(c[i].x--)
		{
			res[(tx-1)*y+ty]=c[i].y;
			++tx,++ty;
			if(tx>x)tx-=x,ty-=x-1;
			if(ty<=0)ty+=y;
			if(ty>y)ty-=y;
		}
	}
	for(int i=1;i<=x;++i)
	{
		for(int j=1;j<=y;++j)
			printf("%d ",res[(i-1)*y+j]);
		putchar('\n');
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	sort(a+1,a+n+1);
	int cur=1;
	for(int i=2;i<=n+1;++i)
		if(a[i]!=a[i-1])c[++m]=mp(cur,a[i-1]),cur=1;
		else ++cur;
	int best=0,rx,ry;
	for(int x=1;x*x<=n;++x)
	{
		int sum=0;
		for(int i=1;i<=m;++i)
			sum+=min(x,c[i].x);
		int y=sum/x;
		if(y>=x && x*y>best)best=x*y,rx=x,ry=y;
	}
	printf("%d\n",best);
	printf("%d %d\n",rx,ry);
	solve(rx,ry);
	return 0;
}