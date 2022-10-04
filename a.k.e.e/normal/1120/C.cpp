#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <unordered_map>

using namespace std;

typedef unsigned long long ull;
#define hash xtqakioi
const int MAXN=5005,MAXK=13,BASE=31;

int n,a,b;
char s[MAXN];
struct Suffix
{
	int x,y,id;
	Suffix(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	inline bool operator ==(const Suffix &b)const {return x==b.x && y==b.y;}
}wa[MAXN],wb[MAXN];
int wcnt[MAXN],sa[MAXN],rk[MAXN],height[MAXN];
void buildsa()
{
	Suffix *a=wa,*b=wb;
	int tot=0,k=1;
	memset(wcnt,0,sizeof(wcnt));
	for(int i=1;i<=n;i++)wcnt[s[i]-'a']++;
	for(int i=1;i<26;i++)wcnt[i]+=wcnt[i-1];
	for(int i=n;i>0;i--)sa[wcnt[s[i]-'a']--]=i;
	for(int i=1;i<=n;i++)
		if(s[sa[i]]==s[sa[i-1]])rk[sa[i]]=tot;
		else rk[sa[i]]=++tot;
	while(k<=n)
	{
		for(int i=1;i<=n;i++)a[i]=Suffix(rk[i],i+k>n?0:rk[i+k],i);
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[a[i].y]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)b[wcnt[a[i].y]--]=a[i];
		memset(wcnt,0,sizeof(wcnt));
		for(int i=1;i<=n;i++)wcnt[b[i].x]++;
		for(int i=1;i<=n;i++)wcnt[i]+=wcnt[i-1];
		for(int i=n;i>0;i--)a[wcnt[b[i].x]--]=b[i];
		tot=0;
		for(int i=1;i<=n;i++)
			if(a[i]==a[i-1])rk[a[i].id]=tot;
			else rk[a[i].id]=++tot;
		if(tot==n)break;
		k<<=1;
	}
	for(int i=1;i<=n;i++)sa[rk[i]]=i;
	k=0;
	for(int i=1;i<=n;i++)
	{
		if(k)k--;
		for(int t=sa[rk[i]-1];i+k<=n && t+k<=n && s[i+k]==s[t+k];k++);
		height[rk[i]]=k;
	}
}
int _log2[MAXN],rmq[MAXN][MAXK];
void getst()
{
	_log2[1]=0;
	for(int i=2;i<=n;i++)
		_log2[i]=_log2[i-1]+((1<<(_log2[i-1]+1))==i);
	for(int i=1;i<=n;i++)rmq[i][0]=height[i];
	for(int j=1;j<MAXK;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}
inline int lcp(int x,int y)
{
	x=rk[x];y=rk[y];
	if(x>y)swap(x,y);++x;
	int t=_log2[y-x+1];
	return min(rmq[x][t],rmq[y-(1<<t)+1][t]);
}

int ct[MAXN];
bool p[MAXN][MAXN];
int f[MAXN];

int main()
{
	cin>>n>>a>>b>>(s+1);
	buildsa();
	getst();
	for(int i=1;i<=n;i++)
	{
		memset(ct,0,sizeof(ct));
		for(int j=1;j<i;j++)
		{
			int t=min(i-j,lcp(i,j));
			++ct[i];--ct[i+t];
		}
		for(int j=i;j<=n;j++)
		{
			ct[j]+=ct[j-1];
			if(ct[j])p[i][j]=1;
		}
	}
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		f[i]=1<<30;
		for(int j=1;j<=i;j++)
			if(p[j][i])f[i]=min(f[i],f[j-1]+b);
		f[i]=min(f[i],f[i-1]+a);
	}
	printf("%d\n",f[n]);
	return 0;
}