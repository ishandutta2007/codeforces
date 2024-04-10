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
int a[1111111],c[1111111];
ll v[1111111];
char s[1111111],t[1111111];
pii P[1111111];
int len[1111111],lenb[1111111];
int nxt[222222][26],lst[222222][26];
int prf[222222],suf[222222];
void exec()
{
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<26;ii++)
			lst[i][ii]=lst[i-1][ii];
		lst[i][s[i]-97]=i;
	}
	for(i=n;i;i--)
	{
		for(ii=0;ii<26;ii++)
			nxt[i][ii]=nxt[i+1][ii];
		nxt[i][s[i]-97]=i;
	}
	int maxdet=0;
	suf[m+1]=n+1;
	for(i=1;i<=m;i++)
	{
		prf[i]=nxt[prf[i-1]+1][t[i]-97];
	}
	for(i=m;i;i--)
	{
		suf[i]=lst[suf[i+1]-1][t[i]-97];
	}
	for(i=1;i<m;i++)
	{
		maxdet=max(maxdet,suf[i+1]-prf[i]);
	}
	printf("%d\n",maxdet);
}
int main()
{
	int T=1;
//	scanf("%d",&T);
	while(T--)exec();
}