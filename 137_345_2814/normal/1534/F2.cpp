#include<cstdio>
#include<algorithm>
using namespace std;
#define N 400500
int n,m,a[N],sl[N],sr[N],vl[N],ti;
char s[N];
int getid(int x,int y){if(x>n||x<1||y>m||y<1)return 0;return x*m-m+y;}
void dfs1(int x,int y)
{
	if(x<1||x>n||y<1||y>m)return;
	if(sl[getid(x,y)])return;
	sl[getid(x,y)]=ti;
	dfs1(x+1,y);
	if(s[getid(x,y-1)]=='#')dfs1(x,y-1);
	if(s[getid(x-1,y)]=='#')dfs1(x-1,y);
	if(s[getid(x,y+1)]=='#')dfs1(x,y+1);
}
void dfs2(int x,int y)
{
	if(x<1||x>n||y<1||y>m)return;
	if(sr[getid(x,y)])return;
	sr[getid(x,y)]=ti;
	dfs2(x+1,y);
	if(s[getid(x,y-1)]=='#')dfs2(x,y-1);
	if(s[getid(x-1,y)]=='#')dfs2(x-1,y);
	if(s[getid(x,y+1)]=='#')dfs2(x,y+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s+(i-1)*m+1);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(ti=1;ti<=m;ti++)for(int j=1;j<=n;j++)if(s[getid(j,ti)]=='#')dfs1(j,ti);
	for(ti=m;ti>=1;ti--)for(int j=1;j<=n;j++)if(s[getid(j,ti)]=='#')dfs2(j,ti);
	for(int i=0;i<=m+1;i++)vl[i]=m+1;
	for(int i=1;i<=m;i++)
	{
		int su=0;
		for(int j=n;j>=1;j--)
		{
			if(s[getid(j,i)]=='#')su++;
			if(su==a[i]&&s[getid(j,i)]=='#')
			{
				int lb=sl[getid(j,i)],rb=sr[getid(j,i)];
				vl[lb-1]=min(vl[lb-1],rb);
			}
		}
	}
	for(int i=m;i>=0;i--)vl[i]=min(vl[i],vl[i+1]);
	int as=0,nw=0;while(nw<m+1)nw=vl[nw],as++;
	printf("%d\n",as-1);
}