#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int x=123,N=1e5+5;
const unsigned long long mod=1e9+7;
struct T{unsigned long long HASH;int lazy;}t[N<<2];
unsigned long long xp[N],tmp[10][N],lst;
int n,m,k,T;
char s[N];
inline unsigned long long mul(unsigned long long a,unsigned long long b,unsigned long long p)
{
	return a*b%p;
	unsigned long long d=(unsigned long long)floor(a*(long double)b/p+0.5);
	unsigned long long ret=(a*b-d*p)%p;
	if(ret<0)ret+=p;
	return ret;
}
inline void pushup(int u,int l,int r)
{
	int mid=(l+r)>>1;
	t[u].HASH=(mul(t[u<<1].HASH,xp[r-mid],mod)+t[u<<1|1].HASH)%mod;
}
void build(int u,int l,int r)
{
	if(l==r){t[u].HASH=s[l]-'0'+1;return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);build(u<<1|1,mid+1,r);
	pushup(u,l,r);
}
inline void pushdown(int u,int l,int r)
{
	int mid=(l+r)>>1;
	if(t[u].lazy)
	{
		t[u<<1].HASH=tmp[t[u].lazy-1][mid-l+1];
		t[u<<1|1].HASH=tmp[t[u].lazy-1][r-mid];
		t[u<<1].lazy=t[u].lazy;t[u<<1|1].lazy=t[u].lazy;
		t[u].lazy=0;
	}
}
void modify(int u,int l,int r,int left,int right,int v)
{
	if(left<=l&&right>=r){t[u].lazy=v+1;t[u].HASH=tmp[v][r-l+1];return;}
	pushdown(u,l,r);int mid=(l+r)>>1;
	if(left<=mid)modify(u<<1,l,mid,left,right,v);
	if(right>mid)modify(u<<1|1,mid+1,r,left,right,v);
	pushup(u,l,r);
}
void query(int u,int l,int r,int left,int right)
{
	if(left<=l&&right>=r){lst=(mul(lst,xp[r-l+1],mod)+t[u].HASH)%mod;return;}
	pushdown(u,l,r);int mid=(l+r)>>1;
	if(left<=mid)query(u<<1,l,mid,left,right);
	if(right>mid)query(u<<1|1,mid+1,r,left,right);
}
int main()
{
	read(n),read(m),read(k);T=m+k;
	xp[0]=1;for(int i=1;i<=n;i++)xp[i]=xp[i-1]*x%mod;
	for(int i=0;i<10;i++)
		for(int j=1;j<=n;j++)tmp[i][j]=(tmp[i][j-1]+xp[j-1]*(i+1))%mod;
	scanf("%s",s+1);
	build(1,1,n);
	while(T--)
	{
		int kase,l,r,c,d;
		read(kase);
		if(kase==1)
		{
			read(l),read(r),read(c);
			modify(1,1,n,l,r,c);
		}
		if(kase==2)
		{
			read(l),read(r),read(d);
			if(d>=r-l+1){puts("YES");continue;}
			lst=0;query(1,1,n,l,r-d);unsigned long long tmp0=lst;
			lst=0;query(1,1,n,l+d,r);unsigned long long tmp1=lst;
			if(tmp0==tmp1)puts("YES");else puts("NO");
		}
	}
	return 0;
}