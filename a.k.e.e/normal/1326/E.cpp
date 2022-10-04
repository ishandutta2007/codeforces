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
const int MAXN=300005;

int n,a[MAXN],b[MAXN];
int Min[MAXN<<2|1],lazy[MAXN<<2|1];
void pushdown(int id)
{
	Min[id<<1]+=lazy[id],lazy[id<<1]+=lazy[id];
	Min[id<<1|1]+=lazy[id],lazy[id<<1|1]+=lazy[id];
	lazy[id]=0;
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr){Min[id]+=c,lazy[id]+=c;return;}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
	Min[id]=min(Min[id<<1],Min[id<<1|1]);
}
int query(int id,int l,int r,int ql,int qr)
{
	if(l==ql && r==qr)return Min[id];
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)return query(id<<1,l,mid,ql,qr);
	if(ql>mid)return query(id<<1|1,mid+1,r,ql,qr);
	return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int x;
	readint(n);
	for(int i=1;i<=n;++i)readint(x),a[x]=i;
	for(int i=1;i<=n;++i)readint(b[i]);
	x=n;
	for(int i=1;i<=n;++i)
	{
		printf("%d ",x);
		modify(1,1,n,1,b[i],1);
		for(;x && query(1,1,n,1,a[x])>0;--x)modify(1,1,n,1,a[x],-1);
	}
	return 0;
}