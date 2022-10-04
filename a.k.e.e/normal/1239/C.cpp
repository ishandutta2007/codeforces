#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(register int i=(x);i<=(y);++i)
#define try(i,x,y) for(register int i=(x);i>=(y);--i)
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005;
const ll INF=1ll<<60;

int n;
ll res[MAXN],p,a[MAXN];
int f[MAXN<<2|1];
void build(int id,int l,int r)
{
	if(l==r){f[id]=l;return;}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	if(a[f[id<<1]]<=a[f[id<<1|1]])f[id]=f[id<<1];
	else f[id]=f[id<<1|1];
}
void modify(int id,int l,int r,int x,ll c)
{
	if(l==r){a[l]=c;return;}
	int mid=(l+r)>>1;
	if(x<=mid)modify(id<<1,l,mid,x,c);
	else modify(id<<1|1,mid+1,r,x,c);
	if(a[f[id<<1]]<=a[f[id<<1|1]])f[id]=f[id<<1];
	else f[id]=f[id<<1|1];
}
int qmin(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return f[id];
	int mid=(l+r)>>1;
	if(qr<=mid)return qmin(id<<1,l,mid,ql,qr);
	if(ql>mid)return qmin(id<<1|1,mid+1,r,ql,qr);
	int lx=qmin(id<<1,l,mid,ql,mid),rx=qmin(id<<1|1,mid+1,r,mid+1,qr);
	return a[lx]<=a[rx]?lx:rx;
}
int qleft(int id,int l,int r,int ql,int qr,ll lim)
{
	if(a[f[id]]>lim)return n+1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(qr<=mid)return qleft(id<<1,l,mid,ql,qr,lim);
	if(ql>mid)return qleft(id<<1|1,mid+1,r,ql,qr,lim);
	int t=qleft(id<<1,l,mid,ql,mid,lim);
	return t<=n?t:qleft(id<<1|1,mid+1,r,mid+1,qr,lim);
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	readint(n);readint(p);
	int u=0;
	enum(i,1,n)
	{
		readint(a[i]);
		if(!u || a[i]<a[u])u=i;
	}
	build(1,1,n);
	ll cur=0;
	enum(i,1,n)
	{
		chkmax(cur,a[u]);cur+=p;res[u]=cur;
		modify(1,1,n,u,INF);
		int x=qmin(1,1,n,1,u);
		if(a[x]<=cur){u=x;continue;}
		x=qleft(1,1,n,u,n,cur);
		if(x<=n){u=x;continue;}
		u=qmin(1,1,n,1,n);
	}
	enum(i,1,n)printf("%I64d ",res[i]);
    return 0;
}