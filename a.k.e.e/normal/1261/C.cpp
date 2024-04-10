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
const int MAXN=3000015,INF=0x3f3f3f3f,dir[8][2]={1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};

int n,m;
inline int ei(int x,int y){return (x-1)*m+y;}
char a[MAXN],str[MAXN];
int dis[MAXN],fis[MAXN];
pii q[MAXN];
bool check(int mid)
{
	memset(dis,0x3f,sizeof(dis));
	memset(fis,0x3f,sizeof(fis));
	int front=1,rear=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[ei(i,j)]=='.')
			{
				if(mid)q[++rear]=mp(i,j);
				dis[ei(i,j)]=0;
			}
	while(front<=rear)
	{
		pii p=q[front++];
		for(int t=0;t<8;++t)
		{
			int tx=p.x+dir[t][0],ty=p.y+dir[t][1];
			if(!tx || !ty || tx>n || ty>m || dis[ei(tx,ty)]<INF)continue;
			dis[ei(tx,ty)]=dis[ei(p.x,p.y)]+1;
			if(dis[ei(tx,ty)]<mid)q[++rear]=mp(tx,ty);
		}
	}
/*cerr<<mid<<":"<<endl;
for(int i=1;i<=n;++i)
{
	for(int j=1;j<=m;++j)
		putchar(dis[ei(i,j)]<INF?'.':'X');
	putchar('\n');
}*/
	front=1,rear=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(dis[ei(i,j)]==INF && a[ei(i,j)]=='X')
			{
				if(mid)q[++rear]=mp(i,j);
				fis[ei(i,j)]=0;
			}
	while(front<=rear)
	{
		pii p=q[front++];
		for(int t=0;t<8;++t)
		{
			int tx=p.x+dir[t][0],ty=p.y+dir[t][1];
			if(!tx || !ty || tx>n || ty>m || fis[ei(tx,ty)]<INF)continue;
			fis[ei(tx,ty)]=fis[ei(p.x,p.y)]+1;
			if(fis[ei(tx,ty)]<mid)q[++rear]=mp(tx,ty);
		}
	}
/*cerr<<endl;
for(int i=1;i<=n;++i)
{
	for(int j=1;j<=m;++j)
		putchar(fis[ei(i,j)]==INF?'.':'X');
	putchar('\n');
}*/
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if( (a[ei(i,j)]=='.')!=(fis[ei(i,j)]==INF) )return 0;
	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	n+=2;m+=2;
	for(int j=1;j<=m;++j)a[ei(1,j)]=a[ei(n,j)]='.';
	for(int i=2;i<n;++i)
	{
		a[ei(i,1)]='.';
		scanf("%s",str+1);
		for(int j=2;j<m;++j)
			a[ei(i,j)]=str[j-1];
		a[ei(i,m)]='.';
	}
	int L=1,R=n+m,mid,ans=0;
	while(L<=R)
	{
		mid=(L+R)>>1;
		if(check(mid))L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%d\n",ans);
	check(ans);
	for(int i=2;i<n;++i)
	{
		for(int j=2;j<m;++j)
			putchar(dis[ei(i,j)]==INF?'X':'.');
		putchar('\n');
	}
	return 0;
}